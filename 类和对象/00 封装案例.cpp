#include<iostream>
using namespace std;

class student
{
public:    //公共权限

	//类中的属性和行为统一称为成员
	//属性  成员属性||成员变量
	//行为  成员函数||成员方法

	string m_name;  //成员属性
	string m_ID;    //成员属性

	void setName(string name)   //成员函数
	{
		m_name = name;
	}

	void setId(string ID)
	{
		m_ID = ID;
	}

	void showStudent()
	{
		cout << "姓名：" << m_name << "  " << "学号：" << m_ID << endl;
	}
};

int main()
{	
	student sd;
	
	sd.setName("张三");
	sd.setId("189014001");

	sd.showStudent();

	system("pause");
	return 0;
}