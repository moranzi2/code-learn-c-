//#define  _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using std::swap;
//int main()
//{
//	int i = 0, t = 5;
//	swap(i, t);
//}
////类模板声明和定义不能在不同文件

//ctrl+f搜索;
#include<iostream>
#include<string>
using namespace std;
void test2()
{
	string s1("hello world");
	//string的size不包含/0;
	//s2.end()为\0所在的位置;
	for (size_t i = 0; i < s1.size(); i++)
	{
		//其实就是重载了[]
		cout << s1[i] << " ";
		cout << s1.operator[](i) << " ";
	}
	cout << endl;
	string::iterator it1 = s1.begin();//迭代器不是指针但是行为类似指针;
	while (it1 != s1.end())//end是最后一个数据的下一个位置;
	{
		cout << *it1 << " ";
	}
	//范围for可以遍历容器
	//底层其实就是迭代器;
	for (auto e : s1)
	{
		cout << e << " ";
	}
}
void test3()
{
	//反向迭代器,从后往前迭代;
	string s1("hello world");
	string::reverse_iterator rit = s1.rbegin();
		while (rit != s1.rend())
		{
			cout << *rit << " ";
			++rit;//仍然是++;
	}
		cout << endl;
		//const迭代器,其他地方不变;
		//普通迭代器是可读可写的，但是const迭代器只读;
		const string s2("hello world");
		//还有一个const_reverse_iterator;只读反向迭代器;
		string::const_iterator it = s2.begin();
		while (it != s2.end())
		{
			cout << *it << " ";
			++it;
		}
}

//reserve 保留储备,用来扩容
//reverse 反转,翻转，反转迭代器;
void test4()
{
	string s1("hello world");
	cout << s1.size() << endl;//size和length其实是一样的;都不包含\0
	cout << s1.length() << endl;
	cout << s1.max_size() << endl;//最大容量;
	cout << s1.capacity() << endl;//容量;
	s1.clear();//清理掉数据，不会清理容量;
	//为了解决清理数据后容量浪费
	s1.shrink_to_fit();//缩容;不会缩到0;
	//当知道需要插入多少数据的时候可以提前开好空间;
	s1.reserve(100);//提前保留空间,也就是扩容;但是比capacity小的时候不会缩容;
	//string中实际上并不依赖空字符\0作为字符串结束的判断机制，而是看size，因此可以出现\0；
	s1.resize(10);//改变size，如果比size小，那就删除，比size大，就插入空字符\0，比capacity大，就扩容
	cout << s1.size() << endl;
	s1.resize(20, 'a');//当大于size，插入a;
	cout << s1.size() << endl;
}
void test5()
{
	string s1("hello world");
	
	//[]和at的功能是一样的，
	//operator[]重载;
	cout << s1[4] << endl;//assert断言防止越界
    //成员函数at;
	cout << s1.at(4) << endl;//抛异常防止越界
	cout << s1.front() << endl;//头
		cout << s1.back() << endl;//尾
}
void test6()
{
	string s1("hello world");
	s1.push_back('!');//插入一个字符;
	cout << s1 << endl;
	s1.append("hello bit");//插入一个字符串或者string;
	    //string& append(const string & str);插入string
		//string& append(const string & str, size_t subpos, size_t sublen);string从subpos数sublen个
		//string & append(const char* s);插字符串
		//string& append(const char* s, size_t n);插字符串前n个；
		//string& append(size_t n, char c);插n个字符
		//template <class InputIterator>   string& append(InputIterator first, InputIterator last);
	 //举例
	string s2(" hello ");
	s1.append(++s2.begin(), --s2.end());

	//重载+=,可以+=字符串，string，字符;
	s1 += s2;
	s1 += "appel";
	s1 += '  ';


	//assign赋值
	s1.assign("xxxxx");//直接对原本的空间进行覆盖，可能扩容，接口和append，构造函数类似;
	

	//insert插入
	s1.insert(0, "yyyy");//在pos位置插入后面的字符串或者string;

	//erase删除;
	s1.erase(2, 4);//在下表2位置删除后面的4个字符,默认为-1，也就是全部删除;
	s1.erase();//全缺省的话相当于clear;

	//replace将特定位置的地方的几个字符替换为字符串或者string，自己查接口
	string s3("hello world");
	s3.replace(5, 1, "%20");
	//insert,erase,replace能少用则少用，都需要挪动数据，效率较低;
	//find 寻找一个字符或者字符串; 如果没找到则return npos;也就是size_t -1
}

class Solution {
public:
	bool isLetter(char s)
	{
		if (s >= 'a' && s <= 'z')
			return true;
		if (s >= 'A' && s <= 'Z')
			return true;
		else
			return false;
	}
	string reverseOnlyLetters(string s) {
		size_t left = 0;
		size_t right = s.size()-1;
		while (left < right)
		{
			while (left < right && !isLetter(s[left]))
				left++;
			while (left < right && !isLetter(s[right]))
				right--;
			swap(s[left], s[right]);
			++left;
			--right;
		}
		return s;
	}
};
int main()
{
	string s1("s   ");
	Solution s2;
	s2.reverseOnlyLetters(s1);
	//构造函数
	//1.string();
	//2.string (const string& str);拷贝构造其他string类型
	//3.string (const string& str, size_t pos, size_t len = npos);拷贝构造从pos开始的前n个
	//4.string (const char* s);拷贝构造一个字符串
	//5.string (const char* s, size_t n);拷贝构造字符串的前n个；
	//6.string (size_t n, char c)构造n个c字母
}