/*
 * VariableDeclare.cpp
 *
 *  Created on: 19 сент. 2017 г.
 *      Author: Паша
 */

#include "pch.h"

int global = 2;
int& getGlobal()
{
  return global;
}

TEST(Module2,AutoVsDecltype)
{
	decltype(getGlobal()) a = getGlobal();
	auto b = getGlobal(); // type deducing like in templates (int)
	a = 3;
	ASSERT_EQ(global,3);
	ASSERT_EQ(a,3);
	ASSERT_EQ(b,2);
}

TEST(Module2,DecltypeWithAuto)
{
	global = 2;
	decltype(auto) a = getGlobal();
	a = 3;
	ASSERT_EQ(global,3);
	ASSERT_EQ(a,3);
}

