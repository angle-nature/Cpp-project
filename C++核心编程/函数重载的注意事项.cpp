#include<iostream>
using namespace std;

//�����������������ò���
void func01(int& a)
{
	cout << "func01(int& a)�ĵ���" << endl;
}

void func01(const int& a)
{
	cout << "func01(const int& a)�ĵ���" << endl;
}

//��������������Ĭ�ϲ���
void func02(int a, int b = 10)
{
	cout << "func02(int a, int b = 10)�ĵ���" << endl;
}

void func02(int a)
{
	cout << "func02(int a)" << endl;
}

int main()
{
	int a = 10;
	func01(a);    //���� func01(int& a)

	func01(10);   //���� func01(const int& a)

	//func02(a);    //����Ĭ�ϲ�����������  ����  Ӧ��������

	system("pause");
	return 0;
}