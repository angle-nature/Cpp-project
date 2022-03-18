#include"point.h"

//Point::  表示该函数在Point类作用域下
void Point::setX_Y(int x, int y)
{
	m_X = x;
	m_Y = y;
}

int Point::getX()
{
	return m_X;
}

int Point::getY()
{
	return m_Y;
}
