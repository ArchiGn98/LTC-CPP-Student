/*
 * MoveConstructor.cpp
 *
 *  Created on: 21 сент. 2017 г.
 *      Author:Luxoft
 *
 *      !!!You need use -fno-elide-constructors gcc options for turnoff return optimization for correct demonstration
 *      of these tests
 */
#include "pch.h"
#include "gtest/gtest.h"

class TestWithoutMoveConstructor
{
private:
	char *Buffer;
	int size;
public:
	static int CountCopyObjet;
    TestWithoutMoveConstructor(char *src);
    TestWithoutMoveConstructor(const TestWithoutMoveConstructor &src);
    TestWithoutMoveConstructor Copy();
    char * GetBuffer() const { return Buffer;}
};

int TestWithoutMoveConstructor::CountCopyObjet = 0;

TestWithoutMoveConstructor::TestWithoutMoveConstructor(char *src)
{
	int i = 0,j;
	for(;src[i++];);
	Buffer = new char [i];
	size = i-1;
	for(j = 0; j < size; j++)
		Buffer[j] = src[j];
	Buffer[j] = '\0';
}
TestWithoutMoveConstructor::TestWithoutMoveConstructor(const TestWithoutMoveConstructor &src) :
		size(src.size)
{
	Buffer = new char[size+1];
	int i=0;
	for(;i<size;i++)
	  Buffer[i]= src.Buffer[i];
	Buffer[i] = '\0';
	CountCopyObjet++;
}
TestWithoutMoveConstructor TestWithoutMoveConstructor::Copy()
{
  TestWithoutMoveConstructor r(Buffer);
  return r;
}


//TEST(Module7,CopyConstructorPerformanceProblem)
//{
//  TestWithoutMoveConstructor x("123456");
//  TestWithoutMoveConstructor y = x.Copy();
//  ASSERT_STREQ(y.GetBuffer(),"123456");
//  ASSERT_EQ(TestWithoutMoveConstructor::CountCopyObjet,2);
//
//}
//--------------------------------------------------------------------------------------------------------

class TestMoveConstructor
{
private:
	char *Buffer;
	int size;
public:
	int static CountCopyObject;
    TestMoveConstructor(char *src);
    TestMoveConstructor(const TestMoveConstructor &src);
    TestMoveConstructor(TestMoveConstructor &&src);
    TestMoveConstructor Copy();
    char * GetBuffer() const { return Buffer;}
};

int TestMoveConstructor::CountCopyObject = 0;

TestMoveConstructor::TestMoveConstructor(char *src)
{
	int i = 0,j;
	for(;src[i++];);
	Buffer = new char [i];
	size = i-1;
	for(j = 0; j < size; j++)
		Buffer[j] = src[j];
	Buffer[j] = '\0';
}
TestMoveConstructor::TestMoveConstructor(const TestMoveConstructor &src) :
		size(src.size)
{
	Buffer = new char[size+1];
	int i=0;
	for(;i<size;i++)
	  Buffer[i]= src.Buffer[i];
	Buffer[i] = '\0';
	CountCopyObject++;
}


TestMoveConstructor::TestMoveConstructor(TestMoveConstructor &&src)
{
	Buffer = src.Buffer;
	size = src.size;
	src.Buffer = nullptr;

}

TestMoveConstructor TestMoveConstructor::Copy()
{
  TestMoveConstructor r(Buffer);

  return r;
}

TEST(Module7,UseMoveConstructor)
{
  TestMoveConstructor x("123456");
  TestMoveConstructor y(x.Copy());
  ASSERT_EQ(TestMoveConstructor::CountCopyObject,0);
}
