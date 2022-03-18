#include"Frame.h"
#include"Map.h"
#include<graphics.h>
#pragma comment(lib,"winmm.lib")  //导入声音库
//#include"Tank.h"

void Frame::startFrame() //游戏开始界面
{
	PlaySound(_T("background.wav"), NULL, SND_FILENAME | SND_ASYNC);
	IMAGE logoImg;
	loadimage(&logoImg, _T("logo.bmp"), 433, 147);
	putimage(113, 40, &logoImg); //加载TANK logo

	IMAGE illustrate;
	loadimage(&illustrate, _T("illustrate.jpg"), 300, 300); //操作说明图片
	settextcolor(RGB(255, 255, 255));
	settextstyle(30, 0, _T("微软雅黑"));
	rectangle(195, 200, 275, 240);
	rectangle(375, 200, 455, 240);
	outtextxy(210, 205, _T("说 明"));
	outtextxy(390, 205, _T("开 始"));

	//  检测鼠标事件
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE: //鼠标移动
			if ((m.x >= 195 && m.x <= 275) && (m.y >= 200 && m.y <= 240))
			{
				putimage(150, 250, &illustrate); //放置操作说明图片
			}
			else
			{
				setfillcolor(BLACK);
				solidrectangle(150, 250, 450, 550);
			}
			break;

		case WM_LBUTTONDOWN: //鼠标点击
			if ((m.x >= 375 && m.x <= 455) && (m.y >= 200 && m.y <= 240))
			{
				cleardevice();
				return;
			}
			break;
		}
	}
}

void Frame::gameOver() //游戏结束界面
{
	IMAGE gameOver;
	loadimage(&gameOver, _T("gameover.jpg"), 600, 400);
	for (int i = 0; i < 130; i++) //从窗口上方下滑效果
	{
		cleardevice();
		putimage(25, i, &gameOver);
		Sleep(15);
	}
	system("pause"); //界面停留
}

void Frame::victory() //玩家胜利界面
{
	cleardevice();
	settextcolor(RED);
	settextstyle(300, 70, _T("微软雅黑"));
	outtextxy(80, 150, _T("Victory"));
	system("pause");
}

void Frame::playFrame()
{
	const int TOTALNUMBER = 10; //设定的敌方坦克1总数

	startFrame(); //开始界面
	Map::loadMap(); //加载地图

	bool flag = true; //判断游戏是否结束 将10个坦克1击败则胜利

	int times = 0;    //记录当前程序的休眠次数
	int enemyTotal = 0; //已加载到地图上的坦克总数
	int enemyalive = TOTALNUMBER; //总存活坦克数

	EnemyTank1 et[TOTALNUMBER]; //共放置10个第一种敌方坦克
	EnemyTank2 et2_1,et2_2;

	et2_1.initEnemyTank2(0, 8); //初始化第二种敌方坦克
	et2_2.initEnemyTank2(24, 8);

	PlayerTank pt; //加载玩家坦克
	for (int i = 0; i < TOTALNUMBER; i++) //初始化所有敌方坦克1
	{		
		if (i % 3 == 0)
			et[i].initEnemyTank1(0, 0);
		else if (i % 3 == 1)
			et[i].initEnemyTank1(12, 0);
		else if (i % 3 == 2)
			et[i].initEnemyTank1(24, 0);
	}

	enemyTotal = 3; //现有坦克数量
	for (int i = 0; i < enemyTotal; i++) //加载3个坦克
	{
		et[i].putImage(); //放置坦克图片
	}

	while (true)
	{		
		//登场其他坦克1
		if (times % 200 == 0 && times != 0 && enemyTotal < TOTALNUMBER)
		{
			if (Map::map[et[enemyTotal - 1].tank_y][et[enemyTotal - 1].tank_x] == 0 ||
				Map::map[et[enemyTotal - 1].tank_y + 1][et[enemyTotal - 1].tank_x] == 0 ||
				Map::map[et[enemyTotal - 1].tank_y][et[enemyTotal - 1].tank_x + 1] == 0 ||
				Map::map[et[enemyTotal - 1].tank_y + 1][et[enemyTotal - 1].tank_x + 1] == 0)
			{
				enemyTotal++;
				et[enemyTotal - 1].putImage();
			}		
		}
		//坦克2登场
		if (times == 1500) 
		{
			et2_1.putImage();
			et2_2.putImage();
		}
		//坦克2移动及开火
		if (times >= 1500 && times % 80 == 0) 
		{
			if (et2_1.HP > 0)
			{
				et2_1.toDestination(12,24);
				et2_1.actuallyMove(et2_1.direction);
				et2_1.tankFire();
			}

			if (et2_2.HP > 0)
			{
				et2_2.toDestination(pt.tank_x, pt.tank_y);
				et2_2.actuallyMove(et2_2.direction);
				et2_2.tankFire();
			}
		}

		// 控制敌方坦克改变方向
		if (times % 200 == 0)
		{
			for (int i = 0; i < enemyTotal; i++)
			{
				if (et[i].HP>0)
				{
					if (i % 2 == 0)        //双数坦克攻击我方老巢
					{
						et[i].toDestination(12, 24);
						et[i].actuallyMove(et[i].direction);
					}
					else                    //单数坦克攻击我方坦克
					{
						et[i].toDestination(pt.tank_x, pt.tank_y);
						et[i].actuallyMove(et[i].direction);
					}
					et[i].tankFire();
				}
			}
		}
		else if (times % 20 == 0)   //控制敌方坦克移动
		{
			if (times >= 1500)
			{
				if (et2_1.HP > 0)
					et2_1.actuallyMove(et2_1.direction);
				if (et2_2.HP > 0)
					et2_2.actuallyMove(et2_2.direction);
			}

			for (int i = 0; i < enemyTotal; i++)
			{
				if (et[i].HP > 0)				
					et[i].actuallyMove(et[i].direction);				
			}
		}

		pt.selfCheck(); //玩家坦克自检是否被摧毁

		if (times >= 1500)
		{
			et2_1.selfCheck(); //敌方坦克2自检是否被摧毁
			et2_2.selfCheck();
		}


		for (int i = 0; i < enemyTotal; i++)
		{
			et[i].selfCheck();	//敌方坦克1自检是否被摧毁		

			if (et[i].bullet.state)  //子弹存在时，更新敌方子弹飞行位置
			{
				flag = et[i].bullet.bulletMove();
				if(flag == false)				
					gameOver();
			}
		}
		
		for (int i = 0; i < TOTALNUMBER; i++)
		{
			if (et[i].HP == 0)
				enemyalive--;
		}

		if (enemyalive == 0)  //判断游戏是否胜利
		{
			victory();
			break;
		}
		else
			enemyalive = TOTALNUMBER;

		if (et2_1.bullet.state)
		{
			flag = et2_1.bullet.bulletMove(); //坦克2子弹移动
			if (flag == false)
				gameOver();
		}

		if (et2_2.bullet.state)
		{
			flag = et2_2.bullet.bulletMove(); //坦克2子弹移动
			if (flag == false)
				gameOver();
		}
		if (pt.bullet.state)            //子弹存在时，更新我方子弹飞行位置
			pt.bullet.bulletMove();	
		
		pt.controlTank(); //玩家操控坦克	
		times++; //计时器加一
		Sleep(15);
	}
}