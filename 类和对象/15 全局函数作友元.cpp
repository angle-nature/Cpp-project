#include<iostream>
using namespace std;

//������
class Building
{
	//���߱����� goodGay ȫ�ֺ����� Builing�� �ĺ����� ���Է���Building��˽������
	friend void goodGay(Building& building);

public:

	string m_sittingRoom; //����

	Building()
	{
		m_sittingRoom = "����";
		m_bedRoom = "����";
	}

private:
	 
	string m_bedRoom;  //����
};

//ȫ�ֺ�������Ԫ
void goodGay(Building &building)
{
	cout << "goodGay ȫ�ֺ������ڷ��ʣ�" << building.m_sittingRoom << endl;
	cout << "goodGay ȫ�ֺ������ڷ��ʣ�" << building.m_bedRoom << endl;
}

void test()
{
	Building b;
	goodGay(b);
}

int main()
{
	test();

	system("pause");

	return 0;
}