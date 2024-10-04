#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//****************************************
//内存管理
//分区：1.内核空间（用户代码不能读写）
//2.栈(向下增长)(函数)
//3.内存映射段(文件映射，动态库，匿名映射)
//4.堆（向上增长）(malloc)
//5.数据段（全局数据，静态数据）(静态区)
//6.代码段（可执行代码，只读常量）(常量区)

//int main()
//{
//	char char2[] = "abcd";
//	//abcd在常量区，会在栈区创建一个数组，存放a，bcd。
//	//因此*char2在栈区
//	const char char3[] = "abds";//少了一个创建数组的过程;
//	//char3也在栈区，*char3在常量区;
//
//class ListNode
//{
//public:
//	ListNode* _next;
//	ListNode* _prev;
//	int val;
//	ListNode(int vla)
//		:val (vla)
//	{
//
//	}
//};
//int main()
//{
//	//c++内存管理方法
//	int* p1 = new int;
//	int* p2 = new int[10];//需要十个int大小的空间对象
//	delete p1;
//	delete[]p2;//如果new[]，也要返回[]；
//	//可以控制初始化了
//	int* p3 = new int(10);//new一个int初始化为10;
//	int* p4 = new int[10] {1, 2, 3, 4, 5};//new数组后初始化;
//	delete p3;
//	delete[]p4;
//	//new一个自定义类型,开空间加构造函数;
//	//new失败以后自己会抛异常，不需要手动检查;
//	ListNode* node1 = new ListNode(1);
//	try {
//		
//	}
//	catch (const exception& e)//捕获异常
//	{
//		cout << e.what() << endl;
//	}
//	//operator new是对malloc封装，operator free是对free封装;
//	//几乎没什么用,是在系统中用的;
//}
class A {
public:
	A()
	{
		cout << "coutA->" << endl;
	}
	~A()
	{
		cout << "cout~A->" << endl;
	}
private:
	int a;
};
//int main()
//{
//	A* p1 = new A; //如果自己没有写析构，那就不用存了，因为他直接不调用了
//	A* p2 = new A[10];//实际上开辟了11个int的空间，最前面的空间存了一个10，用来告诉你析构应该析构几次
//	int* b = new int[10];//开辟十个int空间
//	delete[] p2;//析构十次+operator delete
//	//new的底层其实就是malloc，但是可以弄自定义类型，
//	//并且可以自动调用构造函数方便并且自动检查;
//	//new=operator new+构造函数;operator new=malloc;
//	//sizeof()运算符,编译的时候就已经算出来了;
//	//strlen函数，运行的时候再进行;
//	//new也是一个操作符，编译的时候直接转换为operator new;
//}

//int main()
//{
//	//显式调用构造函数和析构函数;
//	A* p2 = (A*)operator new(sizeof(A));
//	//内存池;//稍微了解
//	new(p2)A();
//	p2->~A();
//	operator delete(p2);
//}


///////////////////////////////////////
//malloc/free和new/delete区别;
//1.malloc和free是函数
//2.malloc申请的空间不会初始化
//3.malloc申请空间需要计算传递空间大小，new只需要加上空间的类型和数量
//4.malloc返回值是void*，需要强转，new不用
//5.malloc需要判断是否为NULL，new自己会捕获异常
//6.malloc/free不会调用构造函数和析构函数，而new会调用构造函数和析构函数;
