#include<iostream>
using namespace std;

//string 求子串

void test01()
{
	string str = "hello";

	string substr = str.substr(1, 3); //从下表为 1 的位置开始获取 3 个字符

	cout << "substr=" << substr << endl;

}

//实用操作
void test02()
{
	string email = "zhangsan@qq.com";

	//从邮件中获取用户名信息
	int pos = email.find("@");

	string usremail = email.substr(0, pos);
	cout << "usremail=" << usremail << endl;
}

int main()
{
	//test01();
	test02();

	system("pause");

	return 0;
}