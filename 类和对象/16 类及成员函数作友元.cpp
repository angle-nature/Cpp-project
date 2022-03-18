#include<iostream>
using namespace std;

class Building;

//好基友类
class goodGay
{
public:

	Building* building;

	goodGay();


	//void visit()
	//{
	//	cout << "好基友类正在访问：" << building->m_bedRoom << endl;
	//}

	void visit2();

};

//房屋类
class Building
{
	//告诉编译器 goodGay类是 Builing类 的好朋友 可以访问Building的私有内容
	//friend class goodGay;

	//告诉编译器 visit2 成员函数是 Builing类 的好朋友 可以访问Building的私有内容
	friend void goodGay::visit2();

public:

	string m_sittingRoom; //客厅

	Building();  //类内声明  类外定义


private:

	string m_bedRoom;  //卧室
};


//类外写成员函数
Building::Building()
{
	m_bedRoom = "卧室";
	m_sittingRoom = "客厅";
}

void goodGay::visit2()
{
	cout << "好基友类正在访问：" << building->m_bedRoom << endl;
}

goodGay::goodGay()
{
	building = new Building;
}

void test()
{
	goodGay gg;
	//gg.visit();
	gg.visit2();
}

int main()
{
	test();

	system("pause");

	return 0;
}