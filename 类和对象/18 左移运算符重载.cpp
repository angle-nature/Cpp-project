#include<iostream>
using namespace std;

class Person
{
public:

	//���ó�Ա�������� ��������� p.operator(cout) �򻯰汾�� p<<cout
	//����һ�㲻���ó�Ա��������<<�����  �޷��� cout ���� << ���

	int m_A;
	int m_B;
};

//ֻ����ȫ�ֺ�������<<
ostream& operator<<(ostream& cout, Person p)  //cout���� ostream��  ��ֻ��һ�� ����Ҫ�� ����
{
	cout << "p.m_A= " << p.m_A << " p.m_B= " << p.m_B;
	return cout;  //����cout ��Ϊ�˿��Լ�����ӡ��������
}

void test01()
{
	Person p;

	p.m_A = 10;
	p.m_B = 20;

	cout << p << endl;
}

int main()
{
	test01();

	system("pause");

	return 0;
}