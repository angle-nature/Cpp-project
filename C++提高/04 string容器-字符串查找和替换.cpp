#include<iostream>
using namespace std;

//1、查找
void test01()
{
	string s1 = "abcdefghdek";

	int pos = s1.find("de"); //find()函数返回值为字符在字符串中的下标  未查找到返回-1

	if (pos == -1)
	{
		cout << "未查找到" << endl;
	}
	else
	{
		cout <<"找到字符串：pos="<< pos << endl;
	}

	//rfind 和 find 的区别
	//rfind 从右往左查找  find 从左往右查找  但输出的下标都是从左往右计数
	pos = s1.rfind("de");

	if (pos == -1)
	{
		cout << "未查找到" << endl;
	}
	else
	{
		cout << "找到字符串：pos=" << pos << endl;
	}

}

void test02()
{
	string s = "abcdefg";

	s.replace(1, 3, "1111"); //从第 1 个字符开始替换 3 个 替换成 “1111”

	cout << s << endl;
}

int main()
{
	test01();
	test02();

	system("pause");

	return 0;
}