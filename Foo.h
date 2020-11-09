#pragma once
#include <memory>
namespace Pointers
{
	class KeeperSharedPtr;
	class Foo
	{
	public:
		std::shared_ptr<KeeperSharedPtr> shared_ptr_ksp;			
	};
	class KeeperSharedPtr
	{
	public:
		std::shared_ptr<Foo> shared_ptr_Foo;
		std::weak_ptr<Foo> weak_ptr_Foo;
	};
}