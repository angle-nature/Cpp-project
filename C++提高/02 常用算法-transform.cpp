#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int func(int val)
{
	return val + 10;
}

void print01(int val)
{
	cout << val << " ";
}

void test()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), print01);
	cout << endl;

	vector<int> v1;
	v1.resize(v.size()); //�ȿ��ٿռ�  ����ָ���ռ��С  �޷����˽�ȥ

	//�����߼���,������ v ���˵����� v1 ��,��ִ�� +10 �Ĳ���
	transform(v.begin(), v.end(), v1.begin(), func);

	for_each(v1.begin(), v1.end(), print01);
	cout << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}