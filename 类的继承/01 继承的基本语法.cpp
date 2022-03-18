#include<iostream>
using namespace std;

class BasePage
{
public:

	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}

	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
	}

	void left()
	{
		cout << "Java、Python、C++...(公共分类列表）" << endl;
	}

};

//继承的优点：减少重复代码量
//语法：  class 子类：继承方式 父类
//子类 也称为 派生类
//父类 也称为 基类

//Java页面
class Java:public BasePage
{
public:
	
	void concent()
	{
		cout << "Java学科视频" << endl;
	}

};

//Python页面
class Python :public BasePage
{
public:

	void concent()
	{
		cout << "Python学科视频" << endl;
	}
};

//C++页面
class CPP :public BasePage
{
public:

	void concent()
	{
		cout << "C++学科视频" << endl;
	}
};

void test()
{
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.concent();

	cout << "------------------------" << endl;

	Python py;
	py.header();
	py.footer();
	py.left();
	py.concent();

	cout << "------------------------" << endl;

	CPP c;
	c.header();
	c.footer();
	c.left();
	c.concent();
}

int main()
{
	test();

	system("pause");

	return 0;
}