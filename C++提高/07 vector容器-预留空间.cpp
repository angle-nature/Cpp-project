#include<iostream>
using namespace std;
#include<vector>

//vector容器 预留空间
void test01()
{
	vector<int> v;

	//预留空间
	v.reserve(100000);

	int num = 0; //统计开辟次数
	int* p =NULL; //&v[0]=NULL

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << num << endl;
	
}

int main()
{
	test01();

	system("pause");

	return 0;
}