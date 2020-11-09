#include "pch.h"
#include "PredicateIterator.h"

#include <vector>
#include <array>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
TEST(HW2, PredicateIteratorRangeBasedForVector)
{
	std::vector<int> input{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> expected{ 2, 4, 6, 8, 10 };
	std::vector<int> result;
	PredicateIterator pIt(input.begin(), input.end(), [](int val) { return val % 2 == 0; });

	for (auto val : pIt)
	{
		result.push_back(val);
	}

	EXPECT_EQ(result, expected);
}

TEST(HW2, PredicateIteratorRangeBasedForArray)
{
	std::array<int, 10> input{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> expected{ 2, 4, 6, 8, 10 };
	std::vector<int> result;
	PredicateIterator pIt(input.begin(), input.end(), [](int val) { return val % 2 == 0; });

	for (auto val : pIt)
	{
		result.push_back(val);
	}

	EXPECT_EQ(result, expected);
}

TEST(HW2, PredicateIteratorRangeBasedForList)
{
	std::list<int> input{ 1,2,3,4,5,6,7,8,9,10 };
	std::list<int> expected{ 2, 4, 6, 8, 10 };
	std::list<int> result;
	PredicateIterator pIt(input.begin(), input.end(), [](int val) { return val % 2 == 0; });

	for (auto val : pIt)
	{
		result.push_back(val);
	}

	EXPECT_EQ(result, expected);
}

TEST(HW2, PredicateIteratorRangeBasedForSet)
{
	std::set<int> input{ 1,2,3,4,5,6,7,8,9,10 };
	std::set<int> expected{ 2, 4, 6, 8, 10 };
	std::set<int> result;
	PredicateIterator pIt(input.begin(), input.end(), [](int val) { return val % 2 == 0; });

	for (auto val : pIt)
	{
		result.insert(val);
	}

	EXPECT_EQ(result, expected);
}

TEST(HW2, PredicateIteratorRangeBasedForUnorderedSet)
{
	std::unordered_set<int> input{ 1,2,3,4,5,6,7,8,9,10 };
	std::unordered_set<int> expected{ 2, 4, 6, 8, 10 };
	std::unordered_set<int> result;
	PredicateIterator pIt(input.begin(), input.end(), [](int val) { return val % 2 == 0; });

	for (auto val : pIt)
	{
		result.insert(val);
	}

	EXPECT_EQ(result, expected);
}

TEST(HW2, PredicateIteratorRangeBasedForMap)
{
	std::map<int, int> input
	{ 
		{1,11},
		{2,20},
		{3,31},
		{4,40},
		{5,51},
		{6,60}
	};
	std::vector<int> expected{ 20, 40, 60 };
	std::vector<int> result;
	PredicateIterator pIt(input.begin(), input.end(), [](std::pair<int, int> val) { return val.second % 2 == 0; });

	for (auto val : pIt)
	{
		result.push_back(val.second);
	}

	EXPECT_EQ(result, expected);
}

TEST(HW2, PredicateIteratorRangeBasedForUnorderedMap)
{
	std::unordered_map<int, int> input
	{
		{1,11},
		{2,20},
		{3,31},
		{4,40},
		{5,51},
		{6,60}
	};
	std::vector<int> expected{ 20, 40, 60 };
	std::vector<int> result;
	PredicateIterator pIt(input.begin(), input.end(), [](std::pair<int, int> val) { return val.second % 2 == 0; });

	for (auto val : pIt)
	{
		result.push_back(val.second);
	}

	EXPECT_EQ(result, expected);
}

TEST(HW2, PredicateIteratorAllNotPredicates)
{
	std::vector<int> input{ 1, 3, 5, 7 };
	std::vector<int> expected;
	std::vector<int> result;
	PredicateIterator pIt(input.begin(), input.end(), [](int val) { return val % 2 == 0; });

	for (auto val : pIt)
	{
		result.push_back(val);
	}

	EXPECT_EQ(result, expected);
}