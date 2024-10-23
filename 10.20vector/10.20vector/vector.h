#pragma once
#include<iostream>
namespace bit
{
	//vector实际上就是一个顺序表，也就是一个可以增删的数组;
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
		{}
		vector(const vector<T>& v)
		{
			reserve(v.capacity());//先reserve可以少开空间，方便;
			for (auto& e : v)
			{
				push_back(e);
			}
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v, *this);//因为是传值，自动创建了一个临时变量;
			return *this;
		}
		void swap(vector<T>& v)
		{
			//因为默认是先就近原则找，所以要加std::
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
		const_iterator begin()const
		{
			return _start;//这里是传值返回，也就是返回了一个临时变量，这个临时变量是在静态区的
			//不能改变
		}
		const_iterator end()const
		{
			return _finish;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return *(_start + pos);
		}
		const T& operator[](size_t pos)const 
		{
			assert(pos < size());
			return *(_start + pos);
		}
		void push_back(const T& val)//不能传值，如果是string的话代价太大;防止改变，加const
		{
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				T* tmp = new T[newcapacity];
				memcpy(tmp, _start, size() * sizeof(T));	
				//这里在创建新变量之后不要用memcpy进行赋值
				//因为如果里面存的是自定义类型，会导致浅拷贝的问题，从而导致二次析构
				//最好用for循环进行遍历赋值，赋值会自动调用自定义类型的拷贝构造，进行深拷贝
				delete[] _start;//否则会导致迭代器失效
				_finish = tmp + size();//先加上finish，因为size是根据finish和start算的，不能先变start
				_start = tmp;
				_end_of_storage = tmp + newcapacity;
			}
			*_finish = val;
			++_finish;
		}	
    void insert(iterator pos, const T& val)
		{//不加引用会导致在外部迭代器失效，加引用导致无法调用临时对象（常性）
		    //所以要记得insert之后可能就变成野指针了，就外部迭代器已经不能用了;
			//扩容记得要更新pos(防止迭代器在内部失效)
		}
	void reserve(size_t n)
	{
	}
	void resize(size_t n, const T& val = T())//无参匿名对象，因为需要缺省值,所以用T();
		//因为c++改动，给内置类型也升级了，加上了构造函数，如int j=int();int k=int(2);
	{
		if (n > size())
		{
			/*reserve(n);*/
			//插入
		}
		else
		{
			//删除
			_finish = _start + n;
		}
	}
	private:
		iterator _start=nullptr;
		iterator _finish=nullptr;
		iterator _end_of_storage = nullptr;
	};
}
