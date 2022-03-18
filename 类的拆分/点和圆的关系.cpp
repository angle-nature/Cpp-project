#include<iostream>
using namespace std;
#include"point.h"
#include"Circle.h"

//�����������ͷ�ļ��У��������Դ�ļ���


//ȫ�ֺ����жϹ�ϵ
void isInCircle(Circle& c, Point& p)
{
	int distance =
		(p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) +
		(p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY());

	int rDistance = c.getR() * c.getR();

	if (distance == rDistance)
	{
		cout << "����Բ��" << endl;
	}

	else if (distance < rDistance)
	{
		cout << "����Բ��" << endl;
	}

	else
	{
		cout << "����Բ��" << endl;
	}

}

int main()
{
	Circle c;
	Point p1;
	Point p2;

	p1.setX_Y(10, 20);
	p2.setX_Y(10, 10);

	c.setCenter(p2);
	c.setR(10);

	isInCircle(c, p1); //ȫ�ֺ����жϹ�ϵ
	isInCircle(c, p2); //ȫ�ֺ����жϹ�ϵ

	c.isInCircle(p1);  //��Ա�����жϹ�ϵ
	c.isInCircle(p2);  //��Ա�����жϹ�ϵ

	system("pause");
	return 0;
}