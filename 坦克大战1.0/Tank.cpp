#include<graphics.h>
#include"Map.h"
#include"Tank.h"
#include <conio.h>
#include<ctime>
#pragma comment(lib,"winmm.lib") //导入声音库

PlayerTank::PlayerTank() //己方坦克初始化
{
	tank_x = 8;  //出现坐标设置在（8，24）格（一堵墙的大小）
	tank_y = 24;
	direction = UP; //初始朝向为上
	HP = 1; //初始血量为1
	mapModify(6);
	
	loadimage(&Tank_img[UP], _T("tank_up.jpg"), 50, 50);
	loadimage(&Tank_img[DOWN], _T("tank_down.jpg"), 50, 50);
	loadimage(&Tank_img[LEFT], _T("tank_left.jpg"), 50, 50);
	loadimage(&Tank_img[RIGHT], _T("tank_right.jpg"), 50, 50);
	putImage();
}

void EnemyTank1::initEnemyTank1(int x,int y) //敌方坦克1初始化
{
	tank_x = x;
	tank_y = y;
	direction = DOWN;
	HP = 1; //初始血量为1
	loadimage(&Tank_img[UP], _T("enemy_tank_up.gif"), 50, 50);
	loadimage(&Tank_img[DOWN], _T("enemy_tank_down.gif"), 50, 50);
	loadimage(&Tank_img[LEFT], _T("enemy_tank_left.gif"), 50, 50);
	loadimage(&Tank_img[RIGHT], _T("enemy_tank_right.gif"), 50, 50);
	//putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
}

void EnemyTank2::initEnemyTank2(int x, int y) //敌方坦克2初始化
{
	tank_x = x;
	tank_y = y;
	direction = DOWN;
	HP = 2; //初始血量为2

	loadimage(&Tank_img[UP], _T("p2tankU.gif"), 50, 50);
	loadimage(&Tank_img[DOWN], _T("p2tankD.gif"), 50, 50);
	loadimage(&Tank_img[LEFT], _T("p2tankL.gif"), 50, 50);
	loadimage(&Tank_img[RIGHT], _T("p2tankR.gif"), 50, 50);
	//putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
}

void Tank::putImage()
{
	mapModify(5);
	putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
}

void Tank::mapModify(int n) //修改地图参数
{
	Map::map[tank_y][tank_x] = n;
	Map::map[tank_y + 1][tank_x] = n;
	Map::map[tank_y][tank_x + 1] = n;
	Map::map[tank_y + 1][tank_x + 1] = n;
}

void Tank::tankMove() //坦克移动
{
	mapModify(0); //将移动之前的地方设为0  即路
	setfillcolor(BLACK); //设置填充颜色
	solidrectangle(tank_x * 25,tank_y * 25,tank_x * 25 + 50,tank_y * 25 + 50);  //覆盖坦克原来位置
	if (direction == UP)
	{
		tank_y--;
	}
	else if (direction == DOWN)
	{
		tank_y++;
	}
	else if (direction == LEFT)
	{
		tank_x--;
	}
	else if (direction == RIGHT)
	{
		tank_x++;
	}
	mapModify(5); //移动后将此处设为5 代表敌方坦克
	putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
}

bool Tank::selfCheck()
{
	if (Map::map[tank_y][tank_x] == 0 || Map::map[tank_y + 1][tank_x] == 0 ||
		Map::map[tank_y][tank_x + 1] == 0 || Map::map[tank_y + 1][tank_x + 1] == 0)
	{
		if (HP > 0)
		{
			HP--;
			if (HP == 0)
			{
				mapModify(0); //将所占地图全部置零
				tankBoom(); //调用坦克爆炸函数
				return false;
			}
			else
				mapModify(5);
		}
	}
	return true;
}

