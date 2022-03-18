#include<iostream>
using namespace std;

//普通写法
class calculator
{
public:

	int GetResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}

		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}

		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		else if (oper == "/")
		{
			return m_Num1 / m_Num2;
		}

		//如果想扩展新的功能，需修改源码
		//在真的开发中 提倡 开闭原则
		//开闭原则： 对扩展进行开发 对修改进行关闭
	}

	int m_Num1;
	int m_Num2;
};

void test01()
{
	//创建计算器对象
	calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 20;

	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.GetResult("+") << endl;
}

int main()
{
	test01();

	system("pause");

	return 0;
}