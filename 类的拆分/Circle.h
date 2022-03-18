#pragma once
#include<iostream>
#include"point.h"
using namespace std;

class Circle
{

public:

	void setCenter(Point center);
	
	Point getCenter();
	
	void setR(int r);
	

	int getR();

	//成员函数判断关系
	void isInCircle(Point& p);

private:

	int m_R;

	//一个类中可以调用另一个类
	Point m_Center;
};
