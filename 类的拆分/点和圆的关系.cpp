#include<iostream>
using namespace std;
#include"point.h"
#include"Circle.h"

//类的声明放在头文件中，定义放在源文件中


//全局函数判断关系
void isInCircle(Circle& c, Point& p)
{
	int distance =
		(p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) +
		(p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY());

	int rDistance = c.getR() * c.getR();

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

int main()
{
	Circle c;
	Point p1;
	Point p2;

	p1.setX_Y(10, 20);
	p2.setX_Y(10, 10);

	c.setCenter(p2);
	c.setR(10);

	isInCircle(c, p1); //全局函数判断关系
	isInCircle(c, p2); //全局函数判断关系

	c.isInCircle(p1);  //成员函数判断关系
	c.isInCircle(p2);  //成员函数判断关系

	system("pause");
	return 0;
}