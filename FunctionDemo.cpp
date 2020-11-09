#include "pch.h"

auto GetA(int a) -> decltype(a+3.0)
		{
	       return a;
		}

TEST(Module4,FunctionTrailingReturn)
{
	ASSERT_EQ(sizeof(GetA(2)),8);
}
