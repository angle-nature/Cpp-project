#include<iostream>
using namespace std;

//������
class Animal
{
public:

	int m_Age;
};

//������̳� ���Խ�����μ̳е�����
//�ڼ̳�֮ǰ ���Ϲؼ��� virtual
//Animal ���Ϊ �����
//����
class Sheep :virtual public Animal{};

//����
class Tuo:virtual public Animal{};

//������
class SheepTuo :public Sheep, public Tuo{};

void test()
{
	SheepTuo st;

	st.Sheep::m_Age=18;
	st.Tuo::m_Age = 28;

	//���������μ̳� ����������ӵ����ͬ��Ա ��Ҫ��������������
	cout << "st.Sheep::m_Age=" << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;

	//������ݸ������� ֻ����һ�ݾͿ����� ���μ̳е������������� ��������Դ�˷�
	//��Ϊ��̳�֮��
	st.m_Age = 30;
	cout << "st.m_Age = " << st.m_Age << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}