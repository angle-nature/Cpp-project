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

//vector�����Ĳ����ɾ������
void test()
{
	vector<int>v1;

	//β��
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << v1 << endl;

	//βɾ
	v1.pop_back();  //ɾ�����һ��Ԫ��
	cout << v1 << endl;

	//���� ��һ�������ǵ�����
	v1.insert(v1.begin()+2, 100);
	cout << v1 << endl;

	v1.insert(v1.begin(), 2, 317);
	cout << v1 << endl;

	//ɾ�� ����Ҳ�ǵ�����
	v1.erase(v1.begin()+3);
	cout << v1 << endl;

	//����ɾ��
	v1.erase(v1.begin()+4, v1.end()-1);
	cout << v1 << endl;

	//���
	v1.clear();
	cout << v1 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}