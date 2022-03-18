#include"Circle.h"


void Circle::setCenter(Point center)
{
	m_Center = center;
}

Point Circle::getCenter()
{
	return m_Center;
}

void Circle::setR(int r)
{
	m_R = r;
}

int Circle::getR()
{
	return m_R;
}

//��Ա�����жϹ�ϵ
void Circle::isInCircle(Point& p)
{
	int distance =
		(p.getX() - getCenter().getX()) * (p.getX() - getCenter().getX()) +
		(p.getY() - getCenter().getY()) * (p.getY() - getCenter().getY());

	int rDistance = getR() * getR();

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
