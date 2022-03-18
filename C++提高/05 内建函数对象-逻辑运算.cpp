#include<iostream>
using namespace std;
#include<vector>
#include<functional>
#include<algorithm>

//�߼��� logical_not

void test()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<bool> v1;
	v1.resize(v.size()); //�ȿ��ٿռ�  ����ָ���ռ��С  �޷����˽�ȥ

	//�����߼���,������ v ���˵����� v1 ��,��ִ���߼�ȡ������
	transform(v.begin(), v.end(), v1.begin(), logical_not<bool>()); 

	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
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