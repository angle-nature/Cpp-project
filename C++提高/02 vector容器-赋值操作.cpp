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

//vector��ֵ
void test()
{
	vector<int>v1; //Ĭ�Ϲ��� �޲ι���

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << v1<<endl;

	//operator= ��ֵ
	vector<int> v2 = v1;
	cout << v2<<endl;

	//assign
	vector<int> v3;
	v3.assign(v1.begin(), v1.end()); //ǰ�պ�
	cout << v3<<endl;

	//n��elem��ʽ��ֵ
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