void Tank::actuallyMove(int keyDirection) //实际移动
{
	switch (keyDirection) //tank_x与tank_y始终在坦克的左上角
	{                                  
	case UP:   //坦克向上
		if (direction == UP && (tank_y - 1) >= 0 && Map::map[tank_y - 1][tank_x] == 0 && Map::map[tank_y - 1][tank_x + 1] == 0)
		{			
			//if (selfCheck())//先自检自身是否被击毁
				tankMove(); //然后再移动
		}
		else if (direction != UP)
		{
			direction = UP;
			putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
		}
		break;                                      
	case DOWN:  //坦克向下
		if (direction == DOWN && (tank_y + 2) <= 25 && Map::map[tank_y + 2][tank_x] == 0 && Map::map[tank_y + 2][tank_x + 1] == 0)
		{
			//if (selfCheck())//先自检自身是否被击毁
				tankMove(); //然后再移动
		}
		else if (direction != DOWN)
		{
			direction = DOWN;
			putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
		}
		break;                                          
	case LEFT:   //坦克向左
		if (direction == LEFT && (tank_x - 1) >= 0 && Map::map[tank_y][tank_x - 1] == 0 && Map::map[tank_y + 1][tank_x - 1] == 0)
		{
			//if (selfCheck())//先自检自身是否被击毁
				tankMove(); //然后再移动
		}
		else if (direction != LEFT)
		{
			direction = LEFT;
			putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
		}
		break;                                               
	case RIGHT:  //坦克向右
		if (direction == RIGHT && (tank_x + 2) <= 25 && Map::map[tank_y][tank_x + 2] == 0 && Map::map[tank_y + 1][tank_x + 2] == 0)
		{
			//if (selfCheck())//先自检自身是否被击毁
				tankMove(); //然后再移动
		}
		else if (direction != RIGHT)
		{
			direction = RIGHT;
			putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
		}
		break;
	}
}

void Tank::tankBoom()
{
	PlaySound(_T("paoji.wav"), NULL, SND_FILENAME | SND_ASYNC);
	IMAGE img[8];

	loadimage(&img[0], _T("blast1.gif"), 50, 50);
	loadimage(&img[1], _T("blast2.gif"), 50, 50);
	loadimage(&img[2], _T("blast3.gif"), 50, 50);
	loadimage(&img[3], _T("blast4.gif"), 50, 50);
	loadimage(&img[4], _T("blast5.gif"), 50, 50);
	loadimage(&img[5], _T("blast6.gif"), 50, 50);
	loadimage(&img[6], _T("blast7.gif"), 50, 50);
	loadimage(&img[7], _T("blast8.gif"), 50, 50);
	for (int i = 0; i < 8; i++)
	{
		putimage(tank_x * 25, tank_y * 25, &img[i]);
		Sleep(10);
	}
	setfillcolor(BLACK);
	solidrectangle(tank_x * 25, tank_y * 25, tank_x * 25 + 50, tank_y * 25 + 50);
}

