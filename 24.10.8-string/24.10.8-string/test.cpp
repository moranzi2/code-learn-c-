#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
void test_string1()
{
	//ΪʲôҪ��string��
	//1.string����ַ�������������
	//2.string ��������������˼��;
	//c_str��ȡstring���е��ַ�������������c����
	string s1("hello world");
	//����fopen�в������ַ������������c_str
	cout << s1.c_str() << endl;
	//dataҲ��һ����;
	cout << s1.data() << endl;
	//copy,���Լ���һ���ֿ������ַ���������;
}

void test_string2()
{//find
	string s1("file.cpp");
	//û�ҵ���retuen -1;
    //size_t find(const string & str, size_t pos = 0) const;����string
	//size_t find(const char* s, size_t pos = 0) const;����s����posλ�ÿ�ʼ
	//size_t find(const char* s, size_t pos, size_t n) const;����s����pos��ʼ����n��λ��
	//size_t find(char c, size_t pos = 0) const;�����ַ�c
//substr����posλ��ȡn���ַ�������һ��string
	string s2 = s1.substr(1, 5);
//rfind �÷�һ�������ǴӺ���ǰ��
//find_first_of("_/\")Ѱ������ַ������������һ���ַ�
//find_last_of("")������
//find_first_not_ofѰ�Ҳ�����Щ�ַ���;
//getline(cin,str),string�Ķ�ȡ
}
void test_string_3()
{
	//to string;��������֮���תstring������������������stringת���κ͸�����
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