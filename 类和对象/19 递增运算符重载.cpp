#include<iostream>
using namespace std;

class MyInteger
{
	//ȫ�ֺ�������Ԫ
	friend ostream& operator<<(ostream& cout, MyInteger myint);

public:

	MyInteger()
	{
		m_Myint = 0;
	}

	//ǰ�õ���
	MyInteger& operator++() //����Ҫ��������  �����޷�����������ε���
	{
		//��++
		this->m_Myint++;

		//�ٷ���
		return *this;
	}

	//���õ���
	MyInteger operator++(int)
	{
		//��¼��ǰ�����ֵ��Ȼ���ñ����ֵ����1�����Ƿ��ص�����ǰ��ֵ���ﵽ�ȷ�����++��Ŀ��
		MyInteger temp = *this;

		this->m_Myint++;

		return temp;
	}

private:

	int m_Myint;

};

//ֻ����ȫ�ֺ�������<<
ostream& operator<<(ostream& cout, MyInteger myint)  //cout���� ostream��  ��ֻ��һ�� ����Ҫ�� ����
{
	cout << "myint= " << myint.m_Myint;
	return cout;  //����cout ��Ϊ�˿��Լ�����ӡ��������
}

void test01()
{
	MyInteger myint;

	cout << ++(++myint) << endl;
	cout << myint << endl;

}

void test02()
{
	MyInteger myint;

	cout << (myint++)++ << endl;
	cout << myint << endl;
}

int main()
{
	test01();
	test02();

	system("pause");

	return 0;
}