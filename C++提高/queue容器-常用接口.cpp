#include<iostream>
using namespace std;
#include<queue>

//ջ�����ĳ��ýӿ�

void test()
{
	//����ջ���� ջ������������Ƚ����
	queue<int> q;

	//����������Ԫ�� ��Ӳ���
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	//���в��ṩ������ ����֧���������
	while (!q.empty())
	{
		//�����ͷԪ��
		cout << "��ͷԪ��Ϊ��" << q.front() << endl;

		//�����βԪ��
		cout << "��βԪ��Ϊ��" << q.back() << endl;
		cout << endl;

		//������ͷԪ��
		q.pop();
	}

	cout << "���еĴ�СΪ��" << q.size() << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}