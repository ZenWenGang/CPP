#pragma once
#include<iostream>
#include<vector>
using namespace std;

enum State
{
    EXIST,//存在
    EMPTY,//空
    DELETE//删除
};

template<class K, class V>
struct HashData
{
    pair<K, V> _kv;
    State _state = EMPTY;
};

//key转成整形的虚函数
template<class K>
struct HashFunc
{
    size_t operator()(const K& key)
    {
        return (size_t)key;
    }
};
//特化后的string转整形的虚函数
template<>
struct HashFunc<string>
{
    size_t operator()(const string& s)
    {
        //BKDR算法
        size_t hash = 0;
        for (auto ch : s)
        {
            hash += ch;
            hash *= 131;
        }
        return hash;
    }
};
inline unsigned long  __stl_next_prime(unsigned long n)
{
    static const int   __stl_num_primes = 28;
    static const unsigned long  __stl_prime_list[__stl_num_primes] =
    {
        53, 97, 193, 389, 769, 1543, 3079, 6151, 12289,
        24593, 49157, 98317, 196613, 393241, 786433, 
        1572869, 3145739,6291469, 12582917, 25165843,
        50331653, 100663319,201326611, 402653189, 
        805306457, 1610612741, 3221225473, 4294967291
    };

    const unsigned long* first = __stl_prime_list;
    const unsigned long* last = __stl_prime_list + __stl_num_primes;
    const unsigned long* pos = lower_bound(first, last, n);
    return pos == last ? *(last - 1) : *pos;
}
namespace open_address
{
 
    template<class K,class V,class Hash=HashFunc<K>>
    class HashTable
    {
    public:
        HashTable()
            :_tables(__stl_next_prime(0))
            ,_n(0)
        { }

        bool Insert(const pair<K, V>& kv)
        {
            //不插入重复值
            if (Find(kv.first))
                return false;
            //负载因子>=0.7就扩容
            if (_n*10/_tables.size()>=7)
            {
                HashTable<K, V, Hash> newht;
                newht._tables.resize(__stl_next_prime(_tables.size() + 1));
                for (auto& data : _tables)
                {
                    //旧表数据映射到新表
                    if (data._state == EXIST)
                    { 
                        newht.Insert(data._kv);
                    }
                }
                _tables.swap(newht._tables);
            }
            Hash hash;
            size_t hash0 = hash(kv.first) % _tables.size();
            size_t hashi = hash0;
            size_t i = 1;
            while (_tables[hashi]._state == EXIST)
            {
                //线性探测找空位
                hashi = (hash0 + i) % _tables.size();
                ++i;
            }
            _tables[hashi]._kv = kv;
            _tables[hashi]._state = EXIST;
            ++_n;
            return true;
        }

        HashData<K, V>* Find(const K& key)
        {
            Hash hash;
            size_t hash0 = hash(key) % _tables.size();
            size_t hashi = hash0;
            size_t i = 1;
            while (_tables[hashi]._state != EMPTY)
            {
                if (_tables[hashi]._statr == EXIST
                    && _tables[hashi])
                {
                    return &_tables[hashi];
                }
                //线性探测
                hashi = (hash0 + i) % _tables.size();
                ++i;
            }
            return nullptr;
        }

        bool Erase(const K& key)
        {
            HashData<K, V>* ret = Find(key);
            if (ret)
            {
                ret->_state = DELETE;
                return true;
            }
            else
            {
                return false;
            }
        }

    private:
        vector<HashData<K, V>> _tables;
        size_t _n;//记录数据个数
    };
}

namespace hash_bucket
{
    template<class T>
    struct HashNode
    {
        T _data;
        HashNode<T>* _next;

        HashNode(const T& data)
            :_data(data)
            ,_next(nullptr)
        { }
    };
    //前置声明，以防编译器找不到
    template<class K,class T,class KeyOfT,class Hash>
    class HashTable;

    template<class K,class T,class Ref,class Ptr,class KeyOfT,class Hash>
    //迭代器部分
    struct HTIterator
    {
        typedef HashNode<T> Node;
        typedef HashTable<K, T, KeyOfT, Hash> HT;
        typedef HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;

        Node* _node;//
        const HT* _ht;//
        
        HTIterator(Node* node,const HT* ht)
            :_node(node)
            ,_ht(ht)
        { }
        Ref operator*()
        {
            return _node->_data;
        }
        Ptr operator->()
        {
            return &_node->_data;
        }
        bool operator!=(const Self&s)
        {
            return _node != s._node;
        }

