#include "pch.h"
#include "Dispatcher.h"
TEST(Module1, InlineLinkOtherModule)
{
	ASSERT_EQ("some static string", Dispatcher::standard_string);
}

