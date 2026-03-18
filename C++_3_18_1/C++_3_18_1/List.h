#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace bite
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
            :_pPre(nullptr)
            ,_pNext(nullptr)
            ,_val(val)
        { }

        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T> Node;
        typedef ListIterator<T, Ref, Ptr> Self;
        Node* _node;
        ListIterator(Node* pNode)
            :_node(pNode)
        { }

        Ref operator*()
        {
            return _node->_val;
        }
        Ptr operator->()
        {
            return &_node->_val;
        }
        Self& operator++()
        {
           _node=_node->_pNext;
            return *this;
        }
        Self operator++(int)
        {
            Self tmp( *this);
            _node = _node->_pNext;
            return tmp;
        }
        Self& operator--()
        {
            _node=_node->_pPre;
            return *this;
        }
        Self operator--(int)
        {
            Self tmp(*this);
            _node = _node->_pPre;
            return tmp;
        }
        bool operator!=(const Self& l)
        {
            return _node != l._node;
        }
        bool operator==(const Self& l)
        {
            return _node == l._node;
        }
    
    };


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造
        list()
        {
            CreateHead();
        }
      
     


        list(int n, const T& value = T())
        {
            CreateHead();
            for (size_t i = 0; i < n; i++)
            {
                push_back(value);
            }
        }
        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            while (first != last)
            {
                push_back(first);
                ++first;
            }
        }
        list(const list<T>& l)
        {
            CreateHead();
            for (auto e : l)
            {
                push_back(e);
            }
        }
        list<T>& operator=(const list<T> l)
        {
            swap(l);
            return *this;
        }
        ~list()
        {
            claer();
            delete _head;
            _head = nullptr;
            _size = 0;
        }
        void claer()
        {
            auto it = begin();
            while (it != end())
            {
                it = erase(it);
            }
        }

        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return _head->_pNext;
        }
        iterator end()
        {
            return _head;
        }
        const_iterator begin()const
        {
            return _head->_pNext;
        }
        const_iterator end()const
        {
            return _head;
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            return _size;
        }
        bool empty()const
        {
            return _size == 0;
        }


        ////////////////////////////////////////////////////////////
        // List Access
        T& front();
        const T& front()const;
        T& back();
        const T& back()const;


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) { insert(end(), val); }
        void pop_back() { erase(--end()); }
        void push_front(const T& val) { insert(begin(), val); }
        void pop_front() { erase(begin()); }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            Node* newnode = new Node(val);
            Node* cur = pos._node;
            Node* prev = cur->_pPre;

            newnode->_pNext = cur;
            cur->_pPre = newnode;
            newnode->_pPre = prev;
            prev->_pNext = newnode;
            ++_size;
            return newnode;
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            assert(pos != _head);
            iterator tmp = pos._node->_pNext;
            Node* cur = pos._node->_pNext;
            Node* prev = pos._node->_pPre;
            prev->_pNext = cur;
            cur->_pPre = prev;
            delete pos._node;
            --_size;

            return tmp;
        }
        void swap(list<T>& l)
        {
            std::swap(_head, l._head);
            std::swap(_size, l._size);
        }
        void CreateHead()
        {
            _head = new Node;
            _head->_pNext = _head;
            _head->_pPre = _head;
            _size = 0;
        }
    private:
        
        Node* _head;
        size_t _size;
    };
    template<class Container>
    void print_container(const Container& con)
    {  
        typename Container::const_iterator it = con.begin();
        while (it != con.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }
};
