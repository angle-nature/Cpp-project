#include<iostream>
using namespace std;
#include<fstream>

void test()
{
	//����ͷ�ļ� fstream

	//����������
	ofstream ofs;
	
	//ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);

	//д����
	ofs << "���������������������ϣ�" << endl;

	//�ر��ļ�
	ofs.close();
}

int main()
{
	test();

	system("pause");

	return 0;
}