void PlayerTank::tankFire()
{
	if (!bullet.state) //控制依次只能发射一个子弹
	{
		PlaySound(_T("hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
		switch (direction)
		{
		case UP:
			bullet.bullet_x = tank_x * 25 + 23;
			bullet.bullet_y = tank_y * 25 - 5;
			break;
		case DOWN:
			bullet.bullet_x = tank_x * 25 + 23;
			bullet.bullet_y = tank_y * 25 + 55;
			break;
		case LEFT:
			bullet.bullet_x = tank_x * 25 - 5;
			bullet.bullet_y = tank_y * 25 + 23;
			break;
		case RIGHT:
			bullet.bullet_x = tank_x * 25 + 55;
			bullet.bullet_y = tank_y * 25 + 23;
			break;
		}
		bullet.state = true;
		bullet.direction = direction;
		putimage(bullet.bullet_x, bullet.bullet_y, &bullet.bulletImage);
	}
}

void PlayerTank::tankMove()
{
	mapModify(0); //将移动之前的地方设为0  即路
	setfillcolor(BLACK); //设置填充颜色
	solidrectangle(tank_x * 25, tank_y * 25, tank_x * 25 + 50, tank_y * 25 + 50);  //覆盖坦克原来位置
	if (direction == UP)
	{
		tank_y--;
	}
	else if (direction == DOWN)
	{
		tank_y++;
	}
	else if (direction == LEFT)
	{
		tank_x--;
	}
	else if (direction == RIGHT)
	{
		tank_x++;
	}
	mapModify(6); //移动后将此处设为6 代表己方坦克
	putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
}

void PlayerTank::controlTank() //控制己方坦克
{
	if (_kbhit())
	{
		char key = _getch();  //获取键盘输入值
		switch (key)
		{
		case 'w': //操控坦克向上                                  
		case 'W':
			actuallyMove(UP);
			break;
		case 's': //操控坦克向下                                      
		case 'S':
			actuallyMove(DOWN);
			break;
		case 'a': //操控坦克向左                                          
		case 'A':
			actuallyMove(LEFT);
			break;
		case 'd': //操控坦克向右                                          
		case 'D':
			actuallyMove(RIGHT);
			break;
		case 'p': //暂停游戏，按任意键开始                                                  
		case 'P':
			system("pause");
			break;
		case 'j':  //射击                                              
		case 'J': 
			tankFire();
			break;
		}
	}
}

void EnemyTank1::tankFire()
{
	if (!bullet.state) //控制依次只能发射一个子弹
	{
		//PlaySound(_T("boom.wav"), NULL, SND_FILENAME | SND_ASYNC);
		switch (direction)
		{
		case UP:
			bullet.bullet_x = tank_x * 25 + 23;
			bullet.bullet_y = tank_y * 25 - 5;
			break;
		case DOWN:
			bullet.bullet_x = tank_x * 25 + 23;
			bullet.bullet_y = tank_y * 25 + 55;
			break;
		case LEFT:
			bullet.bullet_x = tank_x * 25 - 5;
			bullet.bullet_y = tank_y * 25 + 23;
			break;
		case RIGHT:
			bullet.bullet_x = tank_x * 25 + 55;
			bullet.bullet_y = tank_y * 25 + 23;
			break;
		}
		bullet.state = true;
		bullet.direction = direction;
		putimage(bullet.bullet_x, bullet.bullet_y, &bullet.bulletImage);
	}
}

void EnemyTank2::tankFire()
{
	if (!bullet.state) //控制依次只能发射一个子弹
	{
		//PlaySound(_T("boom.wav"), NULL, SND_FILENAME | SND_ASYNC);
		switch (direction)
		{
		case UP:
			bullet.bullet_x = tank_x * 25 + 23;
			bullet.bullet_y = tank_y * 25 - 5;
			break;
		case DOWN:
			bullet.bullet_x = tank_x * 25 + 23;
			bullet.bullet_y = tank_y * 25 + 55;
			break;
		case LEFT:
			bullet.bullet_x = tank_x * 25 - 5;
			bullet.bullet_y = tank_y * 25 + 23;
			break;
		case RIGHT:
			bullet.bullet_x = tank_x * 25 + 55;
			bullet.bullet_y = tank_y * 25 + 23;
			break;
		}
		bullet.state = true;
		bullet.direction = direction;
		putimage(bullet.bullet_x, bullet.bullet_y, &bullet.bulletImage);
	}
}

//操控坦克朝目的地前进(改变坦克的方向)
void Tank::toDestination(int x, int y) 
{
	int r = rand() % 100;
	if (y < tank_y)
	{
		if (x < tank_x)
		{
			if (r < 50)
				direction = UP;
			else
				direction = LEFT;
		}
		else if (x > tank_x)
		{
			if (r < 50)
				direction = UP;
			else
				direction = RIGHT;
		}
		else if (x == tank_x)
		{
			if (Map::map[tank_y][tank_x] == 2)
			{
				if (r < 50)
					direction = LEFT;
				else
					direction = RIGHT;
			}
			direction = UP;
		}
	}
	else if (y > tank_y)
	{
		if (x < tank_x)
		{
			if (r < 50)
				direction = DOWN;
			else
				direction = LEFT;
		}
		else if (x > tank_x)
		{
			if (r < 50)
				direction = DOWN;
			else
				direction = RIGHT;
		}
		else if (x == tank_x)
		{
			if (Map::map[tank_y][tank_x] == 2)
			{
				if (r < 50)
					direction = LEFT;
				else
					direction = RIGHT;
			}
			direction = DOWN;
		}
	}
	else if (y == tank_y)
	{
		if (x < tank_x)
			direction = LEFT;
		else
			direction = RIGHT;
	}
}