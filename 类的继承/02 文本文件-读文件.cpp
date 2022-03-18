#include<iostream>
using namespace std;
#include<fstream>
#include<string>

void test()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	//判断文件是否成功打开
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	//读取数据
	//第一种方式
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//第二种方式
	//char buf[1024] = { 0 };    //buffer:缓存
	//ifs.getline(buf, sizeof(buf));

	//	cout << buf << endl;
	
	//第三种方式
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

	//第四种
	char c;
	while ((c = ifs.get()) != EOF)  //EOF: end of file
	{
		cout << c;
	}


}

int main()
{
	test();

	system("pause");

	return 0;
}