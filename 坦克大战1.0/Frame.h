#pragma once
#include"Tank.h"

class Frame
{
private:
	static void startFrame(); //游戏开始界面
	static void gameOver(); //游戏失败界面
	static void victory(); //游戏胜利界面
public:	
	static void playFrame(); //游戏界面
};