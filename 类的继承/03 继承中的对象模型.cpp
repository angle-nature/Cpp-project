#include<iostream>
using namespace std;

class Base1
{

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;  //˽�г�Աֻ�Ǳ�������  �����ǻᱻ�̳���ȥ

};

//�����̳з�ʽ
class Son1 :public Base1
{
public:
	
	int m_D;
};

//���ÿ�����Ա��ʾ����ߣ�Developer Command Prompt for VS 2019���鿴����ģ��
//��ת�̷� E��
//��ת�ļ�·�� cd E:\C��Ŀ\��ļ̳�
//�鿴���  cl /d1 reportSingleClassLayout���� �ļ���

void test()
{
	//���������зǾ�̬��Ա���ᱻ�̳���ȥ�����е�˽�г�Ա �Ǳ������������� ��˷��ʲ��� ���Ǳ��̳���ȥ��
	cout << "size of Son =" << sizeof(Son1) << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}