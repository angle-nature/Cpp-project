#include<iostream>
using namespace std;

class Person
{
public:

	//��̬��Ա����
	//���ж�����һ������
    //��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
	static void func01()
	{
		m_A = 100;
		//m_B = 20;  ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
		cout << "static void func01 �ĵ���" << endl;
	}

	//��̬��Ա����
	//���ж�����һ������
	//����׶ξͷ����ڴ�
	//���������������ʼ��
	static int m_A; 

	int m_B;
};

//��̬�������⸳��ֵ
int Person::m_A = 10;

void test01()
{
	Person p1;
	
	cout << p1.m_A << endl;

	Person p2;
	p2.m_A = 200;

	cout << p1.m_A << endl;  //p1��p2����һ������  �����200
}

//��̬��Ա����
void test02()
{
	//1��ͨ���������
	Person p;
	cout<<p.m_A<<endl;

	//2��ͨ����������
	cout << Person::m_A << endl;
}

//��̬��Ա����
void test03()
{
	//1��ͨ���������
	Person p;
	p.func01();

	//2��ͨ����������
	Person::func01();
}

int main()
{
	test01();
	test02();
	test03();

	system("pause");

	return 0;
}