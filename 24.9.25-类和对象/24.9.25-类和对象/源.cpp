#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"标头.h"
#include<iostream>
using namespace std;
//隐含的this指针
//这里的Date：：作用是为了让编译器知道这个Init函数是Date的成员函数
//this指针是为了让编译器知道此时调用成员函数是要对类数据的哪个进行操作；
Date::Date()//特殊的成员函数-构造函数（可以传参可以不传参，可以重载）
{
	_year = 1;
	_month = 1;
	_day = 1;
	cout << _year << _month << _day << endl;
}
Date::Date(int year, int month, int day)//特殊的成员函数-构造函数（可以传参可以不传参，可以重载）
{
	_year = year;
	_month = month;
	_day = day;
	cout << _year << _month << _day << endl;
}
void Date:: Init(int year, int month, int day)
{
	this->_year = year;
	cout <<this->_year << endl;
	this->_month = month;
	this->_day = day;
}
int main()
{//编译报错永远都是因为语法错误，空指针不会引发编译报错；
	Date d1;
	//this指针可以为空，但是调用的时候成员函数不能够使用其中的成员变量
	// 调用可以有两种情况;p->printA()等价于(*p).printA();
	// 这两种情况都仅仅是传递了this指针没有进行解引用因此可以使用；
	//Date* const this.this指针不能修改
	//静态区：static和全局才会存在静态区
	//堆：malloc才会存在堆
	//this是形参，参数，因此存在栈(函数调用创建堆栈)区；(也可能在寄存器)
	//常量区：字符串常量。加const的不一定在常量区
	d1.Init(2024, 9, 25);

	//构造函数；用于变量初始化而不是定义
	//1.函数名和类名相同
	//2.没有返回值（不是void不是空，是不需要写）
	//3.对象实例化编译器会自动调用；
	//4.构造函数可以重载
	Date d2;//不带参的构造函数自动调用
	//不能写成Date d2（）；因为与函数声明无法区分
	Date d3(2024, 9, 25);//带参数的构造函数
}