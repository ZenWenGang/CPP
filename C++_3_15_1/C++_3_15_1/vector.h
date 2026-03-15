#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
namespace bit

{
    template<class T>

    class vector

    {

    public:

        // Vector的迭代器是一个原生指针

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

        const_iterator end() const
        {
            return _finish;
        }



            // construct and destroy

        vector()
        { }

        vector(int n, const T& value = T())
        {
            reserve(n);
            for (int i = 0; i < n; i++)
            {
                push_back(value);
            }
        }

            template<class InputIterator>
            vector(InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    push_back(*first);
                    ++first;
                }
            }

            vector(const vector<T>& v)
            {
                reserve(v.size());
                for (auto e : v)
                {
                    push_back(v);
                }
            }

            vector<T>& operator= (vector<T> v)
            {
                swap(v);
                return *this;
            }

            ~vector()
            {
                assert(_finish != _start);
                delete[] _start;
                _start = _finish = _endOfStorage = nullptr;
            }

            // capacity

            size_t size() const
            {
                return _finish - _start;
            }

            size_t capacity() const
            {
                return _endOfStorage - _start;
            }

            void reserve(size_t n)
            {
                if (n > capacity())
                {
                    int oldsize = size();
                    T* tmp = new T[capacity() + n];
                    for (int i = 0; i < oldsize; i++)
                    {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                    _start = tmp;
                    _finish = tmp + oldsize;
                    _endOfStorage = tmp + n;
                }
            }

            void resize(size_t n, const T& value = 0)
            {
                if (n < size())
                {
                    _finish = _start + n;
                }
                else
                {
                    reserve(n);
                    while (_finish < _start + n)
                    {
                        *_finish = value;
                        ++_finish;
                    }
                }
            }



            ///////////////access///////////////////////////////

            T& operator[](size_t pos)
            {
                return _start[pos];
            }

            const T& operator[](size_t pos)const
            {
                return _start[pos];
            }


                ///////////////modify/////////////////////////////

            void push_back(const T& x)
            {
                if (_finish == _endOfStorage)
                {
                    reserve(capacity() == 0 ? 4 : capacity() * 2);
                }
                *_finish = x;
                ++_finish;
            }

            void pop_back()
            {
                return --_finish;
            }

            void swap(vector<T>& v)
            {
                std::swap(_start, v._start);
                std::swap(_finish, v._finish);
                std::swap(_endOfStorage, v._endOfStorage);
            }

            iterator insert(iterator pos, const T& x)
            {
                assert(pos <= _finish);
                assert(pos >= _start);
                if (_finish ==_endOfStorage)
                {
                    int len = pos - _start;
                    reserve(capacity() == 0 ? 4 : 2 * capacity());
                    pos = _start + len;
                }
                iterator end = _finish - 1;
                while (end >= pos)
                {
                    *(end + 1) = *end;
                    --end;
                }
                *pos = x;
                ++_finish;
                return pos;
            }

            iterator erase(iterator pos)
            {
                assert(pos >= _start);
                assert(pos <= _finish);
                iterator it = pos+1;
                while (it != end())
                {
                    *(it-1) =*it ;
                    ++it;
                }
                --_finish;
                return _start;
            }

    private:

        iterator _start=nullptr; // 指向数据块的开始

        iterator _finish=nullptr; // 指向有效数据的尾

        iterator _endOfStorage=nullptr; // 指向存储容量的尾

    };
    template<class T>
    void print_vector(const vector<T>& v)
    {
        typename vector<T>::const_iterator it = v.begin();
        while (it != v.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }
}