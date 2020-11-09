#include "pch.h"
#include <vector>

struct employee
{
	unsigned int id;
	std::string name;
	std::string role;
};

std::pair<int, int> divide_reminder(int dividend, int divisor)
{
	return std::make_pair(dividend / divisor, dividend % divisor);
}


auto get_tuple(const employee& emp)
{
	return std::make_tuple(emp.id, emp.name, emp.role);
}

TEST(Module2, NotStructureBinding)
{
	std::pair<int, int> result = divide_reminder(5, 2);
	ASSERT_EQ(result.first, 2);
	ASSERT_EQ(result.second, 1);
}

TEST(Module2, StructureBindingForPair)
{
	auto [r1, r2] = divide_reminder(5, 2);
	ASSERT_EQ(r1, 2);
	ASSERT_EQ(r2, 1);
}

TEST(Module2, StructureBindingForTuple)
{
	employee emp;
	emp.id = 1u;
	emp.name = "name";
	emp.role = "role";
	auto [r1, r2, r3] = get_tuple(emp);
	ASSERT_EQ(r1, 1u);
	ASSERT_EQ(r2, "name");
	ASSERT_EQ(r3, "role");
}