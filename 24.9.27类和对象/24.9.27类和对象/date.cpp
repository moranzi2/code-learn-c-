#define  _CRT_SECURE_NO_WARNINGS 1
#include"date.h"
bool Date::operator>(const Date& d)
{
	if (_year != d._year)
		return _year > d._year;
	if (_month != d._month)
		return _month > d._month;
	return _day > d._month;
}//当有优先级的比较时，这样比较的结构比较好
bool Date::operator<(const Date& d)
{
	if (*this == d)
		return false;
	return !(*this > d);
}
bool Date::operator>=(const Date& d)
{
	return(*this > d || *this == d);
}
bool Date::operator<=(const Date& d)
{
	return(*this < d || *this == d);
}
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year,_month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		//加上本月的天数，因此先加天数再加月
		if (_month > 12)
		{
			_month = 1;
			++_year;
		}
	}
	return *this;
}
Date Date::operator+(int day)//返回临时变量
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0) {
		//减去上一个月的天数，先减month再减去天数
		--_month;
		_day += GetMonthDay(_year, _month);
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
	}
	return *this;
}
Date Date::operator-(int day)//返回临时变量
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}
int Date::operator-(const Date& d)//日期减去日期，运算符函数重载
{//最好的方式其实是按照某一年为基点计算相距的天数然后再相减；
	Date max = *this;
	Date min = d;
	if (max < min)
	{
		max = d;
		min = *this;
	}
	int count = 0;
	while (max != min)
	{
		++min;
		++count;
	}
	return count;
}
Date& Date::operator++()//前置++//++d1
{
	*this += 1;
	return *this;
}
//特殊处理：解决语法逻辑不自洽
//前置++效率更高
Date Date::operator++(int)//后置++//d1++
{
	Date tmp = *this;
	++*this;
	return tmp;
}
Date& Date::operator--()//后置--//d1--
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)//后置--//d1--
{
	Date tmp = *this;
	--*this;
	return tmp;
}