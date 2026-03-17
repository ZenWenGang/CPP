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

		list_node(const T& data = T())
			:_data(data),
			_next(nullptr),
			_prev(nullptr) {
		}
	};
	//迭代器
	template<class T>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T> Self;
		Node* _node;

		list_iterator(Node* node)
			:_node(node) {
		}

		T& operator*()
		{
			return _node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator!=(const Self& s)const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s)const
		{
			return _node == s._node;
		}
	};
	//链表整体
	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T> iterator;

		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		size_t size()const
		{
			return _size;
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}


		void pop_back(iterator pos)
		{
			erase(--end());
		}

		void pop_front(iterator pos)
		{
			erase(begin());
		}

		void erase(iterator pos)
		{
			assert(pos != end());

			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			--_size;
		}

		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;
			++_size;
		}

		bool empty()const
		{
			return _size == 0;
		}

	private:
		Node* _head;
		size_t _size;
	};

}