        Self& operator++()
        {
            if (_node->_next)
            {
                //当前桶还有数据，走到当前桶下一个节点
                _node = _node->_next;
            }
            else
            {
                //当前桶走完了，找下一个不为空的桶
                KeyOfT kot;
                Hash hash;
                size_t hashi = hash(kot(_node->_data)) % _ht->_tables.size();
                ++hashi;
                while (hashi < _ht->_tables.size())
                {
                    _node = _ht->_tables[hashi];
                    if (_node)
                        break;
                    else
                        ++hashi;
                }
                //走完所有桶
                if (hashi == _ht->_tables.size())
                {
                    _node = nullptr;
                }
            }
            return *this;
        }
    };

    template<class K,class T,class KeyOfT,class Hash>
    class HashTable
    {
        template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
        friend struct HTIterator;

        typedef HashNode<T> Node;
    public:
        typedef HTIterator<K, T, T&, T*, KeyOfT, Hash>Iterator;
        typedef HTIterator<K, T, const T&, const T*, KeyOfT, Hash>ConstIterator;

        Iterator Begin()
        {
            if (_n == 0)
                return End();
            for (size_t i = 0; i < _tables.size(); i++)
            {
                Node* cur = _tables[i];
                if (cur)
                {
                    return Iterator(cur, this);
                }
            }
            return End();
        }

        Iterator End()
        {
            return Iterator(nullptr, this);
        }

        ConstIterator Begin() const
        {
            if (_n == 0)
                return End();

            for (size_t i = 0; i < _tables.size(); i++)
            {
                Node* cur = _tables[i];
                if (cur)
                {
                    return ConstIterator(cur, this);
                }
            }

            return End();
        }

        ConstIterator End() const
        {
            return ConstIterator(nullptr, this);
        }

        HashTable()
            :_tables(__stl_next_prime(0))
            , _n(0)
        { }

        ~HashTable()
        {
            for (size_t i = 0; i < _tables.size(); i++)
            {
                Node* cur = _tables[i];
                while (cur)
                {
                    Node* next = cur->_next;
                    delete cur;
                    cur = next;
                }
                _tables[i] = nullptr;
            }
        }

        pair<Iterator, bool> Insert(const T& data)
        {
            KeyOfT kot;
            Iterator it = Find(kot(data));
            if (it != End())
                return { it,false };

            Hash hash;
            //负载因子==1时扩容
            if (_n == _tables.size())
            {
                vector<Node*> newTable(__stl_next_prime(_tables.size() + 1));
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    Node* cur = _tables[i];
                    while (cur)
                    {
                        Node* next = cur->_next;
                        //头插到新表
                        size_t hashi = hash(kot(cur->_data)) % newTable.size();
                        cur->_next = newTable[hashi];
                        newTable[hashi] = cur;
                        cur = next;
                    }
                    _tables[i] = nullptr;
                }
                _tables.swap(newTable);
            }
            size_t hashi = hash(kot(data)) % _tables.size();
            //头插
            Node* newnode = new Node(data);
            newnode->_next = _tables[hashi];
            _tables[hashi] = newnode;
            ++_n;

            return { Iterator(newnode,this),false };
        }

        Iterator Find(const K& key)
        {
            KeyOfT kot;
            Hash hash;
            size_t hashi = hash(key) % _tables.size();
            Node* cur = _tables[hashi];
            while (cur)
            {
                if (kot(cur->_data) == key)
                {
                    return Iterator(cur, this);
                }
                cur = cur->_next;
            }
            return End();
        }

        bool Erase(const K& key)
        {
            KeyOfT kot;
            size_t hashi = key % _tables.size();
            Node* prev = nullptr;
            Node* cur = _tables[hashi];
            while (cur)
            {
                if (kot(cur->_data) == key)
                {
                    if (prev == nullptr)
                    {
                        _tables[hashi] = cur->_next;
                    }
                    else
                    {
                        prev->_next = cur->_next;
                    }
                    delete cur;
                    --_n;
                    return true;
                }
                else
                {
                    prev = cur;
                    cur = cur->_next;
                }
            }
            return false;
        }
    private:
        vector<Node*> _tables;//指针数组
        size_t _n = 0;
    };
}

