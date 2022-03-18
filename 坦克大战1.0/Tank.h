#pragma once
#include<graphics.h>
#include"Bullet.h"
#include"Direction.h"

class Tank
{
	friend class Frame;
protected:
	int tank_x;  //̹�˺�����
	int tank_y;  //̹��������

	DIRECTION direction;   //�ж�̹�˷��򣬴Ӷ�ȷ���ӵ��ķ��й켣    1 Ϊ�� ��2Ϊ�� �� 3Ϊ�� 4Ϊ��
	int HP;  //̹��Ѫ��  HPΪ0ʱ����	
	IMAGE Tank_img[4]; //̹�˵�������������ͼƬ
	//Bullet2 bullet;

	void putImage(); //����̹��ͼƬ
	void mapModify(int n); //�޸ĵ�ͼ����
	virtual void tankMove();//̹���ƶ�����
	void actuallyMove(int keyDirection); //ʵ���ƶ�
	//virtual void tankFire(); //���� �����ӵ�
	void tankBoom(); //̹�˱�ը����
	bool selfCheck(); //�Լ�̹�������Ƿ��ӵ�����
	void toDestination(int x, int y); //��Ŀ�ĵ�ǰ��
};

class PlayerTank: public Tank  //���̹��
{
	friend class Frame;
private:
	Bullet1 bullet;
public:
	void tankFire();
	PlayerTank(); //��ʼ��̹��
	void tankMove();
	void controlTank(); //�ٿؼ���̹��  �����ƶ������
};

class EnemyTank1 : public Tank  //�з�̹��1
{
	friend class Frame;
private:
	Bullet2 bullet;
public:
	void tankFire();
	void initEnemyTank1(int x,int y); //��ʼ��̹��
};

class EnemyTank2 : public Tank  //�з�̹��2
{
	friend class Frame;
private:
	Bullet2 bullet;
public:
	void tankFire();
	void initEnemyTank2(int x,int y); //��ʼ��̹��
};