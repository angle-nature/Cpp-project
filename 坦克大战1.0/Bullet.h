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
	bool state = false; //子弹的状态
	IMAGE bulletImage; //子弹图片
	//bool bulletMove(); //子弹移动
};

class Bullet1:public Bullet //玩家子弹
{
public:
	Bullet1();
	bool bulletMove();
};

class Bullet2:public Bullet //敌方坦克子弹
{
public:
	Bullet2();
	bool bulletMove();
};
