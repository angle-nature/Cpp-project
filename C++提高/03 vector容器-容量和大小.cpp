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

//vector�����������ʹ�С����
void test()
{
	vector<int>v1; 

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << v1 << endl;

	if (v1.empty())
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ��" << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ��" << v1.size() << endl;
	}

	//����ָ����С
	v1.resize(15);
	//v1.resize(15,100); //Ҳ��������resize���ذ汾��ָ�����ֵ����2��100��
	cout << v1 << endl; //�������ָ���ı�ԭ���ĳ��ˣ�Ĭ����0����µ�λ��

	v1.resize(5);
	cout << v1 << endl; //�������ָ���ı�ԭ���Ķ��ˣ����������Զ�ɾ��
}

int main()
{
	test();

	system("pause");

	return 0;
}