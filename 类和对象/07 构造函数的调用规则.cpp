#include<iostream>
using namespace std;

//���캯���ĵ��ù���
//1������һ���࣬C++���������ÿ���඼���������������
//Ĭ�Ϲ��캯������ʵ�֣�
//�вι��캯������ʵ�֣�
//�������캯����ֵ������

//2��
//���д���вι��캯�����������򲻻��ṩĬ�Ϲ��캯��������Ȼ���ṩ�������캯��
//���д�˿������캯�����������򲻻��ṩ������ͨ���캯����
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

void test01()
{
	Person p1(10);  //�вι���
	Person p2(p1);  //��������

	cout << "P2������Ϊ��" << p2.m_age << endl;
}


void test02()
{
	Person p;  //Ĭ�Ϲ��죨�޲ι��죩
}


int main()
{
	//test01();
	//test02();

	system("pause");

	return 0;
}