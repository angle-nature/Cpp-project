#include<iostream>
using namespace std;

int& function01()
{
	int a = 10;   //�ֲ�����������ջ��  �Ǿֲ����� ���ܷ��ؾֲ�����������	
	return a;
}

int& function02()
{
	static int b = 20;  //��̬�����洢��ȫ����  ���Է��ر���������
	return b;
}

int main()
{
	int& ref01 = function01();
	int& ref02 = function02();

	cout << "ref= " << ref01 << endl;  //��һ����ȷ����Ϊ����������һ�����ݵı���
	cout << "ref= " << ref01 << endl;  //�ٴδ�ӡ����ִ�����Ϊa���ڴ��Ѿ��ͷ�

	cout << "ref= " << ref02 << endl;  //��δ�ӡ������ִ���
	cout << "ref= " << ref02 << endl;

	function02() = 1000;     //��������ķ���ֵ�����ã������ĵ��ÿ�����Ϊ��ֵ

	cout << "ref= " << ref02 << endl;
	cout << "ref= " << ref02 << endl;

	return 0;
}