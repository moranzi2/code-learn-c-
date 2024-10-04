#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(year)
//	{}//友元函数,允许类外函数读取私有成员;
//	//也可以自己写一个get，set函数从而在外面调用_year
//	//friend ostream& operator<<(ostream& _cout, Date& d);
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//class Time
//{//Date是time的友元，date可以访问time的private，time不能访问date
//	friend class Date;
//};
//class A
//{//内部类;只是在A中定义B，实际上B是独立的，A的大小为8;
////B受A类的类域的限制，但是B是全局的;
//public://内部类天生是外部的友元类；
//	class B {
//	private:
//		int b1_;
//	};
//private:
//	int a1_;
//	int a2_;
//};
//int main()
//{//B受A类的类域的限制，但是B是全局的;
//	A::B b1;//所以要加A：：
//}
//class A
//{
//public:
//	A(int a = 0)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "a(int a)" << endl;
//	}
//};
//int main()
//{
//	//有名对象
//	A aa1;
//	//匿名对象//用来方便使用一些函数，不用创建对象了
//	//生命周期只在当前这一行;
//	A;
//	A(5);
//	A(3);
//	//构造+拷贝构造=拷贝构造；
//	//拷贝构造+拷贝构造=拷贝构造；
//}


