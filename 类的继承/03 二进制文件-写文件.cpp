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
	ofstream ofs;

	//3�����ļ�
	ofs.open("Person.txt", ios::out | ios::binary);  //�򿪷�ʽҲ�����ڴ����������ʱ���д

	//4��д�ļ�
	Person p = { "�ɵ�",20 };
	ofs.write((const char*)&p, sizeof(Person));

	//5���ر��ļ�
	ofs.close();
	
}

int main()
{
	test();

	system("pause");

	return 0;
}