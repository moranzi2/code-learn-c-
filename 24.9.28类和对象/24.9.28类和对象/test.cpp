
#include<iostream>
using namespace std;
//class Date {
//	//最后的两个默认成员函数:
//	//取地址重载，(完全可以不写);
//	//用来让你能够得到类的地址;
//public:
//	void Print()const//在这里加const(定义声明都加)
//		//但是不能所有函数都加，有的需要修改成员;
//		//变成const Date*，权限就不会被放大了；
//		//同时其他的还能继续用，因为权限可以缩小;
//	{//const函数中不能调用非const;
//		cout << _year << endl;
//	}
//
//	//再谈构造函数:其实不等于初始化，因为初始化不能多次
//	//但是可以构造多次； 初始化列表只能一次
//	//同时，还有个新玩法，初始化列表；(解决const成员无法初始化)
//	// 因为const和引用必须在定义的时候初始化，所以必须走初始化列表；
//	//能用初始化列表就用初始化列表//（先走初始化列表，再走{里面的}）
//	//缺省值就是没有对他们初始化的时候就用缺省值
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		//，_aa(1,2)还可以对内置类型初始化
//	{}
//	Date(int year = 1, int month = 2)
//	{
//		_year = year;
//	}
//	 
//	
//	//👉友元声明,加入后才可以访问私有函数
//	friend istream& operator>>(istream& out,Date& d);
//	friend ostream& operator<<(ostream& out, const Date& d);
//private:
//	int _year=5;//缺省值
//	int _month;
//	int _day;
//};
////流插入和流提取需要写为全局函数不能写成成员函数
////不然的话会导致写为d1<<cout;
//ostream& operator<<(ostream& out, const Date& d)
//{
//	//流插入就是为了解决自定义类型;
//	out << d._year << endl;
//	return out;
//	//返回ostream，从而才能支持cout<<d1<<d2；
//}
////cout 和cin进行对比;
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year;
//	return in;
//}
//int main()
//{
//	const Date d1;//在这个情况下，成员函数无法调用。解决办法
//	//在函数()后面加一个const;
//	//const int* a;修饰a指向的内容
//	//临时变量具有常性
//	//类型转换和和表达式返回值，函数调用传值返回产生临时变量；
//}
//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//		int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//		//哪怕没有默认构造函数，也会通过初始化列表去访问成员中自定义类型的默认构造函数
//		//同时，也会对声明对象赋值，顺序
//		//1.声明对象赋值
//		//2.走初始化列表
//		//3.走花括号里面的
//
//	{}
//private:
//	int _day=5;
//	int* p = nullptr;//缺省值可以这么写
//	int* p2 = (int*)malloc(4);
//};
//class A
//{
//public:
//	/*explicit */A(int x)//如何不想进行隐式类型转换就写explicit
//	{
//		_x = x;
//	}
//	int _x; 
//};
//class B
//{
//public:
//	int _x;
//	A _b = 3;
//
//};
//class Stack
//{
//public:
//	void Push(const A& a)
//	{
//		//
//	}
//};
//int main()
//{
//	Date d(1);
//	A cc1(1);
//	//需要有一个单参数的构造函数;（隐式类型转换）
//	//构造一个临时对象再拷贝构造;
//	// 但实际上->编译器优化了，
//	//同一个表达式连续步骤的构造会被合二为一;
//	//从而直接构造了
//	A cc2 = 2;
//	 const A& cc3 = 3;//引用临时变量要加const
//	 A cc4(3);
//	 Stack st;
//	 st.Push(cc3);
//	 //隐式类型转换的好处
//	 st.Push(4);
//}
class A
{
public: A(int a1, int a2)
	:_a1(a1)
	, _a2(a2)
	//初始化的顺序是按照声明的顺序来的，而不是按照初始化列表顺序的
{

}
	  int _a1;
	  int _a2;
};
class B
{
private://各种缺省值;
	int _a = 1;
	int* p = (int*)malloc(4);
	A aa1 = { 1,2 };
	static int GetN()
	{
		return n;
	}//静态成员函数没有this指针，专门为了访问静态成员变量
	//如果需要得知n的值，可以写GetN函数；
	static int n;//声明
	//因为是静态不属于某一个对象，属于整个类，在类里声明在外面定义；
	//统计构造次数，在构造和拷贝构造中写++n
	//写到类里面是为了封装，让其他地方无法随意修改;
};
//定义
int B::n = 0;
int main()
{
	//C++11
	A a1 = { 1,2 };//隐式类型转换的另一种类型
}