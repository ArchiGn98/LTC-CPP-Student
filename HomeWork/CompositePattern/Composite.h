#pragma once

#include <memory>

#include <vector>

#include <string>

class Component;
class Leaf;
class Composite;

using sptr_Component = typename std::shared_ptr<Component>;
using sptr_Leaf = typename std::shared_ptr<Leaf>;
using sptr_Composite = typename std::shared_ptr<Composite>;

class Component
{
public:
    std::string dataName, data;
    const size_t indent_size = 4;
    std::weak_ptr<Component> parentPtr;
    bool isLastComponent;
    int id;
    static int id_setter;

    Component();

    virtual ~Component();

    Component(const Component& other);

    Component(std::string dataName, std::string data);

    bool operator==(const Component& other);

    Component& operator=(const Component& other) = delete;
    Component& operator=(const Component&& other) = delete;

    virtual std::string str(int indent = 0) const = 0;
};

// enable_shared_from_this defines shared_from_this() method
// using it it is possible to create shared_ptr from this class
class Leaf : public Component, 
    public std::enable_shared_from_this<Leaf>
{
public:
    Leaf();

    Leaf(const Leaf& other);

    Leaf(std::string dataName, std::string data);

    bool operator==(const Leaf& other);

    Leaf& operator=(const Leaf& other) = delete;
    Leaf& operator=(const Leaf&& other) = delete;

    std::string str(int indent = 0) const override;
};

// enable_shared_from_this defines shared_from_this() method
// using it it is possible to create shared_ptr from this class
class Composite : public Component,
    public std::enable_shared_from_this<Composite>
{
    std::vector<sptr_Component> components;

    void setPreviousNotLast();

public:
    Composite();

    Composite(const Composite& other);

    Composite(std::string dataName);

    bool operator==(const Composite& other);

    Composite& operator=(const Composite& other) = delete;
    Composite& operator=(const Composite&& other) = delete;

    std::string str(int indent = 0) const override;

    void add(sptr_Component component);

    void remove(sptr_Component component);

    sptr_Component getChild();
};

class SharedFactory
{
public:
    static sptr_Leaf newLeaf(std::string dataName, std::string data);

    static sptr_Composite newComposite(std::string dataName = "");
};

#define NEW_LEAF SharedFactory::newLeaf
#define NEW_COMPOSITE SharedFactory::newComposite