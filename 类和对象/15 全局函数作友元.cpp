#include<iostream>
using namespace std;

//房屋类
class Building
{
	//告诉编译器 goodGay 全局函数是 Builing类 的好朋友 可以访问Building的私有内容
	friend void goodGay(Building& building);

public:

	string m_sittingRoom; //客厅

	Building()
	{
		m_sittingRoom = "客厅";
		m_bedRoom = "卧室";
	}

private:
	 
	string m_bedRoom;  //卧室
};

//全局函数作友元
void goodGay(Building &building)
{
	cout << "goodGay 全局函数正在访问：" << building.m_sittingRoom << endl;
	cout << "goodGay 全局函数正在访问：" << building.m_bedRoom << endl;
}

void test()
{
	Building b;
	goodGay(b);
}

int main()
{
	test();

	system("pause");

	return 0;
}