#include<iostream>
using namespace std;

//string�Ĺ��캯��

/*
-string();                   //����һ���յ��ַ��� ���磺string str
-string(const string& str);  //ʹ���ַ���s��ʼ��
-string(const string& str);  //ʹ��һ��string�����ʼ����һ��string����  ��������
-string(int n,char c);       //ʹ��n���ַ�c��ʼ��
*/

void test()
{
	string s1;  //Ĭ�Ϲ���

	//char str[] = "Hello World";
	const char* str = "Hello World!";
	string s2(str);

	cout << s2 << endl;

	string s3(s2);  //��������
	cout << s3 << endl;

	string s4(10, 'a');
	cout << s4 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}