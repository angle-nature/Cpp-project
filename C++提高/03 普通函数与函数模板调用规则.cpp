#include<iostream>
using namespace std;

//��ͨ�����뺯��ģ����ù���
//1���������ģ������ͨ���������Ե��ã����ȵ�����ͨ����
//2������ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
//3������ģ����Է�������
//4���������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��

void myPrint(int a, int b)
{
	cout << "���õ���ͨ����" << endl;
}

template<class T>
void myPrint(T a, T b)
{
	cout << "���õ�ģ�庯��" << endl;
}


int main()
{
	int a = 10;
	int b = 20;

	myPrint(a, b); //����1��������ͨ����

	//ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
	myPrint<>(a, b);

	//�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
	char c1 = 'a';
	char c2 = 'b';

	myPrint(c1, c2);

	system("pause");

	return 0;
}