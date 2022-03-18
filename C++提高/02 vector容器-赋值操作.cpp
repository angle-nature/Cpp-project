#include<iostream>
using namespace std;
#include<vector>

ostream& operator<<(ostream& cout, vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << " ";
	}
	return cout;
}

//vector赋值
void test()
{
	vector<int>v1; //默认构造 无参构造

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << v1<<endl;

	//operator= 赋值
	vector<int> v2 = v1;
	cout << v2<<endl;

	//assign
	vector<int> v3;
	v3.assign(v1.begin(), v1.end()); //前闭后开
	cout << v3<<endl;

	//n个elem方式赋值
	vector<int> v4;
	v4.assign(10, 100);
	cout << v4 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}