#define  _CRT_SECURE_NO_WARNINGS 1
#include"date.h"
bool Date::operator>(const Date& d)
{
	if (_year != d._year)
		return _year > d._year;
	if (_month != d._month)
		return _month > d._month;
	return _day > d._month;
}//�������ȼ��ıȽ�ʱ�������ȽϵĽṹ�ȽϺ�
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
		//���ϱ��µ�����������ȼ������ټ���
		if (_month > 12)
		{
			_month = 1;
			++_year;
		}
	}
	return *this;
}
Date Date::operator+(int day)//������ʱ����
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0) {
		//��ȥ��һ���µ��������ȼ�month�ټ�ȥ����
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
Date Date::operator-(int day)//������ʱ����
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}
int Date::operator-(const Date& d)//���ڼ�ȥ���ڣ��������������
{//��õķ�ʽ��ʵ�ǰ���ĳһ��Ϊ���������������Ȼ���������
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
Date& Date::operator++()//ǰ��++//++d1
{
	*this += 1;
	return *this;
}
//���⴦������﷨�߼�����Ǣ
//ǰ��++Ч�ʸ���
Date Date::operator++(int)//����++//d1++
{
	Date tmp = *this;
	++*this;
	return tmp;
}
Date& Date::operator--()//����--//d1--
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)//����--//d1--
{
	Date tmp = *this;
	--*this;
	return tmp;
}