#include<iostream>
using namespace std;

class Person
{
public:

	Person(int age)
	{
		//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
		this->age = age;
	}

	Person& PersonAddAge(Person p)  //�˴�һ��Ҫ���ض��������  ����Ὣ���ص�ֵ����һ���µĶ���  ������p2����
	{
		this->age += p.age;

		//thisָ��p2��ָ�룬*this��ָ��p2���������
		return *this;
	}

	int age;
};

//1��������Ƴ�ͻ
void test01()
{
	Person p(20);
	cout << "p������Ϊ��" << p.age << endl;
}

//2�����ض�������*this
void test02()
{
	Person p1(10);
	Person p2(10);

	//��ʽ���˼��
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);  // �ȼ��� p2.age=p2.age+p1.age+p1.age+p1.age;

	cout << "p2������Ϊ��" << p2.age << endl;
}

int main()
{
	//test01();
	test02();

	system("pause");

	return 0;
}