#pragma once
#include"Direction.h"
#include<graphics.h>
//#include"Frame.h"

class Bullet
{
public:
	int bullet_x;
	int bullet_y;
	DIRECTION direction;
	bool state = false; //�ӵ���״̬
	IMAGE bulletImage; //�ӵ�ͼƬ
	//bool bulletMove(); //�ӵ��ƶ�
};

class Bullet1:public Bullet //����ӵ�
{
public:
	Bullet1();
	bool bulletMove();
};

class Bullet2:public Bullet //�з�̹���ӵ�
{
public:
	Bullet2();
	bool bulletMove();
};
