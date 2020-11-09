#include "pch.h"
#include "constrexpr-if.h"


TEST(Module10, ConstIfExprInt) {
	int actual = Addable<int>{1}.Add(2);
	ASSERT_EQ(3, actual);
}

TEST(Module10, ConstIfExprVector)
{
	std::vector<int> source{ 1, 2, 3 };
	std::vector<int> expected{ 11, 12, 13};
	auto actual = Addable<std::vector<int>>{source}.Add(10);
	ASSERT_EQ(expected, actual);
	
}