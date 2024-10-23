#define  _CRT_SECURE_NO_WARNINGS 1
#include"vector.h"
#include<vector>
#include<iostream>
#include<string>
using namespace std;
//#include<vector>
//#include<algorithm>
//里面有一个find函数可以用来寻找vector和list里面的数据
// string不用这里的find是因为string还需要查找子串
//iterator find(iterator,iterator, int);
	//栈区开空间比堆区开的效率更高（栈区在编译就已经开好了）
	//堆里面大量的开小块空间会造成空间不连续，形成空间碎片;
	//所以实际上string是由一个str和一个buff构成的，buff在栈区
	
	//写时拷贝，在拷贝构造和赋值的时候直接浅拷贝，导致多个指针指向同一块空间
	//用一个引用计数记录指针数量，析构的时候直接引用计数--；
	//修改的时候如果引用计数>1,就先拷贝构造再修改，这叫写时拷贝；
//void test_vector()
//{
//	vector<string>v;
//	string s1("苹果");
//	//有名对象
//	v.push_back(s1);
//	//匿名对象，用完就销毁了
//	v.push_back(string("香蕉"));
//	//隐式类型转换为string并且在这个过程中创建一个临时变量来存储
//	v.push_back("草莓");
//}
//template<typename T>
template<class T>
void print_vector(const vector<T>& v)
{
	//需要加typename是告诉编译器，vector<T>::const_iterator这是一个类型而不是一个全局变量
	//这种情况在定义类外面的函数的时候可能会出现，以及在类外使用迭代器可能出现
	typename vector<T>::const_iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}
//在用迭代器进行erase或者insert之后，使用之后就不能再使用了，因为可能变成扩容缩容，然后就迭代器失效了
// 但是官方erase返回了一个iterator。从而进行了迭代器更新，从而防止了因为缩容而失效
//可能就变成了野指针;
int main()
{
	//数组对越界的检查是抽查
	//vector[]对越界的检查是assert断言
	//at对越界的检查是捕获异常;

	//只要是有关迭代器的，一般都是左闭右开;因为.end()一般都是最后一个元素的下一个;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
	//单参数构造函数支持隐式类型转换//产生临时变量，具有常性
	std::string str1 = "11111";//构造+拷贝构造=直接拷贝狗仔
	const string& str2 = "11111";//构造临时对象，引用临时对象; 
	vector<string> v2;
	v2.push_back(str1);
	v2.push_back("2222");
	v2.push_back(string("111"));
	vector<int> v3({ 10,20 });//直接构造
	vector<int> v4 = { 1,3 };//隐式类型转换+优化构造;
}