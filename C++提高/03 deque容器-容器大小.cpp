#include<iostream>
using namespace std;
#include<deque>

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it < d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//vector�����������ʹ�С����
void test()
{
	deque<int>d1;

	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty())
	{
		cout << "d1Ϊ��" << endl;
	}
	else
	{
		cout << "d1��Ϊ��" << endl;
		cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
		//deque����û�������ĸ���
	}

	//����ָ����С
	d1.resize(15);
	//d1.resize(15,100); //Ҳ��������resize���ذ汾��ָ�����ֵ����2��100��
	printDeque(d1); //�������ָ���ı�ԭ���ĳ��ˣ�Ĭ����0����µ�λ��

	d1.resize(5);
	printDeque(d1); //�������ָ���ı�ԭ���Ķ��ˣ����������Զ�ɾ��
}

int main()
{
	test();

	system("pause");

	return 0;
}