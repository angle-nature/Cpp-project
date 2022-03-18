#include<iostream>
using namespace std;
#include<fstream>

void test()
{
	//包含头文件 fstream

	//创建流对象
	ofstream ofs;
	
	//指定打开方式
	ofs.open("test.txt", ios::out);

	//写内容
	ofs << "噜啦啦噜啦啦噜啦噜啦嘞！" << endl;

	//关闭文件
	ofs.close();
}

int main()
{
	test();

	system("pause");

	return 0;
}