#include<iostream>
using namespace std;

class BasePage
{
public:

	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}

	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
	}

	void left()
	{
		cout << "Java��Python��C++...(���������б�" << endl;
	}

};

//�̳е��ŵ㣺�����ظ�������
//�﷨��  class ���ࣺ�̳з�ʽ ����
//���� Ҳ��Ϊ ������
//���� Ҳ��Ϊ ����

//Javaҳ��
class Java:public BasePage
{
public:
	
	void concent()
	{
		cout << "Javaѧ����Ƶ" << endl;
	}

};

//Pythonҳ��
class Python :public BasePage
{
public:

	void concent()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};

//C++ҳ��
class CPP :public BasePage
{
public:

	void concent()
	{
		cout << "C++ѧ����Ƶ" << endl;
	}
};

void test()
{
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.concent();

	cout << "------------------------" << endl;

	Python py;
	py.header();
	py.footer();
	py.left();
	py.concent();

	cout << "------------------------" << endl;

	CPP c;
	c.header();
	c.footer();
	c.left();
	c.concent();
}

int main()
{
	test();

	system("pause");

	return 0;
}