#include<iostream>
using namespace std;

//�����ǳ����
class Person
{
public:

	Person()
	{
		cout << "Person���޲ι��캯������" << endl;
	}

	Person(int a,int height)
	{
		m_age = a;
		m_Height = new int(height);    //����new���������ݣ��᷵�ظ����ݶ�Ӧ�����͵�ָ�� ���ڶ���

		cout << "Person���вι��캯������" << endl;
	}

	Person(const Person& p)
	{
		m_age = p.m_age;
		//m_Height=p.m_Height;   ����Ĭ�Ͽ�������д��ʵ��  ǳ����
		m_Height = new int(*p.m_Height);  //�ڶ�������һ���µĵ�ַ�����ܴ�������ֵ  ���

		cout << "Person�Ŀ������캯������" << endl;
	}

	//��������
	~Person()
	{
		//�������������ͷŶ���ռ�õ��ڴ�
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person��������������" << endl;
	}


	int m_age = 0;
	int* m_Height;
};

void test01()
{
	Person p1(20,180);  //�вι���

	cout << "P1������Ϊ��" << p1.m_age << "���Ϊ��" << *p1.m_Height << endl;

	Person p2(p1);  //��������

	cout << "P2������Ϊ��" << p2.m_age << "���Ϊ��" << *p2.m_Height << endl;

	//p1.m_Height �� p2.m_Height �ĵ�ַ��ͬ ��������������ʱ���ᷢ���ظ��ͷ�һ����ַ�Ĵ���
}


int main()
{
	test01();

	system("pause");

	return 0;
}