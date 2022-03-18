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

//成员函数判断关系
void Circle::isInCircle(Point& p)
{
	int distance =
		(p.getX() - getCenter().getX()) * (p.getX() - getCenter().getX()) +
		(p.getY() - getCenter().getY()) * (p.getY() - getCenter().getY());

	int rDistance = getR() * getR();

	if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}

	else if (distance < rDistance)
	{
		cout << "点在圆内" << endl;
	}

	else
	{
		cout << "点在圆外" << endl;
	}
}
