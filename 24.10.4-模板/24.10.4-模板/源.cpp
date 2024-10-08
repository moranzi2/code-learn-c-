#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
template<typename T>
//模板不能声明和定义分离;
// 
//template<typename T1,typenameT2>需要几种类型就定义几个
// 编译器通过参数类型，用模板生成对应的函数叫做函数实例化
//template<class T>;暂时是一样的
//函数模板
void Swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}
template<typename T>
T Add(T& x, T& y)
{
	return x + y;
}
//具体使用的时候印刷出来另一份函数;
int main()
{
	int a = 1, b = 2;
	int a1 = 1; 
	double d2 = 1.0;
	Swap(a, b);
	swap(a, b);//swap在std命名空间中已经有了;
	//显示实例化;在函数名和参数中间写
	//一般来讲，编译器在类型不是int的时候会进行隐式类型转换，但也可能直接报错
	//Add<int>(a1, d2);vs2022则是直接报错
	//显式实例化同时也是强制要求使用模板;不能用现成的

	//如果函数模板和现成的函数同时存在，先看看能不能用现成的
	//如果不能的话再用模板去生成；
	//但如果现成的需要隐式类型转换(不够匹配)，那就用函数模板的;

	//如果有显式实例化，则必须用模板，不能用现成的;
}
//还有类模板;必须用显式实例化