#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"标头.h"
using namespace std;
//内联函数(解决每次调用函数都需要建立栈帧的问题)
//在debug模式下可以对内联函数进行调试
//在release模式会把内联函数直接展开不会调试
//以空间换时间，减少调用提高效率
inline int Add(int left, int right)
{//在前面加inline即可
	    
	return left + right;
}//对于较大的函数不适合使用内联（代码膨胀问题）
//当函数为100行而调用了一万次，展开则用了100*1w
//不展开则使用了100+1w
//但是对于编译器来说，如果你这个函数较长或者是递归
//编译器就会自动取消内联不会展开
//inline不建议声明和定义分离，可能会出问题
//内联函数不会生成函数的地址（直接展开）也不会生成函数符号表
//因此当声明和定义分离会导致链接不上；

//为什么定义要和声明分离，如果定义在头文件中
//有两个源文件调用了头文件那么会出现重定义问题
// 其他解决办法：2.static修饰函数（链接属性只在当前文件可见）
// 不会生成（？Add@YAHH@Z）符号表；也就不会在链接时冲突
// 3.只在头文件写定义同时用inline（不生成符号表）不会链接
//#pragma once是让同一个源文件中重复调用的两个重复头文件消失
void func(int a,int b)
{

}
#include<map>
//int main()
//{
//	int i = 0;
//	auto k = i;
//	auto kp = &i;//自动识别右边类型
//	auto* kpp = &i;//必须传指针；
//	//auto的价值就在于当类型特别长的时候减少代码的数量
//	//缺点就在于可读性较差难懂
//	//auto可以做函数的返回值但是不能做参数
//	//auto不能用来定义数组；auto b[]=[0,1,2];不允许；
//	void(*pf1)(int, int) = func;
//	auto pf2 = func;  
//	cout << typeid(pf1).name() << endl;
//	cout << typeid(pf2).name() << endl;
//	//C++11标准新语法
//	//依次取数值中的值赋值给e，自动迭代（只会修改e不会修改数组）
//	//e是数组中的值的拷贝；
//	int array[] = { 1,2,3,4,5 };
//	for (auto e : array)
//	{
//		cout << e << "";
//	}
//	cout << endl;
//	return 0;
//}
//void f(int i)
//{
//	;
//}
//void f(int* i)
//{
//	;
//}
//int main()
//{
//	//NULL的bug;在宏替换以后将NULL改为了0，变成了整形；
//	f(1);
//	f(NULL);
//	//不能用void*，要用int*；f((void*)NULL);
//	//解决办法：用nullptr；
//	f(nullptr);  
//}
//c语言是面向过程(拿盆子，放水，放衣服，放洗衣粉，手搓)。
//c++面向对象(我，洗衣机，衣服，洗衣机)。
//面向对象三大特征：封装继承多态；

struct Stack//将结构体升级成为类但又兼容struct
	//c++更喜欢用class来定义类
{
	//成员变量
	int* a;
	int top;
	int capacity;
	//成员函数//成员函数是存在对象外的某个公共区域中，没有存在类里
	//（）当同时有多个类，可以节省空间；
	void Init()
		{			//..	
	}
};
class Date {
public://从开始一直到下一个访问限定值或者到类的结束；
//struct也能加访问限定符
	void Init(int year, int month, int day)
	{

	}
	int _year;//防止和函数中形参重名;
	int _month;
	int _day;
};
class a2 {
	//没有成员变量的类大小是1byte；占位标识对象实例化的存在；
	//原因需要对这个对象分配一点空间，不然不算一个定义；
	//初始化（给值）不是定义（给空间）
};//计算class的大小仍然要遵循结构体内存对齐
//默认class中的访问权限是私有，struct是公有；
//访问限定符：1。公有。（在类内类外都可以用）2.保护。3.私有（保护和私有类似）
//int  main()
//{
//	struct Stack st1;//可以写struct stack也可以stack
//	Stack st2;//当为class，只能写stack也能写class stack
//	st2.Init();
//
//}

//内存对齐的原因：为了提高效率；空间换时间
//指定对齐数：#pragma pack（1）把对齐数改为1；默认是8
//不对齐会导致平台上移植性不好，部分机器只能一次读4/8个字节；
//那样的话就需要读两次。char int 1 4 4 4 4 .先读前三个再读后一个
int main()
{

}