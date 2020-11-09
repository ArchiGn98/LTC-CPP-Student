#include "pch.h"
#include "FooBar.h"

extern std::vector<int> BarArgs;

TEST(HW5, PrintfArgs1)
{
    BarArgs.clear();

    Bar1 b1(1);

    Printf(b1);

    ASSERT_EQ(BarArgs[0], b1.getX());
}

TEST(HW5, PrintfArgs2)
{
    BarArgs.clear();

    Bar1 b1(1);
    Bar2 b2(2, 3);

    Printf(b1, b2);

    ASSERT_EQ(BarArgs[0], b1.getX());
    ASSERT_EQ(BarArgs[1], b2.getX());
    ASSERT_EQ(BarArgs[2], b2.getY());
}

TEST(HW5, PrintfArgs4)
{
    BarArgs.clear();

    Bar1 b1(1);
    Bar1 b2(2);

    Bar2 b3(3, 4);
    Bar2 b4(5, 6);

    Printf(b1, b2, b3, b4);

    ASSERT_EQ(BarArgs[0], b1.getX());
    ASSERT_EQ(BarArgs[1], b2.getX());
    ASSERT_EQ(BarArgs[2], b3.getX());
    ASSERT_EQ(BarArgs[3], b3.getY());
    ASSERT_EQ(BarArgs[4], b4.getX());
    ASSERT_EQ(BarArgs[5], b4.getY());
}