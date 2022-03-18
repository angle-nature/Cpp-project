#include<iostream>
using namespace std;

//���ö�̬ʵ�ּ�����
//��̬�ŵ㣺
//1���ṹ����
//2���ɶ���ǿ
//3������ǰ�ںͺ������Լ�ά���Ը�

//ʵ�ּ�����������
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

//�ӷ���������
class AddCalulator:public AbstractCalculator
{
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

//������������
class SubCalulator :public AbstractCalculator
{
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

//�˷���������
class MulCalulator :public AbstractCalculator
{
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

void test()
{
	//��̬ʹ������
	//����ָ����������������

	//�ӷ�����
	AbstractCalculator* abc = new AddCalulator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;

	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	//�������ٵ��ڴ�ǵ��ֶ�����  �ͷŵ���ָ����ָ������
	delete abc;

	//��������
	abc = new SubCalulator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;

	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;

	//�˷�����
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