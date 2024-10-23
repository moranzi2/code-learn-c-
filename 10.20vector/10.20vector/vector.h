#pragma once
#include<iostream>
namespace bit
{
	//vectorʵ���Ͼ���һ��˳���Ҳ����һ��������ɾ������;
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
			reserve(v.capacity());//��reserve�����ٿ��ռ䣬����;
			for (auto& e : v)
			{
				push_back(e);
			}
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v, *this);//��Ϊ�Ǵ�ֵ���Զ�������һ����ʱ����;
			return *this;
		}
		void swap(vector<T>& v)
		{
			//��ΪĬ�����Ⱦͽ�ԭ���ң�����Ҫ��std::
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
			return _start;//�����Ǵ�ֵ���أ�Ҳ���Ƿ�����һ����ʱ�����������ʱ�������ھ�̬����
			//���ܸı�
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
		void push_back(const T& val)//���ܴ�ֵ�������string�Ļ�����̫��;��ֹ�ı䣬��const
		{
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				T* tmp = new T[newcapacity];
				memcpy(tmp, _start, size() * sizeof(T));	
				//�����ڴ����±���֮��Ҫ��memcpy���и�ֵ
				//��Ϊ������������Զ������ͣ��ᵼ��ǳ���������⣬�Ӷ����¶�������
				//�����forѭ�����б�����ֵ����ֵ���Զ������Զ������͵Ŀ������죬�������
				delete[] _start;//����ᵼ�µ�����ʧЧ
				_finish = tmp + size();//�ȼ���finish����Ϊsize�Ǹ���finish��start��ģ������ȱ�start
				_start = tmp;
				_end_of_storage = tmp + newcapacity;
			}
			*_finish = val;
			++_finish;
		}	
    void insert(iterator pos, const T& val)
		{//�������ûᵼ�����ⲿ������ʧЧ�������õ����޷�������ʱ���󣨳��ԣ�
		    //����Ҫ�ǵ�insert֮����ܾͱ��Ұָ���ˣ����ⲿ�������Ѿ���������;
			//���ݼǵ�Ҫ����pos(��ֹ���������ڲ�ʧЧ)
		}
	void reserve(size_t n)
	{
	}
	void resize(size_t n, const T& val = T())//�޲�����������Ϊ��Ҫȱʡֵ,������T();
		//��Ϊc++�Ķ�������������Ҳ�����ˣ������˹��캯������int j=int();int k=int(2);
	{
		if (n > size())
		{
			/*reserve(n);*/
			//����
		}
		else
		{
			//ɾ��
			_finish = _start + n;
		}
	}
	private:
		iterator _start=nullptr;
		iterator _finish=nullptr;
		iterator _end_of_storage = nullptr;
	};
}
