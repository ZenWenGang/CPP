#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include<functional>
#include<deque>


namespace bit
{
    //·Âº¯Êý
    template<class T>
    class less
    {
    public:
        bool operator()(const T& x, const T& y)
        {
            return x <y;
        }
    };

    template <class T, class Container=vector<T>, class compare = less<T> >
    class priority_queue
    {

    public:

        priority_queue() = default;

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
        {
            for (auto& e : first)
            {
                cout << *e << " ";
            }
            cout << endl;
        }

        void AdjustUP(int child)
        {
            compare com;
            int parent = (child - 1) / 2;
            while (child > 0)
            {
                if (com(c[parent], c[child]))
                {
                    swap(c[parent], c[child]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    break;
                }
            }
        }

        void AdjustDown(int parent)
        {
            size_t child = parent * 2 + 1;
            compare com;
            while (child < c.size())
            {
                if (child + 1 < c.size() && com(c[child], c[child + 1]))
                {
                    ++child;
                }
                if (com(c[parent], c[child]))
                {
                    swap(c[child], c[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }

        bool empty() const
        {
            return c.empty();
        }

        size_t size() const
        {
            return c.size();
        }

        const T& top()
        {
            return c[0];
        }

        void push(const T& x)
        {
            c.push_back(x);
            AdjustUP(c.size() - 1);
        }

        void pop()
        {
            swap(c[0], c[c.size() - 1]);
            c.pop_back();
            AdjustDown(0);
        }

    private:

        Container c;


    };
    void test_Pqueue()
    {
        priority_queue<int> p1;
        p1.push(1);
        p1.push(3);
        p1.push(5);
        p1.push(2);
        p1.push(4);
        while (!p1.empty())
        {
            cout << p1.top()<<" ";
            p1.pop();
        }
        cout << endl;
    }
};
