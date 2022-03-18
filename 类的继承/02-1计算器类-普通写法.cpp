#include<iostream>
using namespace std;

//利用多态实现计算器
//多态优点：
//1、结构清晰
//2、可读性强
//3、对于前期和后期扩以及维护性高

//实现计算器抽象类
class AbstractCalculator
{
public:

	virtual int getResult()
	{
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//加法计算器类
class AddCalulator:public AbstractCalculator
{
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

//减法计算器类
class SubCalulator :public AbstractCalculator
{
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

//乘法计算器类
class MulCalulator :public AbstractCalculator
{
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

void test()
{
	//多态使用条件
	//父类指针或者引用子类对象

	//加法运算
	AbstractCalculator* abc = new AddCalulator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;

	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	//堆区开辟的内存记得手动销毁  释放的是指针所指的数据
	delete abc;

	//减法运算
	abc = new SubCalulator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;

	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;

	//乘法运算
	abc = new SubCalulator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;

	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
}

int main()
{
	test();

	system("pause");

	return 0;
}