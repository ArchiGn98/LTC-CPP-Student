/*
 * IncrementDecrement.cpp
 *
 *  Created on: 18 сент. 2017 г.
 *      Author: Паша
 */

#include "pch.h"
#include <limits>
using namespace std;

constexpr int inc(const int a)
{
	return a+1;
}
TEST(Module3,ContExprDemo)
{
	ASSERT_EQ(inc(3),4);
}

TEST(Module3,ConstExprDemoWithArray)
{
	struct A
	{
		constexpr A(bool b) : n(b?5:10) {};
		size_t n;
	};
	int a[A(true).n];
	int b[A(false).n];
	ASSERT_EQ(sizeof(a)/sizeof(int),5);
	ASSERT_EQ(sizeof(b)/sizeof(int),10);
}

