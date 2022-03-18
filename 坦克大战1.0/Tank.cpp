#include<graphics.h>
#include"Map.h"
#include"Tank.h"
#include <conio.h>
#include<ctime>
#pragma comment(lib,"winmm.lib") //����������

PlayerTank::PlayerTank() //����̹�˳�ʼ��
{
	tank_x = 8;  //�������������ڣ�8��24����һ��ǽ�Ĵ�С��
	tank_y = 24;
	direction = UP; //��ʼ����Ϊ��
	HP = 1; //��ʼѪ��Ϊ1
	mapModify(6);
	
	loadimage(&Tank_img[UP], _T("tank_up.jpg"), 50, 50);
	loadimage(&Tank_img[DOWN], _T("tank_down.jpg"), 50, 50);
	loadimage(&Tank_img[LEFT], _T("tank_left.jpg"), 50, 50);
	loadimage(&Tank_img[RIGHT], _T("tank_right.jpg"), 50, 50);
	putImage();
}

void EnemyTank1::initEnemyTank1(int x,int y) //�з�̹��1��ʼ��
{
	tank_x = x;
	tank_y = y;
	direction = DOWN;
	HP = 1; //��ʼѪ��Ϊ1
	loadimage(&Tank_img[UP], _T("enemy_tank_up.gif"), 50, 50);
	loadimage(&Tank_img[DOWN], _T("enemy_tank_down.gif"), 50, 50);
	loadimage(&Tank_img[LEFT], _T("enemy_tank_left.gif"), 50, 50);
	loadimage(&Tank_img[RIGHT], _T("enemy_tank_right.gif"), 50, 50);
	//putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
}

void EnemyTank2::initEnemyTank2(int x, int y) //�з�̹��2��ʼ��
{
	tank_x = x;
	tank_y = y;
	direction = DOWN;
	HP = 2; //��ʼѪ��Ϊ2

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

void Tank::mapModify(int n) //�޸ĵ�ͼ����
{
	Map::map[tank_y][tank_x] = n;
	Map::map[tank_y + 1][tank_x] = n;
	Map::map[tank_y][tank_x + 1] = n;
	Map::map[tank_y + 1][tank_x + 1] = n;
}

void Tank::tankMove() //̹���ƶ�
{
	mapModify(0); //���ƶ�֮ǰ�ĵط���Ϊ0  ��·
	setfillcolor(BLACK); //���������ɫ
	solidrectangle(tank_x * 25,tank_y * 25,tank_x * 25 + 50,tank_y * 25 + 50);  //����̹��ԭ��λ��
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
	mapModify(5); //�ƶ��󽫴˴���Ϊ5 ����з�̹��
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
				mapModify(0); //����ռ��ͼȫ������
				tankBoom(); //����̹�˱�ը����
				return false;
			}
			else
				mapModify(5);
		}
	}
	return true;
}

void Tank::actuallyMove(int keyDirection) //ʵ���ƶ�
{
	switch (keyDirection) //tank_x��tank_yʼ����̹�˵����Ͻ�
	{                                  
	case UP:   //̹������
		if (direction == UP && (tank_y - 1) >= 0 && Map::map[tank_y - 1][tank_x] == 0 && Map::map[tank_y - 1][tank_x + 1] == 0)
		{			
			//if (selfCheck())//���Լ������Ƿ񱻻���
				tankMove(); //Ȼ�����ƶ�
		}
		else if (direction != UP)
		{
			direction = UP;
			putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
		}
		break;                                      
	case DOWN:  //̹������
		if (direction == DOWN && (tank_y + 2) <= 25 && Map::map[tank_y + 2][tank_x] == 0 && Map::map[tank_y + 2][tank_x + 1] == 0)
		{
			//if (selfCheck())//���Լ������Ƿ񱻻���
				tankMove(); //Ȼ�����ƶ�
		}
		else if (direction != DOWN)
		{
			direction = DOWN;
			putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
		}
		break;                                          
	case LEFT:   //̹������
		if (direction == LEFT && (tank_x - 1) >= 0 && Map::map[tank_y][tank_x - 1] == 0 && Map::map[tank_y + 1][tank_x - 1] == 0)
		{
			//if (selfCheck())//���Լ������Ƿ񱻻���
				tankMove(); //Ȼ�����ƶ�
		}
		else if (direction != LEFT)
		{
			direction = LEFT;
			putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
		}
		break;                                               
	case RIGHT:  //̹������
		if (direction == RIGHT && (tank_x + 2) <= 25 && Map::map[tank_y][tank_x + 2] == 0 && Map::map[tank_y + 1][tank_x + 2] == 0)
		{
			//if (selfCheck())//���Լ������Ƿ񱻻���
				tankMove(); //Ȼ�����ƶ�
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
	if (!bullet.state) //��������ֻ�ܷ���һ���ӵ�
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
	mapModify(0); //���ƶ�֮ǰ�ĵط���Ϊ0  ��·
	setfillcolor(BLACK); //���������ɫ
	solidrectangle(tank_x * 25, tank_y * 25, tank_x * 25 + 50, tank_y * 25 + 50);  //����̹��ԭ��λ��
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
	mapModify(6); //�ƶ��󽫴˴���Ϊ6 ������̹��
	putimage(tank_x * 25, tank_y * 25, &Tank_img[direction]);
}

void PlayerTank::controlTank() //���Ƽ���̹��
{
	if (_kbhit())
	{
		char key = _getch();  //��ȡ��������ֵ
		switch (key)
		{
		case 'w': //�ٿ�̹������                                  
		case 'W':
			actuallyMove(UP);
			break;
		case 's': //�ٿ�̹������                                      
		case 'S':
			actuallyMove(DOWN);
			break;
		case 'a': //�ٿ�̹������                                          
		case 'A':
			actuallyMove(LEFT);
			break;
		case 'd': //�ٿ�̹������                                          
		case 'D':
			actuallyMove(RIGHT);
			break;
		case 'p': //��ͣ��Ϸ�����������ʼ                                                  
		case 'P':
			system("pause");
			break;
		case 'j':  //���                                              
		case 'J': 
			tankFire();
			break;
		}
	}
}

void EnemyTank1::tankFire()
{
	if (!bullet.state) //��������ֻ�ܷ���һ���ӵ�
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
	if (!bullet.state) //��������ֻ�ܷ���һ���ӵ�
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

//�ٿ�̹�˳�Ŀ�ĵ�ǰ��(�ı�̹�˵ķ���)
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