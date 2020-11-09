/*
 * Template.cpp
 *
 *  Created on: 22 ����. 2017 �.
 *      Author: ����
 */
#include "pch.h"
#include "Template.h"
#include <initializer_list>

TEST(Module10,UseTemplateForSimpleType)
{
	Storage<int> storageInt{1,2,3,4,5};
	Storage<long> storageLong {2,4,6,8};

	ASSERT_EQ(storageInt.GetSum(),15);
	ASSERT_EQ(storageLong.GetSum(),20);
}
//-------------------------------------------------------------------------------------------------

class CustomType
{
	int v1;
	int v2;
public:
	CustomType()=default;
	CustomType(int v) : v1(v),v2(0){}
	CustomType(int v1,int v2) : v1(v1),v2(v2){}
	CustomType& operator+=(CustomType& op);
	//For google Test Framework purpose only!
	friend	bool operator==(const CustomType &op1, const CustomType &op2);
};
CustomType& CustomType::operator+=(CustomType &op)
{
  v1 += op.v1;
  v2 += op.v2;
  return *this;
}
bool operator==(const CustomType &op1, const CustomType &op2)
{
  return op1.v1 == op2.v1 && op1.v2 == op2.v2;
}
TEST(Module10,UseTemplateForUserType)
{
 Storage<CustomType> x { CustomType(2,3),CustomType(5,2),CustomType(1,2)};
 ASSERT_EQ(x.GetSum(),CustomType(8,7));
}
//--------------------------------------------------------------------------------------

template<>
class Storage<char>
{
private:
	char *Buffer;
	int count;
public:
	Storage(std::initializer_list<char> init);
	~Storage();
	char* GetSum();
};

Storage<char>::Storage(std::initializer_list<char> init):count(0)
{
  Buffer = new char[init.size()+1];
  for(auto c : init)
	  Buffer[count++] = c;
  Buffer[count] = '\0';
}
Storage<char>::~Storage()
{
	delete []Buffer;
}
char* Storage<char>::GetSum()
{
	return Buffer;
}

TEST(Module10,FullSpecializationTemplate)
{
	Storage<char,10> x {'a','b','c','d'};
	ASSERT_STREQ(x.GetSum(),"abcd");
}
//--------------------------------------------------------------------------------------------

TEST(Module10,PartialSpecializationTemplate)
{
	TestPartial<int> x(4);
	int v = 3;
	TestPartial<int*> y(&v);
	ASSERT_EQ(x.GetValue(),4);
	ASSERT_EQ(y.GetValue(),3);
}

//--------------------------------------------------------------------------------------------
template<typename T>
	constexpr T pi = T(3.14f);
template<>
	constexpr const char* pi<const char*> = "pi";

TEST(Module10,VariableTemplate)
{

	float p = pi<float>;
	const char*m = pi<const char*>;
	ASSERT_NEAR(p,3.14,0.1);
	ASSERT_STREQ(m,"pi");
}
//-------------------------------------------------------------------------------------------------
template<typename T>
int Sum(T t)
{
	return t;
}
template<typename T,typename...Args>
int Sum(T t,Args... args)
{
  return t+Sum(args...);

}
TEST(Module10,VariadicTemplate)
{
	ASSERT_EQ(Sum(1,2,3),6);
}
