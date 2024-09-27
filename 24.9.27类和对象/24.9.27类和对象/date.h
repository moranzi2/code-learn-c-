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
    Date operator+(int day);//返回临时变量
    Date& operator-=(int day);
    Date operator-(int day);//返回临时变量
    int operator-(const Date& d);//日期减去日期，运算符函数重载

    Date& operator++();//前置++//++d1
    //特殊处理：解决语法逻辑不自洽
    Date operator++(int);//后置++//d1++
    Date& operator--();//后置--//d1--
    Date operator--(int);//后置--//d1--
    //inline
    int GetMonthDay(int year, int month)
    {
        //放到静态区只会调用一次
        static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2) {//先算month可以节约时间
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
