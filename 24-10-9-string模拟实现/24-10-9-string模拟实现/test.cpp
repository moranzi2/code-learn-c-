#define  _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
using namespace bit;
int main()
{
	//string a1("ehfehg");
	//string::iterator it3 = a1.begin();//加string::就是因为有多个迭代器，这个迭代器在string 域里面
	//while (it3 != a1.end())
	//{
	//	std::cout << *it3 << std::endl;
	//	++it3;
	//}
	//for (auto e : a1)
	//{
	//	//范围for其实就相当于迭代器;从汇编层面来说;
	//}
	//string a2("hello world");
	//a2.insert(3, "hello bit");
	//for (auto e : a2)
	//{
	//	std::cout << e << std::endl;
	//}
	string a1("hello bit");
	string a2("hello world");
	a1 = a2;//直接写=的话是浅拷贝，所以=也要自己写
}