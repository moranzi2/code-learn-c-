#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class Date 
{
public:
    Date(int year = 1, int month = 1, int day = 1);
    bool operator>(const Date& d);
    bool operator<(const Date& d);
    bool operator>=(const Date& d);
    bool operator<=(const Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    Date& operator=(const Date& d);
    Date& operator+=(int day);
    Date operator+(int day);//������ʱ����
    Date& operator-=(int day);
    Date operator-(int day);//������ʱ����
    int operator-(const Date& d);//���ڼ�ȥ���ڣ��������������

    Date& operator++();//ǰ��++//++d1
    //���⴦������﷨�߼�����Ǣ
    Date operator++(int);//����++//d1++
    Date& operator--();//����--//d1--
    Date operator--(int);//����--//d1--
    //inline
    int GetMonthDay(int year, int month)
    {
        //�ŵ���̬��ֻ�����һ��
        static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2) {//����month���Խ�Լʱ��
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                return 29;
        }
        return monthDays[month];
    }
private:
	    int _year;
    	int _month;
    	int _day;
};
