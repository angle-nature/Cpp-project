#include<iostream>
using namespace std;

class Person
{
public:

	int m_A;                //�Ǿ�̬��Ա����  ������Ķ�����

	static int m_B;         //��̬��Ա����  ��������Ķ�����

	void func01() {}        //�Ǿ�̬��Ա����  ��������Ķ�����

	static void func02(){}  //��̬��Ա����  ��������Ķ�����
};

void test01()
{
	Person p1;
	//�ն���ռ���ڴ�Ϊ�� 1
	//C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "size of Person= " << sizeof(p1) << endl;
}

int main()
{
	test01();

	system("pause");

	return 0;
}