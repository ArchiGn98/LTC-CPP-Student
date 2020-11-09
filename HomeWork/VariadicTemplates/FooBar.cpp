#include "pch.h"
#include "FooBar.h"

std::vector<int> BarArgs;

Bar1::Bar1(int x) : x{ x } {}

void Bar1::Printf()
{
    std::cout << x << std::endl;
    BarArgs.push_back(x);
}

Bar1::~Bar1() {}

Bar2::Bar2(int x, int y) : x{ x }, y{ y } {}

void Bar2::Printf()
{
    std::cout << x << " " << y << std::endl;
    BarArgs.push_back(x);
    BarArgs.push_back(y);
}

Bar2::~Bar2() {}