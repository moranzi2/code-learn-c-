#pragma once
#include<iostream>
#include<assert.h>
namespace bit
{
	class string 
	{
	public:
		//string()//��ʼ���б�Ϊ�˱�����cԭ���صļ��ݣ�Ӧ����_strһ��ֵΪ\0
		//	:_str(new char[1])//���Բ���ʲô��������ܸ�nullptr;
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
		//	strcpy(_str, str);//����ĸ���ǰ��
		//}
		string(const char* str = "")//Ҳ����ΪҪ��c���Լ��ݣ�����Ҫ��һ��\0
			:_size(strlen(str))//ȫȱʡ�������ǰ�������;
		{
			_capacity = _size;//Ϊ��Ч�ʲ�Ӧ��ʹ������strlen;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string& s)
		{
			//Ҳ��������һ��tmpȡ��s��str��Ȼ��tmp��*this����
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		~string()
		{
			delete[] _str;//�Ժ���delete������free
			_str = nullptr;
			_size = _capacity = 0;
		}
		//const���ܵ��÷�const��Ա������Ȩ�޷Ŵ�
		//��const���Ե���const��Ա������Ȩ�޵���С; 
		size_t size() const//��const��Ϊ����const string����Ҳ�ܹ�ʹ��
		{
			//Ϊ�˻��_size
			return _size;
		}
		size_t capacity()const//����ǲ���Ҫ�ı�ĺ�����һ�ɶ�����const��������������������
		{
			return _capacity;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];//������������أ����Ϊ��������

		}
		const char& operator[](size_t pos)const
		{//��Ϊ��ֻ���ĳ�Ա����;
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
				char* tmp = new char[n+1];//���ռ���ԶҪ�࿪һ����Ϊ\0��׼����;
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;

				_capacity = n;
			}
		}
		void push_back(char ch)//����ֱ����insert������
		{
			//����
			if (_size == _capacity)
			{
				reserve(_capacity==0 ? 4 : 2 * _capacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{//����ֱ��insert�ַ���;
			//����
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str+_size,str);
			_size += len;
			//����β��һ���ַ���������strcat����Ϊ���������߼�����\0��λ�ã������ԭ�����ַ���
		}
		string& operator=(const string& s)
		{
			//Ҳ����ֱ��swap��s��;
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
		bool operator==(const string& s)//�Ƚϴ�С��ʵ�����Ƿǳ�Ա��������Ϊ��֧���ַ�����string���Ƚ�;
		{
			return strcmp(_str, s._str);
		}
		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}//�������û�н������ݣ�ʹ�õ�ʱ�򲻻������⣬���ǽ�����ᱨ���ڶѻ�����������д���ڴ棬Ҳ����д����malloc������ڴ�ռ�;
			size_t end = _size+1;
			while (end > pos)//��posΪ0���ᷢ����ѭ��������;
			{//��һ����������ߵĲ����������Ͳ�ͬ���ᷢ����������������Ϊ��Χ������Ǹ�
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
			strncpy(_str + pos, ch,len);//��strcpy����������ڿ���ѡ�񼸸�;
			_size = _size + len;
		}
		void erase(size_t pos,size_t len=npos)
		{//��pos���λ�ÿ�ʼɾ
			assert(pos < _size);
			if (len == npos || /*pos + len >= _size*/len>=_size-pos)
			{//��pos+len>npos�ͻ���bug;
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
		void swap(string& s)//ȫ�������swap���������Ҫ�������ο�����һ����������˵���дһ����Ա����
		//Ϊ�˷�ֹʹ��ȫ��ģ��swap;������д��һ��ר�ŵ�void swap(string& a,string& b)
	    //���ʹ�õ�ʱ���������ƥ���;(ģ��֪ʶ);
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
			const char* p=strstr(_str+pos, sub);//��һ���ַ�����Ѱ����һ���ַ���
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
		//һ���򵥵ĵ�����;
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
		{//�õ��ǵ����������Բ���Ҫ����˽�г�Ա���Բ���Ҫ����Ԫ��
			out << ch;
		}
		return out;
	}
	std::istream& operator>>(std::istream& in, string& s)
	{
		s.clear();//��ֹԭ�������ݣ�����Ӧ�����������
		char ch;
		ch=in.get();//ʵ����in�Ƕ��������кͿո�ģ���ֱ�Ӻ��Ե�
		//����ֱ����in�Ļ��ᵼ���޷���ѭ������ѭ��������Ҫ��in.get(),�൱��getchar;
		while (ch != ' ' && ch != '\n')
		{
			s += ch; ch=in.get();
		}
		return in;
	}
	void swap(string& x, string& y)
	{
		x.swap(y);//Ϊ�˷�ֹ����ȫ��
	}
	std::istream& getline(std::istream& in, string& s)
	{
		s.clear();//��ֹԭ�������ݣ�����Ӧ�����������
		char ch;
		ch = in.get();//ʵ����in�Ƕ��������кͿո�ģ���ֱ�Ӻ��Ե�
		size_t i = 0;
		char buff[128];
		//����ֱ����in�Ļ��ᵼ���޷���ѭ������ѭ��������Ҫ��in.get(),�൱��getchar;
		while (ch != '\n')//���ǲ��ϵ�+=�ᵼ�¶�����ݣ������ܴ�;
		{//����������buff�����ݴ������٣�������С;
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
