#pragma once
#include<iostream>
#include<assert.h>
namespace bit 
{
	class string 
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		//string()
		//{

		//}
		char* begin()
		{
			return _str;
		}
		char* end()
		{
			return _str + _size;
		}
		const char* begin()const
		{
			return _str;
		}
		const char* end()const
		{
			return _str + _size;
		}
		string(const char* str="")//构造函数
			:_size(strlen(str))
		{
			_str = new char[_size + 1];
			strcpy(_str, str);
			_capacity = _size;
		}
		string(const string& str)//拷贝构造函数
		{
			_str = new char[str._capacity + 1];
			strcpy(_str, str._str);
			_size = str._size;
			_capacity = str._capacity;
		}
		string(size_t n,char c)//构造函数
		{
			_str = new char[n+1];
			_size = n;
			_capacity = n;
			for (size_t t = 0; t < n; ++t)
			{
				push_back(c);
			}
		}
		~string()//析构函数
		{
			delete[]_str;
			_str = nullptr;
			_size =_capacity = 0;
		}
		string& operator=(const string& str)//=运算符重载
		{
			char* tmp=new char[str._capacity+1];
			strcpy(tmp, str._str);
			delete[]_str;
			_str = tmp;
			_size = str._size;
			_capacity = str._capacity;
			return *this;
		}
		char& operator[](size_t n) 
		{
			assert(n < _size);
			return _str[n];
		}
		const char& operator[](size_t n)const
		{
			assert(n < _size);
			return _str[n];
		}
		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_str[n] = '\0';
			}
			else
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;

				}
				_str[n] = '\0';
			}
			_size = n;
		}
		void reserve(size_t n)
		{
			assert(n > _size);
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			_str[_size - 1] = c;
			++_size;
			_str[_size] = '\0';

		}
		void append(const char* str)
		{
			insert(_size, str);
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		string& operator+=(const string& str)
		{
			append(str._str);
			return *this;
		}
		void swap(string& s)
		{
			std::swap(_str  ,s._str);
			std::swap(_size  ,s._size);
			std::swap(_capacity  ,s._capacity);
		}
		void insert(size_t n,char c)
		{
			assert(n <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			for (size_t t = _size; t > n; --t)
			{
				_str[t] = _str[t - 1];
			}
			_str[n] = c;
			++_size;
			_str[_size] = '\0';
		}
		void insert(size_t n,const char* str)
		{
			assert(n <= _size);
			size_t len = strlen(str);
			reserve(_size + len);
			for (size_t t = _size+len; t-len+1 > n; --t)
			{
				_str[t] = _str[t - len];
			}
			strncpy(_str + n, str, len);
			_size += len;
		}
		void erase(size_t pos)
		{
			assert(pos < _size);
			for (size_t t = pos; t < _size; ++t)
			{
				_str[pos] = _str[pos + 1];
			}
			--_size;
		}
		const char* c_str()const
		{
			return _str;
		}
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
	private:
		char* _str=nullptr;
		size_t _size=0;
		size_t _capacity=0;
	};
	std::ostream& operator<<(std::ostream& out,const string& s)
	{
		for (size_t t = 0; t < s.size(); ++t)
		{
			out << s[t];
		}
		return out;
	}
	std::istream& operator>>(std::istream& in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		size_t i = 0;
		char buff[128];
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
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
	std::istream& getline(std::istream& in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		size_t i = 0;
		char buff[128];
		while (ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
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
}