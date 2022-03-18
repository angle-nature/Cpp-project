#include"Bullet.h"
#include"Map.h"
#include<graphics.h>

Bullet1::Bullet1()
{
	bullet_x = 0;
	bullet_y = 0;
	state = false;
	direction = UP;
	loadimage(&bulletImage, _T("����ӵ�.bmp"), 4, 4);	
}

Bullet2::Bullet2()
{
	bullet_x = 0;
	bullet_y = 0;
	state = false;
	direction = UP;
	loadimage(&bulletImage, _T("�����ӵ�.bmp"), 4, 4);
}

bool Bullet1::bulletMove() //�ӵ��ƶ�����ײ���
{
	bool flag = true;
	IMAGE Wall2;
	loadimage(&Wall2, _T("wall2.jpg"), 25, 25);
	setfillcolor(BLACK);
	solidrectangle(bullet_x , bullet_y, bullet_x +4, bullet_y +4); //�����ӵ�
	int x1, y1, x2, y2;
	x1 = bullet_x / 25;
	y1 = bullet_y / 25;
	switch (direction) //�ж��ӵ�����
	{
	case UP:
		bullet_y -= 3;
		x2 = x1 + 1;
		y2 = y1;
		break;
	case DOWN:
		bullet_y += 3;
		x2 = x1 + 1;
		y2 = y1;
		break;
	case LEFT:
		bullet_x -= 3;
		x2 = x1;
		y2 = y1 + 1;
		break;
	case RIGHT:
		bullet_x += 3;
		x2 = x1;
		y2 = y1 + 1;
		break;
	}
	
	if (bullet_x < 0 || bullet_x>650 || bullet_y < 0 || bullet_y>650)
	{
		state = false;
		return true;
	}

	//�ӵ�����������ǽ������ǽ��ͬʱ���ӵ���״̬��Ϊ 0  
	if (Map::map[y1][x1] == 1 && Map::map[y2][x2] == 1)
	{
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
		solidrectangle(x2 * 25, y2 * 25, x2 * 25 + 25, y2 * 25 + 25);
		Map::map[y1][x1] = 0;
		Map::map[y2][x2] = 0;
		state = false;
	}
	else if (Map::map[y1][x1] == 1 && Map::map[y2][x2] == 0)
	{
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
		solidrectangle(x2 * 25, y2 * 25, x2 * 25 + 25, y2 * 25 + 25);
		Map::map[y1][x1] = 0;
		state = false;
	}
	else if (Map::map[y1][x1] == 0 && Map::map[y2][x2] == 1)
	{
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
		solidrectangle(x2 * 25, y2 * 25, x2 * 25 + 25, y2 * 25 + 25);
		Map::map[y2][x2] = 0;
		state = false;
	}
	else if (Map::map[y1][x1] == 2 && Map::map[y2][x2] == 2)   //�ӵ�������������ǽ�����»��ư�ǽͼƬ������ǽ�ϻ��е��ӣ��������ӵ�״̬Ϊ0
	{
		putimage(x1 * 25, y1 * 25, &Wall2);
		putimage(x2 * 25, y2 * 25, &Wall2);
		state = false;
	}
	else if (Map::map[y1][x1] == 2 && Map::map[y2][x2] != 2)
	{
		putimage(x1 * 25, y1 * 25, &Wall2);
		setfillcolor(BLACK);
		solidrectangle(x2 * 25, y2 * 25, x2 * 25 + 25, y2 * 25 + 25);
		state = false;
	}
	else if (Map::map[y1][x1] != 2 && Map::map[y2][x2] == 2)
	{
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
		putimage(x2 * 25, y2 * 25, &Wall2);
		state = false;
	}
	else if (Map::map[y1][x1] == 4 && Map::map[y2][x2] == 4) //�ϳ�
	{
		return false;
	}
	else if (Map::map[y1][x1] == 5 || Map::map[y2][x2] == 5) //�з�̹��
	{
		Map::map[y1][x1] = 0;
		Map::map[y2][x2] = 0;
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
		state = false;
	}
	else if (Map::map[y1][x1] == 6 || Map::map[y2][x2] == 6) //����̹��
	{
		state = false;
	}

	if(state)
		putimage(bullet_x, bullet_y, &bulletImage);

	return flag;
}

