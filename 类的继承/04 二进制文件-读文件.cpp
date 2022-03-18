#include<iostream>
using namespace std;
#include<fstream>

class Person
{
public:

	char m_Name[64];  //用string数据类型会引起一些错误

	int m_Age;
};

void test()
{
	//1、包含头文件

	//2、创建流对象
	ifstream ifs;

	//3、打开文件
	ifs.open("Person.txt", ios::in | ios::binary);  //打开方式也可以在创建流对象的时候就写

	//4、判断文件是否成功打开
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	//5、读取文件
	Person p;
	ifs.read((char*)&p, sizeof(Person));

	cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;

}

int main()
{
	test();

	system("pause");

	return 0;
}