#include<iostream>
using namespace std;
#include<fstream>

class Person
{
public:

	char m_Name[64];  //��string�������ͻ�����һЩ����

	int m_Age;
};

void test()
{
	//1������ͷ�ļ�

	//2������������
	ifstream ifs;

	//3�����ļ�
	ifs.open("Person.txt", ios::in | ios::binary);  //�򿪷�ʽҲ�����ڴ����������ʱ���д

	//4���ж��ļ��Ƿ�ɹ���
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	//5����ȡ�ļ�
	Person p;
	ifs.read((char*)&p, sizeof(Person));

	cout << "������" << p.m_Name << " ���䣺" << p.m_Age << endl;

}

int main()
{
	test();

	system("pause");

	return 0;
}