#include<iostream>
using namespace std;

class Person
{
public:

	//thisָ��ı��� �� ָ�볣�� ��Ϊthis ��ָ����ó�Ա�����Ķ���� ָ�򲻿��޸�  �ȼ���  Person * const this
	//��Ա����������� const ���ε���thisָ��  �ȼ���  const Person * const this  ָ��ָ���ֵ�����ɸı�
	void showPerson() const    //������
	{
		//this->m_A = 100;
		this->m_B = 200;
	}

	int m_A;
	mutable int m_B; //������� ��ʹ�ڳ������� Ҳ�����޸����ֵ ���Ϲؼ���mutable
	
};

void test01()
{
	Person p;
	p.showPerson();
}

void test02()
{
	const Person p;  //�ڶ���ǰ��const����ɳ�����
	//p.m_A = 100;  �����޸�
	p.m_B = 200;    //������� ���޸�

	//������ֻ�ܵ��ó����� ��Ϊ���������ܻ��޸���ͨ������ֵ ���������ǲ����޸���ͨ��Ա������ֵ��
	p.showPerson();
}

int main()
{
	test01();
	test02();

	system("pause");

	return 0;
}