#include "pch.h"
#include <iostream>

unsigned long long operator ""_min(unsigned long long minutes)
{
	return minutes * 60;
}

const char* operator ""letter(unsigned long long value)
{
	switch (value) 
	{
	case 0: return "zero";
	case 1: return "one";
	case 2: return "two";
	default: return "other";
	}
}
unsigned long long operator "" b(const char* str)
{
	unsigned long long result = 0;
	size_t size = strlen(str);
	std::cout << "size: " << size << std::endl;

	for (size_t i = 0; i < size; ++i)
	{
		assert(str[i] == '1' || str[i] == '0');
		result |= (str[i] - '0') << (size - i - 1);
	}

	return result;
}
TEST(Module3, MinutesToSeconds)
{
	ASSERT_EQ(10_min, 600);
}

TEST(Module3, NumberToLetter)
{
	ASSERT_STREQ(0letter, "zero");
	ASSERT_STREQ(2letter, "two");
	ASSERT_STREQ(5letter, "other");
}

TEST(Module3, NumberToBinary)
{
	ASSERT_EQ(101b, 5);
}