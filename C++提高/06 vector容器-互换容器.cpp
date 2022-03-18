#include<iostream>
using namespace std;
#include<vector>

ostream& operator<<(ostream& cout, vector<int>& v)
{
	for (int i=0;i<v.size();i++)
	{
		cout << v[i] << " ";
	}
	return cout;
}

//vector容器的互换操作
void test01()
{
	vector<int>v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "交换前：" << endl;
	cout << v1 << endl;

	vector<int> v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	cout << v2 << endl;

	cout << "交换后：" << endl;
	v1.swap(v2);

	cout << v1 << endl;
	cout << v2 << endl;
}

//2、实际用途
//巧用swap可以收缩内存空间
void test02()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	v.resize(3); //重新指定大小
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	//巧用swap收缩内存
	//vector<int>(v) 是匿名对象 将v的大小拷贝到一个匿名对象中 然后与v进行交换 匿名对象在此行运行完后系统自动回收
	vector<int>(v).swap(v); 
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
}

int main()
{
	//test01();
	test02();

	system("pause");

	return 0;
}