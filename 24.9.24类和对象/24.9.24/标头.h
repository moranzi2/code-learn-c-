#pragma once
int Add(int left, int right);
//类的声明
//类的正确使用方法是在头文件声明然后把成员函数的定义放在/
//.cpp文件中；
class Date
{
private:
	int _year;
	int _month;//默认成员变量是私有
	//成员函数是公有
	int _day;//是声明，定义的主要标志是开空间(对象实例化)
public:
	void Init(int year, int month, int day);
};
//之后对函数定义的时候需要在函数前面加Date::
//也就是现在类域里面去找；

 