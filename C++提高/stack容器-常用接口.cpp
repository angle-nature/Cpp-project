#include<iostream>
using namespace std;
#include<stack>

//ջ�����ĳ��ýӿ�

void test()
{
	//����ջ���� ջ������������Ƚ����
	stack<int> s;

	//��ջ�����Ԫ�� ���� ѹջ/��ջ
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while (!s.empty())
	{
		//���ջ��Ԫ��
		cout << "ջ��Ԫ��Ϊ��" << s.top() << endl;

		//����ջ��Ԫ��
		s.pop();
	}
	cout << "ջ�Ĵ�СΪ��" << s.size() << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}