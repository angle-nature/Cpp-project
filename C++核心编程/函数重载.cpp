#include<iostream>
using namespace std;

//�������ص�������
//1����������ͬ
//2����������ͬ������ֵ������ͬ
//3�����������ĸ��������͡�˳��ͬ
void func()
{
	cout << "' func()����" << endl;
}

void func(int a)
{
	cout << "func(int a)����" << endl;
}

void func(int a,int b)
{
	cout << " func(int a,int b)����" << endl;
}

void func(int a,float b)
{
	cout << "func(int a,float b)����" << endl;
}

void func(float a,int b)
{
	cout << " func(float a,int b)����" << endl;
}

int main()
{


	system("pause");

	return 0;
}