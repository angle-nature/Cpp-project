#include<iostream>
using namespace std;

//string�Ĺ��캯��

/*
-string& operator=(const char* s);                   //char*�����ַ�������ֵ����ǰ���ַ���
-string& operator=(const string &s);                  //���ַ���s��ֵ����ǰ���ַ���
-string& operator=(char);                            //�ַ���ֵ����ǰ���ַ���
-string& assign(const char* s);                      //���ַ���s��ֵ����ǰ���ַ���
-string& assign(const char* s,int n);                //���ַ���s��ǰn���ַ���ֵ����ǰ���ַ���
-string& assign(const string &s);                     //���ַ���s��ֵ����ǰ���ַ���
-string& assign(int n,cahr c);                       //��n���ַ�c��ֵ����ǰ�ַ���
*/

void test()
{
	string s1;  //Ĭ�Ϲ���
	s1 = "Hello World";
	cout << "s1=" << s1 << endl;

	string s2;
	s2 = s1;
	cout << "s2=" << s2 << endl;

	string s3;
	s3 = 'a';
	cout << "s3=" << s3 << endl;

	string s4;
	s4.assign("Hello World!");
	cout << "s4=" << s4 << endl;

	string s5;
	s5.assign("Hello World!",5);
	cout << "s5=" << s5 << endl;

	string s6;
	s6.assign(s5);
	cout << "s6=" << s6 << endl;

	string s7;
	s7.assign(10, 'a');
	cout << "s7=" << s7 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}