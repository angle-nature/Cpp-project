#include<iostream>
using namespace std;

class Base1
{

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
	
};

//�����̳з�ʽ
class son1:public Base1
{
public:
	void func()
	{
		m_A = 10; //�����еĹ���Ȩ�޳�Ա ����������Ȼ�ǹ���Ȩ��
		m_B = 20; //�����еı���Ȩ�޳�Ա ����������Ȼ�Ǳ���Ȩ��
		//m_C = 30; //�����е�˽��Ȩ�޳�Ա ��������ʲ���
	}
};

//�����̳з�ʽ
class son2 :protected Base1
{
public:
	void func()
	{
		m_A = 10; //�����еĹ���Ȩ�޳�Ա �������б�ɱ���Ȩ��
		m_B = 20; //�����еı���Ȩ�޳�Ա ����������Ȼ�Ǳ���Ȩ��
		//m_C = 30; //�����е�˽��Ȩ�޳�Ա ��������ʲ���
	}
};

//˽�м̳з�ʽ
class son3 :private Base1
{
public:
	void func()
	{
		m_A = 10; //�����еĹ���Ȩ�޳�Ա �������б��˽��Ȩ��
		m_B = 20; //�����еı���Ȩ�޳�Ա �������б�Ϊ˽��Ȩ��
		//m_C = 30; //�����е�˽��Ȩ�޳�Ա ��������ʲ���
	}
};

int main()
{
	system("pause");

	return 0;
}