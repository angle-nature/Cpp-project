#include<iostream>
using namespace std;

class Building;

//�û�����
class goodGay
{
public:

	Building* building;

	goodGay();


	//void visit()
	//{
	//	cout << "�û��������ڷ��ʣ�" << building->m_bedRoom << endl;
	//}

	void visit2();

};

//������
class Building
{
	//���߱����� goodGay���� Builing�� �ĺ����� ���Է���Building��˽������
	//friend class goodGay;

	//���߱����� visit2 ��Ա������ Builing�� �ĺ����� ���Է���Building��˽������
	friend void goodGay::visit2();

public:

	string m_sittingRoom; //����

	Building();  //��������  ���ⶨ��


private:

	string m_bedRoom;  //����
};


//����д��Ա����
Building::Building()
{
	m_bedRoom = "����";
	m_sittingRoom = "����";
}

void goodGay::visit2()
{
	cout << "�û��������ڷ��ʣ�" << building->m_bedRoom << endl;
}

goodGay::goodGay()
{
	building = new Building;
}

void test()
{
	goodGay gg;
	//gg.visit();
	gg.visit2();
}

int main()
{
	test();

	system("pause");

	return 0;
}