#include "pch.h"
#include <memory>
#include <utility>
#include "Foo.h"

	int  Make_it1(std::unique_ptr <Pointers::Foo>)
	{
		return 1;
	}
	int  Make_it2(std::unique_ptr<Pointers::Foo>&)
	{
		return 1;
	}

using namespace Pointers;

TEST(Module6, UniquePtr)
{
	std::unique_ptr<Foo> pt1 = std::make_unique<Foo>();
	//std::unique_ptr<Foo> pt2 = pt1; //error
	std::unique_ptr<Foo> pt2 = std::move(pt1);
	//UniquePtr::Make_it1(pt1);//error
	Make_it2(pt2);
}