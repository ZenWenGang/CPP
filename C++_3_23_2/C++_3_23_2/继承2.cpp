#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//
//class Student;//前置声明
//
//class Person
//{
//public:
//	//友元关系不能被继承
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name="张三";//姓名
//};
//
//class Student :public Person
//{
//	friend void Display(const Person& p, const Student& s);//声明为派生类友元，才能访问_stuNum
//protected:
//	int _stuNum=123456;//学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;//可访问基类成员
//	cout << s._stuNum << endl;//可访问派生类成员（已声明为友元）
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//	return 0;
//}

//class Person
//{
//protected:
//	string _name;
//	string _sex;
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	int _NO;//学号
//};
//
//int main()
//{
//	Student sobj;
//	//1.派生类对象->基类指针/引用/对象（合法）
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	Person pobj = sobj;//调用基类拷贝构造完成切片
//
//	//2.基类对象->派生类对象（非法，编译报错）
//	//sobj=pobj;
//	return 0;
//}


//基类
class Person
{
public:
	string _name;
};

//派生类1:Student
class Student :public Person
{
protected:
	int _num;
};

//派生类2:Teacher
class Teacher :public Person
{
protected:
	int _id;//职工编号
};

//派生类3:Assistant(继承Student和Teacher)->菱形继承
class Assistant :public Student, public Teacher
{
protected:
	string _majorCourse;//主修课程
};

int















