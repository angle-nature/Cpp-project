#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//普通函数
void print01(int val)
{
	cout << val <<" ";
}

//仿函数
class print02
{
public:
	void operator()(int val)
	{
		cout << val <<" ";
	}
};

void test()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);

	//遍历算法
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	for_each(v.begin(), v.end(), print02());
	cout << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}