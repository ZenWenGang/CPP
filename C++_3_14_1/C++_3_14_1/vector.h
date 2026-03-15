#pragma once
#include<iostream>
#include<assert.h>

using namespace std;
namespace zwg
{
	template<class T>
	class vector
	{
	public:
		//一些函数要用到迭代区间进行操作
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		
		//构造函数
		/*vector()//这样写也可以
		{}*/
		vector() = default;// C++11 强制生成默认构造
		
		//拷贝构造
		vector(const vector<T>& v)
		{
			reserve(v.size());//提前开好空间
			for (auto& e : v)
			{
				push_back(e);
			}
		}
		//清除数据
		void clear()
		{
			_finish = _start;
		}
		//析构函数
		~vector()
		{
			if (_start)
			{
				delete[] _start;//因为这三个指针指向同一块空间，释放一个就行
				_start = _finish = _end_of_storage = nullptr;//全部置空
			}
		}
		//尾删一个元素
		void pop_back()
		{
			assert(!empty());
			return --_finish;
		}

		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		//判空
		bool empty()
		{
			return _start == _finish;
		}
		//尾插
		void push_back(const T& n)
		{
			if (_finish==_end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity()*2);
			}
			*_finish = n;
			++_finish;
		}
		//迭代区间删除一个元素
		void erase(iterator pos)
		{
			assert(pos > _start);
			assert(pos <= _finish);
			iterator it = pos + 1;
			while (it != end())
			{
				*(it - 1) = *it;//用到了重载的=
				++it;
			}
			--_finish;
		}
		//迭代区间插入
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			//扩容
			if (_finish == _end_of_storage)
			{
				int len = pos - _start;//记住pos位置，防止扩容后pos位置丢失（迭代器失效问题：野指针）
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end>=pos) 
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		//赋值重载
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		//迭代器区间构造
		//类模板的成员函数还可以继续是函数模板	
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)//这里可以用<，但是为了支持更多容器（例如链表），还是使用！=靠谱一些
			{
				push_back(*first);
				++first;
			}
		}
		//n个val初始化
		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		//重载[]
		T& operator[](size_t n)
		{
			assert(n < size());
			return _start[n];
		}

		const T& operator[](size_t n)const
		{
			assert(n < size());
			return _start[n];
		}
		//预开辟空间
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[capacity() + n];				
				//memcpy(tmp, _start, sizeof(T) * old_size);//浅拷贝会有问题
				for (size_t i = 0; i < old_size; i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
				
				_start = tmp;
				_finish = tmp + old_size;
				_end_of_storage = tmp + n;
			}
		}
		//用n个数据初始化
		void resize(size_t n, T val = T())
		{
			if (n <size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}


	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};
	//vector的输出
	template<class T>
	void print_container(const vector<T>& v)
	{
		// 规定，没有实例化的类模板里面取东西，编译器不能区分这里const_iterator
		// 是类型还是静态成员变量
		typename vector<T>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}
