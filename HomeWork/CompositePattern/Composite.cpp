#include "pch.h"
#include "Composite.h"
#include <sstream>
#include <algorithm>
/*
---------Component defenitions---------
*/

int Component::id_setter = 0;

Component::Component()
    : dataName{ "" },
    data{ "" },
    parentPtr{},
    isLastComponent{ true },
    id{ id_setter++ } {}

Component::~Component() {}

Component::Component(const Component& other) : Component()
{
    parentPtr = other.parentPtr;
    dataName = other.dataName;
    data = other.data;
}

Component::Component(std::string dataName, std::string data)
    : dataName{ dataName }, data{ data }, isLastComponent{ true }, id{ id_setter++ } 
{
    parentPtr = std::weak_ptr<Component>();
}

bool Component::operator==(const Component& other)
{
    return other.data == data;
}

/*
---------Leaf defenitions---------
*/

Leaf::Leaf() : Component() {}

Leaf::Leaf(const Leaf& other) : Component(other) {}

Leaf::Leaf(std::string dataName, std::string data)
    : Component(dataName, data)
{
}

bool Leaf::operator==(const Leaf& other) { return other.data == data; }

std::string Leaf::str(int indent) const
{
    std::ostringstream oss;
    std::string i(indent_size * indent, ' ');
    if (!dataName.empty())
    {
        oss << i << "\"" << dataName << "\":";
    }
    else
    {
        oss << i << "\""
            << "..."
            << "\":";
    }
    if (data.size() > 0)
    {
        oss << " \"" << data << "\"";
    }
    else
    {
        oss << " \"\"";
    }
    if (!isLastComponent)
    {
        oss << ",";
    }
    return oss.str();
}

/*
---------Composite defenitions---------
*/

void Composite::setPreviousNotLast()
{
    if (auto size = components.size(); size >= 1)
    {
        auto prev_last = std::next(components.begin(), size - 1);
        (*prev_last)->isLastComponent = false;
    }
}

Composite::Composite() : Component() {}

Composite::Composite(const Composite& other) : Component(other) {}

Composite::Composite(std::string dataName) : Component(dataName, "") {}

bool Composite::operator==(const Composite& other)
{
    return other.data == data;
}

std::string Composite::str(int indent) const
{
    std::ostringstream oss;

    std::string i(indent_size * indent, ' ');

    // composite begin
    if (dataName.empty())
    {
        oss << i << "{" << std::endl;
    }
    else
    {
        oss << i << "\"" << dataName << "\":"
            << " [" << std::endl;
    }

    // composite body
    if (components.size() > 0)
    {
        for (const auto& element : components)
        {
            oss << element->str(indent + 1) << std::endl;
        }
    }
    else
    {
        oss << std::endl;
    }

    // composite end
    if (dataName.empty())
    {
        oss << i << "}";
    }
    else
    {
        oss << i << "]";
    }
    if (!isLastComponent)
    {
        oss << ",";
    }
    return oss.str();
}

void Composite::add(sptr_Component component)
{
    component->isLastComponent = true;
    component->parentPtr = shared_from_this();

    setPreviousNotLast();
    components.push_back(component);
}

void Composite::remove(sptr_Component component)
{
    int id = component->id;
    components.erase(std::remove_if(components.begin(), components.end(),
        [&id](sptr_Component const& pi)
        {
            return (pi->id == id);
        }),
        components.end());
}

sptr_Component Composite::getChild()
{
    sptr_Composite childes = NEW_COMPOSITE("childes_" + dataName);
    std::for_each(components.begin(), components.end(),
        [this, &childes](sptr_Component component)
        {
            if (component->parentPtr.lock() == shared_from_this())
            {
                childes->add(component);
            }
        });

    return childes;
}

/*
---------SharedFactory defenitions---------
*/

sptr_Leaf SharedFactory::newLeaf(std::string dataName, std::string data)
{
    return std::make_shared<Leaf>(dataName, data);
}

sptr_Composite SharedFactory::newComposite(std::string dataName)
{
    return std::make_shared<Composite>(dataName);
}