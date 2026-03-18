#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace zwg
{
	//链表节点
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& data=T())
			:_data(data)
			,_next(nullptr)
			,_prev(nullptr)
		{ }
	};
	//迭代器
	template<class T,class ref,class ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, ref, ptr> Self;
		Node* _node;
		
		list_iterator(Node* node)
			:_node(node)
		{}

		ref operator*()
		{
			return _node->_data;
		}

		ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator++()
		{
		    _node=_node->_next;
			return *this;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator==(const Self& s)const
		{
			return _node == s._node;
		}

		bool operator!=(const Self& s)const
		{
			return _node != s._node;
		}

	};

	//链表
	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T,const T&,const T*> const_iterator;
		
		list()
		{
			empty_init();
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		list(initializer_list<T> il)
		{
			empty_init();
			for (auto& e : il)
			{
				push_back(e);
			}
		}

		list(const list<T>& x)
		{
			empty_init();
			for (auto& e : x)
			{
				push_back(e);
			}
		}

		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void empty()
		{
			return _size == 0;
		}

		void insert(iterator pos, const T& x)
		{
			Node* newnode= new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;
			++_size;
		}

		iterator erase(iterator pos)
		{
			assert(pos!=end());
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete[] pos._node;
			--_size;

			return next;
		}

		list<T>& operator=(const list<T> x)
		{
			swap(x);
			return *this;
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front(const T& x)
		{
			erase(begin());
		}
		void pop_back(const T& x)
		{
			erase(--end());
		}
		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}
		

		void swap(const list<T>& x)
		{
			std::swap(_head, x._head);
			std::swap(_size, x._size);
		}
		const_iterator begin()const
		{
			return _head->_next;
		}

		const_iterator end()const
		{
			return _head;
		}

		size_t size()
		{
			return _size;
		}

	private:
		Node* _head;
		size_t _size;
	};

	//template<class container>
	//void print_container(const container& con)
	//{
	//	typename container::const_iterator it = con.begin();
	//	while (it != con.end());
	//	{
	//		cout << *it << " ";
	//	}
	//	cout << endl;
	//}
}