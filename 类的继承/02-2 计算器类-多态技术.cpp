#include<iostream>
using namespace std;

//��ͨд��
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

		//�������չ�µĹ��ܣ����޸�Դ��
		//����Ŀ����� �ᳫ ����ԭ��
		//����ԭ�� ����չ���п��� ���޸Ľ��йر�
	}

	int m_Num1;
	int m_Num2;
};

void test01()
{
	//��������������
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