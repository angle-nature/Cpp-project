#include<iostream>
using namespace std;

//���캯���ķ��༰����
//����
//���������� �޲ι��죨Ĭ�Ϲ��죩�� �вι���
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


	int m_age=0;
};

//����
void test()
{
	//1�����ŷ�
	Person p1;      //Ĭ�Ϲ��캯���ĵ���
	Person p2(10);  //�вι��캯���ĵ���
	Person p3(p1);  //�������캯���ĵ���

	//ע���������Ĭ�Ϲ��캯��ʱ�����ܼ����� ��p1()������������Ϊ���Ǻ�������
	//����  Person p()��  

	//2����ʾ��
	Person p01;
	Person p02 = Person(10);  //�вι��캯��
	Person p03 = Person(p01); //�������캯��

	//Person(10); //�������� �ص㣺��ǰִ�н�����ϵͳ���������յ���������

	//ע�����
	//��Ҫ���ÿ������캯����ʼ���������� ����������Ϊ Person��p03��===Person p3��
	//Person(p03);

	//3����ʽת����
	Person p4 = 10; //�൱��д�� Person p4=Person(10);
	Person p5 = p4; //�൱��д�� Person p5=Person(p4);
}

int main()
{
	test();

	system("pause");

	return 0;
}