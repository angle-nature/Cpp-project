#include<iostream>
using namespace std;

class student
{
public:    //����Ȩ��

	//���е����Ժ���Ϊͳһ��Ϊ��Ա
	//����  ��Ա����||��Ա����
	//��Ϊ  ��Ա����||��Ա����

	string m_name;  //��Ա����
	string m_ID;    //��Ա����

	void setName(string name)   //��Ա����
	{
		m_name = name;
	}

	void setId(string ID)
	{
		m_ID = ID;
	}

	void showStudent()
	{
		cout << "������" << m_name << "  " << "ѧ�ţ�" << m_ID << endl;
	}
};

int main()
{	
	student sd;
	
	sd.setName("����");
	sd.setId("189014001");

	sd.showStudent();

	system("pause");
	return 0;
}