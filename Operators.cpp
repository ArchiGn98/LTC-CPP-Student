/*
 * Operators.cpp
 *
 *  Created on: 19 сент. 2017 г.
 *      Author: Паша
 */

#include "pch.h"


TEST(Module4,BasedRangeForOperator1)
{
	int sum=0;
	for(int current : {0,1,2,3,4,5,6})
		sum += current;
	ASSERT_EQ(sum,21);
}

TEST(Module4,BasedRangeForOperator2)
{
	char Str[] = "ABAABBA";
	int countA = 0;
	for(char current : Str)
		countA += (current == 'A');
	ASSERT_EQ(countA,4);
}
