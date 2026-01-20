#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A
{
public:
    A(int a = 0)
        :_a(a)
    {
        cout << "A(int a)" << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
private:
    int _a;
};
class Solution {
public:
    int Sum_Solution(int n) {
        //...
        return n;
    }
};
int main()
{
    A aa1;
    //A aa1();// 不能这么定义对象，因为编译器⽆法识别下⾯是⼀个函数声明，还是对象定义
        
    A(); // 匿名对象的⽣命周期只有这⼀⾏，下⼀⾏他就会⾃动调⽤析构函数
    A(1);// 但是我们可以这么定义匿名对象，匿名对象的特点不⽤取名字，
  
    Solution st;
    cout << st.Sum_Solution(10) << endl;

    cout << Solution().Sum_Solution(10) << endl; // 匿名对象在这样场景下就很好⽤
    return 0;
}