#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//�º��� ����ֵ������bool�������� ��Ϊν��
//һԪν��

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//������������û�д���5������
	//GreaterFive() ��������������
	//find_if()�ķ���ֵ�ǵ�����
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ���һ������5������Ϊ��" << *it << endl;
	}
}

//��Ԫν��
class MyCompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

void test02()
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
		cout << *it <<" ";
	}
	cout << endl;

	sort(v.begin(), v.end(),MyCompare());  //����

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it <<" ";
	}
	cout << endl;
}

int main()
{
	//test01();

	test02();

	system("pause");

	return 0;
}