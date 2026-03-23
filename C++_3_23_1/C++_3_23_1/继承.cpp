#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
////Person类
//class Person
//{
//public:
//	//构造
//	Person()
//	{
//		cout << "Person构造" << endl;
//	}
//	//析构
//	~Person()
//	{
//		cout << "Person析构" << endl;
//	}
//	
//private:
//	int _age = 18;//年龄
//};
////学生类
//class Student :public Person
//{
//public:
//	//构造
//	Student()
//	{
//		cout << "Student构造" << endl;
//	}
//	//析构
//	~Student()
//	{
//		cout << "Student析构" << endl;
//	}
//protected:
//	int _stuid;//学号
//};

//int main()
//{
//	Student s;
//	return 0;
//}

//// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是⾮常容易混淆
//class Person
//{
//protected:
//	int _num = 111;// ⾝份证号
//	string _name = "王彪"; // 姓名
//};
//
//class Student : public Person
//{
// public:
//	void Print()
//	{
//		cout << " 姓名:"<<_name<< endl;
//		cout << " 身份证号: "<<Person::_num<< endl;
//		cout << " 学号: "<<_num<<endl;
//	}
// protected:
//	int _num = 999; // 学号
//};
//int main()
//{
//	Student s1;
//	s1.Print();
//	return 0;
//};

class A
{
  public:
  void fun()
  {
     cout << "func()" << endl;
  } 
};

class B : public A
{
public:
	void fun(int i)
	{
		cout << "func(int i)" << i << endl;
	}
};
int main()
{
	B b;
	b.fun(10);
	b.A::fun();
	return 0;
};