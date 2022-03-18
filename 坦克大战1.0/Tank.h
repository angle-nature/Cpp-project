#pragma once
#include<graphics.h>
#include"Bullet.h"
#include"Direction.h"

class Tank
{
	friend class Frame;
protected:
	int tank_x;  //坦克横坐标
	int tank_y;  //坦克纵坐标

	DIRECTION direction;   //判断坦克方向，从而确定子弹的飞行轨迹    1 为上 ，2为下 ， 3为左， 4为右
	int HP;  //坦克血量  HP为0时死亡	
	IMAGE Tank_img[4]; //坦克的上下左右四张图片
	//Bullet2 bullet;

	void putImage(); //放置坦克图片
	void mapModify(int n); //修改地图参数
	virtual void tankMove();//坦克移动规则
	void actuallyMove(int keyDirection); //实际移动
	//virtual void tankFire(); //开火 发射子弹
	void tankBoom(); //坦克爆炸画面
	bool selfCheck(); //自检坦克坐标是否被子弹置零
	void toDestination(int x, int y); //朝目的地前进
};

class PlayerTank: public Tank  //玩家坦克
{
	friend class Frame;
private:
	Bullet1 bullet;
public:
	void tankFire();
	PlayerTank(); //初始化坦克
	void tankMove();
	void controlTank(); //操控己方坦克  包括移动及射击
};

class EnemyTank1 : public Tank  //敌方坦克1
{
	friend class Frame;
private:
	Bullet2 bullet;
public:
	void tankFire();
	void initEnemyTank1(int x,int y); //初始化坦克
};

class EnemyTank2 : public Tank  //敌方坦克2
{
	friend class Frame;
private:
	Bullet2 bullet;
public:
	void tankFire();
	void initEnemyTank2(int x,int y); //初始化坦克
};