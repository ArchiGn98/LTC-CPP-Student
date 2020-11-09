#include "pch.h"
#include <list>

class Foo
{
	int id;
	static int countCopies;
public:
	Foo(int id) : id{id} {}
	Foo(Foo& other) { countCopies++; }
	inline static int& getCountCopies() { return countCopies; }
};




int Foo::countCopies = 0;

TEST(HW2, RangeBasedForObject)
{
	Foo::getCountCopies() = 0;
	std::list<Foo> foos;
	foos.push_back(Foo(1));
	foos.push_back(Foo(2));
	foos.push_back(Foo(3));
	ASSERT_EQ(Foo::getCountCopies(), 3);

	for(auto copy : foos){}
	ASSERT_EQ(Foo::getCountCopies(), 6);
}

TEST(HW2, RangeBasedForReference)
{
	Foo::getCountCopies() = 0;
	std::list<Foo> foos;
	foos.push_back(Foo(1));
	foos.push_back(Foo(2));
	foos.push_back(Foo(3));
	ASSERT_EQ(Foo::getCountCopies(), 3);

	for (auto& ref : foos) {}
	ASSERT_EQ(Foo::getCountCopies(), 3);

}