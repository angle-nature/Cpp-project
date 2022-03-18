#include<iostream>
using namespace std;

class Base1
{

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
	
};

//公共继承方式
class son1:public Base1
{
public:
	void func()
	{
		m_A = 10; //父类中的公共权限成员 到子类中依然是公共权限
		m_B = 20; //父类中的保护权限成员 到子类中依然是保护权限
		//m_C = 30; //父类中的私有权限成员 到子类访问不到
	}
};

//保护继承方式
class son2 :protected Base1
{
public:
	void func()
	{
		m_A = 10; //父类中的公共权限成员 到子类中变成保护权限
		m_B = 20; //父类中的保护权限成员 到子类中依然是保护权限
		//m_C = 30; //父类中的私有权限成员 到子类访问不到
	}
};

//私有继承方式
class son3 :private Base1
{
public:
	void func()
	{
		m_A = 10; //父类中的公共权限成员 到子类中变成私有权限
		m_B = 20; //父类中的保护权限成员 到子类中变为私有权限
		//m_C = 30; //父类中的私有权限成员 到子类访问不到
	}
};

int main()
{
	system("pause");

	return 0;
}