/*
 * LambdaDemo.cpp
 *
 *  Created on: 22 сент. 2017 г.
 *      Author: Паша
 */
#include "pch.h"
#include <functional>
#include <list>

class Func
{
	int value;
public:
	Func(int v) : value(v) {}
	int operator()() {return value;}
};

TEST(Module4,FunctionalObject)
{
	Func x(10);
	ASSERT_EQ(x(),10);
}
//-------------------------------------------------------------------------------------------------
TEST(Module4,SimpleLambda)
{
	int value=5;
	auto f1 = [&](int k) { value = k; return k + 2; };
	ASSERT_EQ(f1(2),4);
	ASSERT_EQ(value,2);

	auto f2 = [=](int k) { return k-2+value;};
	ASSERT_EQ(f2(4),4);
}
//-------------------------------------------------------------------------------------------------
class TestLambda
{
	int value;
public:
	TestLambda(int v) : value(v) {}
    std::function<int()> GetLambda();
};

std::function<int()> TestLambda::GetLambda()
{
	return [this]() { return value; };
}

TEST(Module4,LambdaCaptureProperties)
{
	TestLambda a(2),b(3);
	auto f1 = a.GetLambda();
	auto f2 = b.GetLambda();
	ASSERT_EQ(f1(),2);
	ASSERT_EQ(f2(),3);
}
//---------------------------------------
class TestAuto
{
public:
	int k;
	TestAuto(int a): k(a) {}
	TestAuto operator+(int v) {return TestAuto(k + v);}
};
TEST(Module4,LambdaWithAuto)
{
	auto f = [] (auto x) { return x+2;};
	int actualInt = f(2);
	ASSERT_EQ(actualInt,4);
	TestAuto actualTest = f(TestAuto(3));
	ASSERT_EQ(actualTest.k,5);
}

int sum_p(std::list<int> source, std::function<bool(int)> predicate)
{
	int result = 0;
	for (auto c : source)
	{
		if (predicate(c))
			result += c;
	}
	return result;
}
bool Predicate(int c)
{
	return c % 2 == 0;
}
TEST(Module4, UseSimpleFunctionAsPredicate)
{
	std::list source{ 1,2,3,4,5,6 };
	int actual = sum_p(source, Predicate);
	ASSERT_EQ(12, actual);
}
TEST(Module4, UseLambdaAsPredicate1)
{
	std::list source{ 1,2,3,4,5,6 };
	int actual = sum_p(source, [](auto c) { return c > 4; });
	ASSERT_EQ(11, actual);
}

TEST(Module4, UseLambdaAsPredicate2)
{
	std::list source{ 1,2,3,4,5,6 };
	int actual = sum_p(source, [](auto c) { return c % 2 == 0; });
	ASSERT_EQ(12, actual);
}