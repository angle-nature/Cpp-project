#include<iostream>
using namespace std;
#include<vector>
#include<functional>
#include<algorithm>

//�ڽ��������� �����º���

void test()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);

	sort(v.begin(), v.end()); //Ĭ������

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//STL�ڽ��º��� ���ڷº��� greater<T>()
	sort(v.begin(), v.end(), greater<int>());  //����

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}