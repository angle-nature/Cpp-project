#pragma once
#include"Tank.h"

class Frame
{
private:
	static void startFrame(); //��Ϸ��ʼ����
	static void gameOver(); //��Ϸʧ�ܽ���
	static void victory(); //��Ϸʤ������
public:	
	static void playFrame(); //��Ϸ����
};