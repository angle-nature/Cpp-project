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
	ofstream ofs;

	//3、打开文件
	ofs.open("Person.txt", ios::out | ios::binary);  //打开方式也可以在创建流对象的时候就写

	//4、写文件
	Person p = { "飞碟",20 };
	ofs.write((const char*)&p, sizeof(Person));

	//5、关闭文件
	ofs.close();
	
}

int main()
{
	test();

	system("pause");

	return 0;
}