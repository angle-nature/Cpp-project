#include<iostream>
using namespace std;

//public        ����Ȩ��  ���ڿ��Է��� ������Է���
//protected     ����Ȩ��  ���ڿ��Է��� ���ⲻ���Է���
//private       ˽��Ȩ��  ���ڿ��Է��� ���ⲻ���Է���   
//Ĭ��Ȩ��Ϊ˽��Ȩ��

class person
{
	string m_wife;
public:

	string m_name; //���� ����Ȩ��

protected:

	string m_car;  //���� ����Ȩ��

private:

	string m_passward;  //˽��Ȩ��

public:
	void showPerson()
	{
		m_name = "����";
		m_car = "��¿";
		m_passward = "123456";
	}
};

int main()
{
	person p;
	p.m_name = "����";        //������Է���

	//p.m_wife = "�绨";      //m_wifeĬ��Ϊ˽��Ȩ�� ������ⲻ�ɷ���
	//p.m_car = "����";       //���ⲻ�ɷ���
	//p.m_pssword = "000000"; //���ⲻ�ɷ���
	
	system("pause");
	return 0;
}