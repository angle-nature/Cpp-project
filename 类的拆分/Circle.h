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

	//��Ա�����жϹ�ϵ
	void isInCircle(Point& p);

private:

	int m_R;

	//һ�����п��Ե�����һ����
	Point m_Center;
};
