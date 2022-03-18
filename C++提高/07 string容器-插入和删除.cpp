#include<iostream>
using namespace std;

//string 字符串插入和删除

void test()
{
	string str = "hello";

	//插入
	str.insert(1, "123");   //在下标为 1 的位置插入字符串"123"
	cout << "str=" << str << endl;

	//删除
	str.erase(1, 3);  //从下表为 1 的位置开始删除 3 个字符
	cout << "str=" << str << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}