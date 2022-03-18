#include<iostream>
using namespace std;

//string的构造函数

/*
-string& operator+=(const char* s);                   //重载+=操作符
-string& operator+=(const char c);                    //重载+=操作符
-string& operator+=(const string &s);                 //重载+=操作符
-string& append(const char* s);                       //把字符串s连接到当前的字符串结尾
-string& append(const char* s,int n);                 //把字符串s的前n个字符连接到当前的字符串结尾
-string& append(const string &s);                     //同operator+=(const string &s);
-string& append(const string &s,int pos,int n);       //字符串s中从pos开始的n个字符连接到字符串结尾
*/

void test()
{
	string s1 = "我";
	s1 += "爱玩游戏";
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