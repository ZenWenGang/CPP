#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.h"

namespace zwg
{
	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		//v.push_back(5);

		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		print_container(v);
		v.insert(v.begin() + 2, 30);
		print_container(v);
	}
	void test_vector3()
	{
		//TestVectorExpand();

		vector<int> v(10, 1);
		v.reserve(20);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.resize(15, 2);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.resize(25, 3);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.resize(5);
		cout << v.size() << endl;
		cout << v.capacity() << endl;
	}
	void test_vector4()
	{
		vector<int> v(10, 1);
		v.push_back(2);
		v.insert(v.begin(), 0);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.insert(v.begin() + 3, 10);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v1(5, 0);
		for (size_t i = 0; i < 5; i++)
		{
			cin >> v1[i];
		}

		for (auto e : v1)
		{
			cout << e << ",";
		}
		cout << endl;
	}
	void test_vector5()
	{
		vector<string> v1;
		string s1("xxxxx");
		v1.push_back(s1);
		v1.push_back("yyyyy");
		for (const auto& e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v5(10);
		print_container(v5);

		vector<int> v6(10,1);
		print_container(v6);
	}
	void test_vector6()
	{
		vector<string> v;
		v.push_back("11111111111111111111");
		v.push_back("11111111111111111111");
		v.push_back("11111111111111111111");
		v.push_back("11111111111111111111");
		print_container(v);

		v.push_back("11111111111111111111");
		print_container(v);
	}
}

int main()
{
	zwg::test_vector5();
	return 0;
}
