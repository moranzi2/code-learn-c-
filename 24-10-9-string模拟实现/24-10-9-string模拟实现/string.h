#pragma once
#include<iostream>
#include<assert.h>
namespace bit
{
	class string 
	{
	public:
		//string()//初始化列表。为了保持与c原因呢的兼容，应当给_str一个值为\0
		//	:_str(new char[1])//所以不管什么情况都不能给nullptr;
		//	,_size(0)
		//    ,_capacity(0)
		//{
		//	_str[0] = '\0';
		//}
		//string(const char* str)
		//	:_str(new char[strlen(str)+1])
		//	,_size(strlen(str))
		//	,_capacity(strlen(str))
		//{
		//	strcpy(_str, str);//后面的给了前面
		//}
		string(const char* str = "")//也是因为要与c语言兼容，必须要有一个\0
			:_size(strlen(str))//全缺省可以替代前面的两个;
		{
			_capacity = _size;//为了效率不应当使用两次strlen;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string& s)
		{
			//也可以先拿一个tmp取走s的str，然后tmp和*this互换
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		~string()
		{
			delete[] _str;//以后都用delete来代替free
			_str = nullptr;
			_size = _capacity = 0;
		}
		//const不能调用非const成员函数，权限放大
		//非const可以调用const成员函数，权限的缩小; 
		size_t size() const//加const是为了让const string类型也能够使用
		{
			//为了获得_size
			return _size;
		}
		size_t capacity()const//如果是不需要改变的函数，一律都加上const，这样两个都可以用了
		{
			return _capacity;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];//算数运算符重载，会变为内联函数

		}
		const char& operator[](size_t pos)const
		{//变为了只读的成员函数;
			assert(pos < _size);
			return _str[pos];

		}
		const char* c_str()
		{
			return _str;
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n+1];//开空间永远要多开一个，为\0做准备的;
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;

				_capacity = n;
			}
		}
		void push_back(char ch)//可以直接用insert来代替
		{
			//扩容
			if (_size == _capacity)
			{
				reserve(_capacity==0 ? 4 : 2 * _capacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{//可以直接insert字符串;
			//扩容
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str+_size,str);
			_size += len;
			//这里尾插一个字符串不能用strcat，因为它的运行逻辑是找\0的位置，会遍历原本的字符串
		}
		string& operator=(const string& s)
		{
			//也可以直接swap（s）;
			char* tmp = new char[s._capacity];
			delete[]_str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
			return *this;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this; 
		}
		string& operator+=(const char* ch)
		{
			append(ch);
			return *this;
		}
		bool operator==(const string& s)//比较大小的实际上是非成员函数，是为了支持字符串和string来比较;
		{
			return strcmp(_str, s._str);
		}
		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}//如果我们没有进行扩容，使用的时候不会有问题，但是结束后会报错在堆缓冲区结束后写入内存，也就是写入了malloc以外的内存空间;
			size_t end = _size+1;
			while (end > pos)//当pos为0，会发生死循环的问题;
			{//当一个运算符两边的操作符的类型不同，会发生类型提升，提升为范围更大的那个
				_str[end] = _str[end-1];
				--end;
			}
			_str[pos] = ch;
			++_size;


		}
		void insert(size_t pos, const char* ch)
		{
			assert(pos <= _size);
			int len = strlen(ch);
			if (_size + len > _capacity)
			{
				reserve(_capacity == 0 ? 4 : _size + len);
			}
			size_t end = _size + len;
			while (end >= pos+len)
			{
				_str[end] = _str[end - len];
				end--;
			}
			strncpy(_str + pos, ch,len);//和strcpy的区别就在于可以选择几个;
			_size = _size + len;
		}
		void erase(size_t pos,size_t len=npos)
		{//从pos这个位置开始删
			assert(pos < _size);
			if (len == npos || /*pos + len >= _size*/len>=_size-pos)
			{//当pos+len>npos就会有bug;
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
			}
				
		}
		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				reserve(n);
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
			
		}
		void swap(string& s)//全局里面的swap是深拷贝，需要进行三次拷贝和一次析构，因此单独写一个成员函数
		//为了防止使用全局模板swap;我们又写了一个专门的void swap(string& a,string& b)
	    //因此使用的时候会先用能匹配的;(模板知识);
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}
		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}
		size_t find(char ch,size_t pos=0)const
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		size_t find(const char* sub, size_t pos = 0)const
		{
			assert(pos < _size);
			const char* p=strstr(_str+pos, sub);//在一个字符串中寻找另一个字符串
			if (p)
			{
				return (p - _str);
			}
			return npos;
		}
		string substr(size_t pos = 0, size_t len = npos)
		{
			string sub;
			if (len == npos || len >= _size - pos)
			{
				for (size_t i = pos; i < _size; ++i)
				{
					sub += _str[i];
				}
			}
			else
			{
				for (size_t i = pos; i < pos + len; ++i)
				{
					sub += _str[i];
				}
			}
		}
		//一个简单的迭代器;
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str+_size;
		}
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
		public:
			static const int npos;
	};
	std::ostream& operator<<(std::ostream& out, const string s)
	{
		for (auto ch : s)
		{//用的是迭代器，所以不需要访问私有成员所以不需要用友元了
			out << ch;
		}
		return out;
	}
	std::istream& operator>>(std::istream& in, string& s)
	{
		s.clear();//防止原本有数据，所以应该先清楚数据
		char ch;
		ch=in.get();//实际上in是读不到换行和空格的，会直接忽略掉
		//所以直接用in的话会导致无法出循环，死循环，所以要用in.get(),相当于getchar;
		while (ch != ' ' && ch != '\n')
		{
			s += ch; ch=in.get();
		}
		return in;
	}
	void swap(string& x, string& y)
	{
		x.swap(y);//为了防止调用全局
	}
	std::istream& getline(std::istream& in, string& s)
	{
		s.clear();//防止原本有数据，所以应该先清楚数据
		char ch;
		ch = in.get();//实际上in是读不到换行和空格的，会直接忽略掉
		size_t i = 0;
		char buff[128];
		//所以直接用in的话会导致无法出循环，死循环，所以要用in.get(),相当于getchar;
		while (ch != '\n')//但是不断的+=会导致多次扩容，负担很大;
		{//所以引入了buff，扩容次数较少，负担较小;
			buff[i++] = ch;
			if (i==127)
			{
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			 ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}
	const int string::npos = -1;
}  
