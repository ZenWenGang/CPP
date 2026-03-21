#pragma once
#include<iostream>
#include<deque>
using namespace std;
namespace my
{
	template<class T,class container=std::deque<T>>
	class Stack
	{
		public:
			//构造函数
			Stack()=default;

			//访问
			T& top()
			{
				return _con.back();
			}
			const T& top()const
			{
				return _con.back();
			}

			//修改
			void push(const T& val)
			{
				return _con.push_back(val);
			}

			void pop()
			{
				return _con.pop_back();
			}
			//容量
			size_t size()const
			{
				return _con.size();
			}

			bool empty()const
			{
				return _con.empty();
			}
			//交换
			void swap(Stack& S)
			{
				std::swap(_con, S._con);
			}
	private:
		container _con;
	};
	void test_stack()
	{
		Stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);
		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
}