bool Bullet2::bulletMove() //�ӵ��ƶ�����ײ���
{
	bool flag = true;
	IMAGE Wall2;
	loadimage(&Wall2, _T("wall2.jpg"), 25, 25);
	setfillcolor(BLACK);
	solidrectangle(bullet_x, bullet_y, bullet_x + 4, bullet_y + 4); //�����ӵ�
	int x1, y1, x2, y2;
	x1 = bullet_x / 25;
	y1 = bullet_y / 25;
	switch (direction) //�ж��ӵ�����
	{
	case UP:
		bullet_y -= 3;
		x2 = x1 + 1;
		y2 = y1;
		break;
	case DOWN:
		bullet_y += 3;
		x2 = x1 + 1;
		y2 = y1;
		break;
	case LEFT:
		bullet_x -= 3;
		x2 = x1;
		y2 = y1 + 1;
		break;
	case RIGHT:
		bullet_x += 3;
		x2 = x1;
		y2 = y1 + 1;
		break;
	}
	
	if (bullet_x < 0 || bullet_x > 650 || bullet_y < 0 || bullet_y > 650)
	{
		state = false;
	}

	//***************  �ӵ�����������ǽ������ǽ��ͬʱ���ӵ���״̬��Ϊ 0  
	if (Map::map[y1][x1] == 1 && Map::map[y2][x2] == 1)
	{
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
		solidrectangle(x2 * 25, y2 * 25, x2 * 25 + 25, y2 * 25 + 25);
		Map::map[y1][x1] = 0;
		Map::map[y2][x2] = 0;
		state = false;
	}
	else if (Map::map[y1][x1] == 1 && Map::map[y2][x2] == 0)
	{
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
		solidrectangle(x2 * 25, y2 * 25, x2 * 25 + 25, y2 * 25 + 25);
		Map::map[y1][x1] = 0;
		state = false;
	}
	else if (Map::map[y1][x1] == 0 && Map::map[y2][x2] == 1)
	{
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
		solidrectangle(x2 * 25, y2 * 25, x2 * 25 + 25, y2 * 25 + 25);
		Map::map[y2][x2] = 0;
		state = false;
	}
	else if (Map::map[y1][x1] == 2 && Map::map[y2][x2] == 2)   //�ӵ�������������ǽ�����»��ư�ǽͼƬ������ǽ�ϻ��е��ӣ��������ӵ�״̬Ϊ0
	{
		putimage(x1 * 25, y1 * 25, &Wall2);
		putimage(x2 * 25, y2 * 25, &Wall2);
		state = false;
	}
	else if (Map::map[y1][x1] == 2 && Map::map[y2][x2] != 2)
	{
		putimage(x1 * 25, y1 * 25, &Wall2);
		setfillcolor(BLACK);
		solidrectangle(x2 * 25, y2 * 25, x2 * 25 + 25, y2 * 25 + 25);
		state = false;
	}
	else if (Map::map[y1][x1] != 2 && Map::map[y2][x2] == 2)
	{
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
		putimage(x2 * 25, y2 * 25, &Wall2);
		state = false;
	}
	else if (Map::map[y1][x1] == 4 && Map::map[y2][x2] == 4) //�ϳ�
	{
		flag = false;
	}
	else if (Map::map[y1][x1] == 5 || Map::map[y2][x2] == 5) //�з�̹�� ����û������
	{
		//Map::map[y1][x1] = 0;
		//Map::map[y2][x2] = 0;
		//setfillcolor(BLACK);
		//solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
		state = false;
	}else if (Map::map[y1][x1] == 6 || Map::map[y2][x2] == 6) //����̹��
	{
		Map::map[y1][x1] = 0;
		Map::map[y2][x2] = 0;
		//setfillcolor(BLACK);
		//solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
		state = false;
		flag = false;
	}

	if(state)
		putimage(bullet_x, bullet_y, &bulletImage);

	return flag;
}