#define  _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
using namespace bit;
void test1()
{
	string str1("erwe");
	const string str2(str1);
}
int main()
{
	test1();
}