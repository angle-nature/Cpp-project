#include<iostream>
using namespace std;

//string�Ĺ��캯��

/*
-string& operator+=(const char* s);                   //����+=������
-string& operator+=(const char c);                    //����+=������
-string& operator+=(const string &s);                 //����+=������
-string& append(const char* s);                       //���ַ���s���ӵ���ǰ���ַ�����β
-string& append(const char* s,int n);                 //���ַ���s��ǰn���ַ����ӵ���ǰ���ַ�����β
-string& append(const string &s);                     //ͬoperator+=(const string &s);
-string& append(const string &s,int pos,int n);       //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
*/

void test()
{
	string s1 = "��";
	s1 += "������Ϸ";
	cout << "s1=" << s1 << endl;

	s1 += ':';
	cout << "s1=" << s1 << endl;

	string s2 = "LOL DNF";
	s1 += s2;
	cout << "s1=" << s1 << endl;

	string s3 = "I ";
	s3.append("love play ");
	cout << "s3=" << s3 << endl;

	s3.append("game abcder", 5);
	cout << "s3=" << s3 << endl;

	s3.append(s2);
	cout << "s3=" << s3 << endl;

	s3.append(s2, 0, 3);
	cout << "s3=" << s3 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}