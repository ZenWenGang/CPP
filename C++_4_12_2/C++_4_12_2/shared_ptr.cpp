#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

struct Date
{
	int _year;
	int _month;
	int _day;
	Date(int year=1, int month=1, int day=1)
		:_year(year)
		,_month(month)
		,_day(day)
	{ }
	~Date()
	{
		cout << "~Date()" << endl;
	}
};
namespace myptr
{
    template<class T>
    class shared_ptr
    {
    public:
        shared_ptr(T* ptr)
            : _ptr(ptr)
            , _pcount(new atomic<int>(1))
        {}

        template<class D>
        shared_ptr(T* ptr, D del)
            : _ptr(ptr)
            , _pcount(new atomic<int>(1))
            , _del(del)
        {}

        ~shared_ptr()
        {
            if (--(*_pcount) == 0)
            {
                //delete _ptr;
                _del(_ptr);
                delete _pcount;
            }
        }

        shared_ptr(const shared_ptr<T>& sp)
            : _ptr(sp._ptr)
            , _pcount(sp._pcount)
        {
            (*_pcount)++;
        }

        shared_ptr<T>& operator=(const shared_ptr<T>& sp)
        {
            //if (this != &sp)
            if (_ptr != sp._ptr)
            {
                if (--(*_pcount) == 0)
                {
                    delete _ptr;
                    delete _pcount;
                }

                _pcount = sp._pcount;
                _ptr = sp._ptr;
                ++(*_pcount);
            }

            return *this;
        }

        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

        int use_count()
        {
            return *_pcount;
        }
    private:
        T* _ptr;
        //int* _pcount;
        atomic<int>* _pcount;  // 原子操作
        function<void(T*)> _del = [](T* ptr) {delete ptr; };
    };
}
//int main()
//{
//	//构造
//    myptr::shared_ptr<Date> sp1(new Date);
//	// 拷贝构造
//	myptr::shared_ptr<Date> sp2(sp1);
//	myptr::shared_ptr<Date> sp3 = sp2;
//	//构造
//	myptr::shared_ptr<Date> sp4(new Date);
//    sp1->_year++;
//    sp3->_month++;
//
//    // 赋值拷贝
//   sp1 = sp4;
//  
//
//	return 0;
//}


// 仿函数删除器
template<class T>
class DeleteArray
{
public:
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

// 文件关闭删除器
class Fclose
{
public:
	void operator()(FILE* ptr)
	{
		cout << "fclose:" << ptr << endl;
		fclose(ptr);
	}
};
// 函数指针删除器
template<class T>
void DeleteArrayFunc(T* ptr)
{
	delete[] ptr;
}
//下面分别用库里的shared_ptr和unique_ptr来作样例
int main()
{
    std::shared_ptr<Date> sp1(new Date);
	std::unique_ptr<Date> up1(new Date);
	// 方法1：使用特化版本（针对new[]）
	std::unique_ptr<Date[]> up2(new Date[10]);
    std::shared_ptr<Date[]> sp2(new Date[10]);


    // 定制删除器 都可以，相对建议lambda
    std::shared_ptr<Date> sp3(new Date[10], [](Date* ptr) {delete[] ptr; });
    std::shared_ptr<Date> sp4(new Date[5], DeleteArrayFunc<Date>);

    std::shared_ptr<FILE> sp5(fopen("Test.cpp", "r"), Fclose());
    shared_ptr<FILE> sp6(fopen("Test.cpp", "r"), [](FILE* ptr) {
        //cout << "fclose:" << ptr << endl;
        fclose(ptr);
        });
 
    // 定制删除器 建议仿函数
    std::unique_ptr<FILE, Fclose> up3(fopen("Test.cpp", "r"));
    auto fcloseFunc = [](FILE* ptr) {fclose(ptr); };
    std::unique_ptr<FILE, decltype(fcloseFunc)> up4(fopen("Test.cpp", "r"), fcloseFunc);

    return 0;
}