#include<iostream>
using namespace std;

//�������캯���ĵ���ʱ��
class Person
{
public:
	//���캯��
	Person()
	{
		cout << "Person���޲ι��캯������" << endl;
	}

	Person(int a)
	{
		m_age = a;
		cout << "Person���вι��캯������" << endl;
	}

	//�������캯��
	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "Person�Ŀ������캯������" << endl;
	}

	//��������
	~Person()
	{
		cout << "Person��������������" << endl;
	}


	int m_age = 0;
};

//1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01()
{
	Person p1(10);  //�вι���
	Person p2(p1);  //��������

	cout << "P2������Ϊ��" << p2.m_age << endl;
}

//2��ֵ���ݵķ�ʽ������������ֵ  ֵ����
void doWork(Person p)
{

}

void test02()
{
	Person p;  //Ĭ�Ϲ��죨�޲ι��죩
	doWork(p); //��������
}

//3��ֵ��ʽ���ؾֲ�����  ֵ����
Person doWork02()
{
	Person p;
	cout << (int*)&p << endl;
	return p;
}

void test03()
{
	Person p=doWork02();
	cout << (int*)&p << endl;
}

int main()
{
	//test01();
	//test02();
	test03();

	system("pause");

	return 0;
}