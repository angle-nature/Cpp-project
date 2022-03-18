#include<iostream>
using namespace std;

//public        公共权限  类内可以访问 类外可以访问
//protected     保护权限  类内可以访问 类外不可以访问
//private       私有权限  类内可以访问 类外不可以访问   
//默认权限为私有权限

class person
{
	string m_wife;
public:

	string m_name; //姓名 公共权限

protected:

	string m_car;  //汽车 保护权限

private:

	string m_passward;  //私有权限

public:
	void showPerson()
	{
		m_name = "张三";
		m_car = "电驴";
		m_passward = "123456";
	}
};

int main()
{
	person p;
	p.m_name = "李四";        //类外可以访问

	//p.m_wife = "如花";      //m_wife默认为私有权限 因此类外不可访问
	//p.m_car = "宝马";       //类外不可访问
	//p.m_pssword = "000000"; //类外不可访问
	
	system("pause");
	return 0;
}