#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
void test_string1()
{
	//为什么要有string；
	//1.string相比字符串，可以扩容
	//2.string 更符合面向对象的思想;
	//c_str获取string其中的字符串，用来兼容c语言
	string s1("hello world");
	//例如fopen中参数是字符串，则必须用c_str
	cout << s1.c_str() << endl;
	//data也是一样的;
	cout << s1.data() << endl;
	//copy,把自己的一部分拷贝到字符数组里面;
}

void test_string2()
{//find
	string s1("file.cpp");
	//没找到就retuen -1;
    //size_t find(const string & str, size_t pos = 0) const;查找string
	//size_t find(const char* s, size_t pos = 0) const;查找s，从pos位置开始
	//size_t find(const char* s, size_t pos, size_t n) const;查找s，从pos开始查找n个位置
	//size_t find(char c, size_t pos = 0) const;查找字符c
//substr。从pos位置取n个字符，返回一个string
	string s2 = s1.substr(1, 5);
//rfind 用法一样，但是从后往前找
//find_first_of("_/\")寻找这个字符串里面的任意一个字符
//find_last_of("")倒着找
//find_first_not_of寻找不是这些字符的;
//getline(cin,str),string的读取
}
void test_string_3()
{
	//to string;各种整形之类的转string，还有其他函数可以string转整形和浮点数
	//string to_string(int val);
	//string to_string(long val);
	//string to_string(long long val);
	//string to_string(unsigned val);
	//string to_string(unsigned long val);
	//string to_string(unsigned long long val);
	//string to_string(float val);
	//string to_string(double val);
	//string to_string(long double val);
}
int main()
{

	return 0;
}