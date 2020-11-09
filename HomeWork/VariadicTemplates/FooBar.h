#pragma once
#include "Printf.h"
#include <iostream>
#include <sstream>
#include <vector>

class Bar1 : public Printable
{
    int x;

public:
    Bar1(int x = 5);
    void Printf() override;
    virtual ~Bar1();
    inline int getX() { return x; }
};

class Bar2 : public Printable
{
    int x, y;

public:
    Bar2(int x = 5, int y = 10);
    void Printf() override;
    virtual ~Bar2();
    inline int getX() { return x; }
    inline int getY() { return y; }
};