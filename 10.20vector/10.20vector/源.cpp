#define  _CRT_SECURE_NO_WARNINGS 1
#include"vector.h"
#include<vector>
#include<iostream>
#include<string>
using namespace std;
//#include<vector>
//#include<algorithm>
//������һ��find������������Ѱ��vector��list���������
// string���������find����Ϊstring����Ҫ�����Ӵ�
//iterator find(iterator,iterator, int);
	//ջ�����ռ�ȶ�������Ч�ʸ��ߣ�ջ���ڱ�����Ѿ������ˣ�
	//����������Ŀ�С��ռ����ɿռ䲻�������γɿռ���Ƭ;
	//����ʵ����string����һ��str��һ��buff���ɵģ�buff��ջ��
	
	//дʱ�������ڿ�������͸�ֵ��ʱ��ֱ��ǳ���������¶��ָ��ָ��ͬһ��ռ�
	//��һ�����ü�����¼ָ��������������ʱ��ֱ�����ü���--��
	//�޸ĵ�ʱ��������ü���>1,���ȿ����������޸ģ����дʱ������
//void test_vector()
//{
//	vector<string>v;
//	string s1("ƻ��");
//	//��������
//	v.push_back(s1);
//	//�������������������
//	v.push_back(string("�㽶"));
//	//��ʽ����ת��Ϊstring��������������д���һ����ʱ�������洢
//	v.push_back("��ݮ");
//}
//template<typename T>
template<class T>
void print_vector(const vector<T>& v)
{
	//��Ҫ��typename�Ǹ��߱�������vector<T>::const_iterator����һ�����Ͷ�����һ��ȫ�ֱ���
	//��������ڶ���������ĺ�����ʱ����ܻ���֣��Լ�������ʹ�õ��������ܳ���
	typename vector<T>::const_iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}
//���õ���������erase����insert֮��ʹ��֮��Ͳ�����ʹ���ˣ���Ϊ���ܱ���������ݣ�Ȼ��͵�����ʧЧ��
// ���ǹٷ�erase������һ��iterator���Ӷ������˵��������£��Ӷ���ֹ����Ϊ���ݶ�ʧЧ
//���ܾͱ����Ұָ��;
int main()
{
	//�����Խ��ļ���ǳ��
	//vector[]��Խ��ļ����assert����
	//at��Խ��ļ���ǲ����쳣;

	//ֻҪ���йص������ģ�һ�㶼������ҿ�;��Ϊ.end()һ�㶼�����һ��Ԫ�ص���һ��;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
	//���������캯��֧����ʽ����ת��//������ʱ���������г���
	std::string str1 = "11111";//����+��������=ֱ�ӿ�������
	const string& str2 = "11111";//������ʱ����������ʱ����; 
	vector<string> v2;
	v2.push_back(str1);
	v2.push_back("2222");
	v2.push_back(string("111"));
	vector<int> v3({ 10,20 });//ֱ�ӹ���
	vector<int> v4 = { 1,3 };//��ʽ����ת��+�Ż�����;
}