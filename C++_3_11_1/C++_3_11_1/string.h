#pragma once
using namespace std;
#include<assert.h>
#include<iostream>
namespace bit
{

    class string
    {
     public:

        typedef char* iterator;//迭代器
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }
        typedef const char* const_iterator;//迭代器
        const_iterator begin()const
        {
            return _str;
        }
        const_iterator end()const
        {
            return _str + _size;
        }
        string(const char* str = "")//析构
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        string(const string& s)//拷贝构造
        {
            _str = new char[s._capacity + 1];
            strcpy(_str, s._str);
            _size = s._size;
            _capacity = s._capacity;
        }

        string& operator=(const string& s)
        {
            if (this !=&s)
            {
                delete[] _str;
                _str = new char[s._capacity + 1];
                strcpy(_str, s._str);
                _size = s._size;
                _capacity = s._capacity;
            }
            return *this;
        }

        ~string()//析构
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        // modify

        void push_back(char c)
        {
            if (_size == _capacity)
            {
                reserve(_capacity==0?4:2*_capacity);
            }
            _str[_size] = c;
            ++_size;
            _str[_size] = '\0';
        }

        string& operator+=(char c)
        {
            push_back(c);
            return *this;
        }

        void append(const char* str)
        {
            size_t len = strlen(str);
            if (_size + len > _capacity)
            {
                reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
            }
            strcpy(_str, str);
            _size += len;
        }

        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }

        void swap(string& s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }

        const char* c_str()const
        {
            return _str;
        }

        // capacity

        size_t size()const
        {
            return _size;
        }

        size_t capacity()const
        {
            return _capacity;
        }

        bool empty()const
        {
            return !(_size == 0);
        }

        void resize(size_t n, char c = '\0');

        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char* tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }

        // access

        char& operator[](size_t index)
        {
            assert(index < _size);
            return _str[index];
        }

        const char& operator[](size_t index)const
        {
            assert(index < _size);
            return _str[index];
        }

        //relational operators

        bool operator<(const string& s)
        {
            return strcmp(this->c_str(), s.c_str())<0;
        }

        bool operator<=(const string& s)
        {
            return !(*this > s);
        }

        bool operator>(const string& s)
        {
            return !(*this <= s);
        }

        bool operator>=(const string& s)
        {
            return !(*this < s);
        }

        bool operator==(const string& s)
        {
            return strcmp(this->c_str(), s.c_str())== 0;
        }

        bool operator!=(const string& s)
        {
            return !(*this== s);
        }



        // 返回c在string中第一次出现的位置

        size_t find(char c, size_t pos = 0) const
        {
            assert(pos < _size);
            for (size_t i = pos; i < _size; i++)
            {
                if (_str[i] == c)
                {
                    return i;
                }
            }
            return npos;
        }

        // 返回子串s在string中第一次出现的位置

        size_t find(const char* s, size_t pos = 0) const
        {
            assert(pos < _size);
            const char* ptr = strstr(_str + pos, s);
            if (ptr == nullptr)
            {
                return npos;
            }
            else
            {
                return ptr - _str;
            }
        }

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置

        string& insert(size_t pos, char c)
        {
            assert(pos <= _size);
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : 2 * _capacity);
            }
            _str[pos] = c;
            ++_size;
            return *this;
        }

        string& insert(size_t pos, const char* str)
        {
            assert(pos <= _size);
            size_t len = strlen(str);
           
            if (len + _size > _capacity)
            {
                reserve(len + _size > 2 * _capacity ? len + _size : 2 * _capacity);
            }
            size_t end = pos + _size;
            while (end > pos + len - 1)
            {
                _str[end] = _str[end - len];
                --end;
            }
            for (size_t i = 0; i < len; i++)
            {
                _str[pos + i] = str[i];
            }
            _size += len;
            return *this;
        }


        // 删除pos位置上的元素，并返回该元素的下一个位置

        string& erase(size_t pos, size_t len)
        {
            assert(pos<_size);
            if (len >= pos - _size)
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                for (size_t i = pos + len; i <= _size; i++)
                {
                    _str[i - len] = _str[i];
                }
                _size -= len;
            }
            return *this;
        }

     private:

        char* _str = nullptr;

        size_t _capacity = 0;

        size_t _size = 0;

        static const size_t npos;
    };

    const size_t string::npos = -1;
    ostream& operator<<(ostream& _cout, const string& s)
    {
        for (auto ch :s)
        {
            _cout << ch;
        }
        return _cout;
    }
    istream& operator>>(istream& _cin, string& s)
    {
        s.clear();
        char ch;
        ch = _cin.get();
        while (ch != ' ' && ch != '\n')
        {
            ch = _cin.get();
        }
        return _cin;
    }
}