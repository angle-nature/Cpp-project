#pragma once  //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;

class Point
{
public:

	void setX_Y(int x, int y);
	
	int getX();
	
	int getY();
	
private:

	int m_X;
	int m_Y;
};