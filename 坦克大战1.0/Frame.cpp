#include"Frame.h"
#include"Map.h"
#include<graphics.h>
#pragma comment(lib,"winmm.lib")  //����������
//#include"Tank.h"

void Frame::startFrame() //��Ϸ��ʼ����
{
	PlaySound(_T("background.wav"), NULL, SND_FILENAME | SND_ASYNC);
	IMAGE logoImg;
	loadimage(&logoImg, _T("logo.bmp"), 433, 147);
	putimage(113, 40, &logoImg); //����TANK logo

	IMAGE illustrate;
	loadimage(&illustrate, _T("illustrate.jpg"), 300, 300); //����˵��ͼƬ
	settextcolor(RGB(255, 255, 255));
	settextstyle(30, 0, _T("΢���ź�"));
	rectangle(195, 200, 275, 240);
	rectangle(375, 200, 455, 240);
	outtextxy(210, 205, _T("˵ ��"));
	outtextxy(390, 205, _T("�� ʼ"));

	//  �������¼�
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE: //����ƶ�
			if ((m.x >= 195 && m.x <= 275) && (m.y >= 200 && m.y <= 240))
			{
				putimage(150, 250, &illustrate); //���ò���˵��ͼƬ
			}
			else
			{
				setfillcolor(BLACK);
				solidrectangle(150, 250, 450, 550);
			}
			break;

		case WM_LBUTTONDOWN: //�����
			if ((m.x >= 375 && m.x <= 455) && (m.y >= 200 && m.y <= 240))
			{
				cleardevice();
				return;
			}
			break;
		}
	}
}

void Frame::gameOver() //��Ϸ��������
{
	IMAGE gameOver;
	loadimage(&gameOver, _T("gameover.jpg"), 600, 400);
	for (int i = 0; i < 130; i++) //�Ӵ����Ϸ��»�Ч��
	{
		cleardevice();
		putimage(25, i, &gameOver);
		Sleep(15);
	}
	system("pause"); //����ͣ��
}

void Frame::victory() //���ʤ������
{
	cleardevice();
	settextcolor(RED);
	settextstyle(300, 70, _T("΢���ź�"));
	outtextxy(80, 150, _T("Victory"));
	system("pause");
}

void Frame::playFrame()
{
	const int TOTALNUMBER = 10; //�趨�ĵз�̹��1����

	startFrame(); //��ʼ����
	Map::loadMap(); //���ص�ͼ

	bool flag = true; //�ж���Ϸ�Ƿ���� ��10��̹��1������ʤ��

	int times = 0;    //��¼��ǰ��������ߴ���
	int enemyTotal = 0; //�Ѽ��ص���ͼ�ϵ�̹������
	int enemyalive = TOTALNUMBER; //�ܴ��̹����

	EnemyTank1 et[TOTALNUMBER]; //������10����һ�ֵз�̹��
	EnemyTank2 et2_1,et2_2;

	et2_1.initEnemyTank2(0, 8); //��ʼ���ڶ��ֵз�̹��
	et2_2.initEnemyTank2(24, 8);

	PlayerTank pt; //�������̹��
	for (int i = 0; i < TOTALNUMBER; i++) //��ʼ�����ез�̹��1
	{		
		if (i % 3 == 0)
			et[i].initEnemyTank1(0, 0);
		else if (i % 3 == 1)
			et[i].initEnemyTank1(12, 0);
		else if (i % 3 == 2)
			et[i].initEnemyTank1(24, 0);
	}

	enemyTotal = 3; //����̹������
	for (int i = 0; i < enemyTotal; i++) //����3��̹��
	{
		et[i].putImage(); //����̹��ͼƬ
	}

	while (true)
	{		
		//�ǳ�����̹��1
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
		//̹��2�ǳ�
		if (times == 1500) 
		{
			et2_1.putImage();
			et2_2.putImage();
		}
		//̹��2�ƶ�������
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

		// ���Ƶз�̹�˸ı䷽��
		if (times % 200 == 0)
		{
			for (int i = 0; i < enemyTotal; i++)
			{
				if (et[i].HP>0)
				{
					if (i % 2 == 0)        //˫��̹�˹����ҷ��ϳ�
					{
						et[i].toDestination(12, 24);
						et[i].actuallyMove(et[i].direction);
					}
					else                    //����̹�˹����ҷ�̹��
					{
						et[i].toDestination(pt.tank_x, pt.tank_y);
						et[i].actuallyMove(et[i].direction);
					}
					et[i].tankFire();
				}
			}
		}
		else if (times % 20 == 0)   //���Ƶз�̹���ƶ�
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

		pt.selfCheck(); //���̹���Լ��Ƿ񱻴ݻ�

		if (times >= 1500)
		{
			et2_1.selfCheck(); //�з�̹��2�Լ��Ƿ񱻴ݻ�
			et2_2.selfCheck();
		}


		for (int i = 0; i < enemyTotal; i++)
		{
			et[i].selfCheck();	//�з�̹��1�Լ��Ƿ񱻴ݻ�		

			if (et[i].bullet.state)  //�ӵ�����ʱ�����µз��ӵ�����λ��
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

		if (enemyalive == 0)  //�ж���Ϸ�Ƿ�ʤ��
		{
			victory();
			break;
		}
		else
			enemyalive = TOTALNUMBER;

		if (et2_1.bullet.state)
		{
			flag = et2_1.bullet.bulletMove(); //̹��2�ӵ��ƶ�
			if (flag == false)
				gameOver();
		}

		if (et2_2.bullet.state)
		{
			flag = et2_2.bullet.bulletMove(); //̹��2�ӵ��ƶ�
			if (flag == false)
				gameOver();
		}
		if (pt.bullet.state)            //�ӵ�����ʱ�������ҷ��ӵ�����λ��
			pt.bullet.bulletMove();	
		
		pt.controlTank(); //��Ҳٿ�̹��	
		times++; //��ʱ����һ
		Sleep(15);
	}
}