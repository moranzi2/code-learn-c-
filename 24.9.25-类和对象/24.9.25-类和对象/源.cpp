#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"��ͷ.h"
#include<iostream>
using namespace std;
//������thisָ��
//�����Date����������Ϊ���ñ�����֪�����Init������Date�ĳ�Ա����
//thisָ����Ϊ���ñ�����֪����ʱ���ó�Ա������Ҫ�������ݵ��ĸ����в�����
Date::Date()//����ĳ�Ա����-���캯�������Դ��ο��Բ����Σ��������أ�
{
	_year = 1;
	_month = 1;
	_day = 1;
	cout << _year << _month << _day << endl;
}
Date::Date(int year, int month, int day)//����ĳ�Ա����-���캯�������Դ��ο��Բ����Σ��������أ�
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
{//���뱨����Զ������Ϊ�﷨���󣬿�ָ�벻���������뱨��
	Date d1;
	//thisָ�����Ϊ�գ����ǵ��õ�ʱ���Ա�������ܹ�ʹ�����еĳ�Ա����
	// ���ÿ������������;p->printA()�ȼ���(*p).printA();
	// ����������������Ǵ�����thisָ��û�н��н�������˿���ʹ�ã�
	//Date* const this.thisָ�벻���޸�
	//��̬����static��ȫ�ֲŻ���ھ�̬��
	//�ѣ�malloc�Ż���ڶ�
	//this���βΣ���������˴���ջ(�������ô�����ջ)����(Ҳ�����ڼĴ���)
	//���������ַ�����������const�Ĳ�һ���ڳ�����
	d1.Init(2024, 9, 25);

	//���캯�������ڱ�����ʼ�������Ƕ���
	//1.��������������ͬ
	//2.û�з���ֵ������void���ǿգ��ǲ���Ҫд��
	//3.����ʵ�������������Զ����ã�
	//4.���캯����������
	Date d2;//�����εĹ��캯���Զ�����
	//����д��Date d2��������Ϊ�뺯�������޷�����
	Date d3(2024, 9, 25);//�������Ĺ��캯��
}