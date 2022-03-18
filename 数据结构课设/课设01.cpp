#include<iostream>
#include<Windows.h>
#include"SeqStack.h"

#define M 10
#define N 18
int maze[M + 2][N + 2] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
	{1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1},
	{1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

typedef struct
{
	int x, y;
}item;
item myMove[4];

void printMaze(int maze[][N + 2])
{
	for (int i = 1; i < M + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
			if (maze[i][j] == 1)
				printf("��");
			else
				printf("  ");
		putchar('\n');
	}
}

int mazepath(int maze[][N + 2], item move[], int x0, int y0)
{
	//���Թ�·������ڲ�����ָ���Թ������ָ�룬�±��ƶ����������飬��ʼ�㣨x0��y0����
	//���m��n��������ֵ��1��ʾ����·����0��ʾ��·��
	pSeqStack S = initSeqStack();
	DataType temp;
	int x, y, d, i, j;
	temp.x = x0;
	temp.y = y0;
	temp.d = -1;
	pushSeqStack(S, temp);

	while (!isEmptySeqStack(S))
	{
		temp = popSeqStack(S);
		x = temp.x;
		y = temp.y;
		d = temp.d + 1; //���·���	
		while (d < 4)
		{
			i = x + move[d].x;  //��һ�����������
			j = y + move[d].y;
			if (maze[i][j] == 0)  //��Ϊ·�������ǰ��
			{
				temp.x = x;
				temp.y = y;
				temp.d = d;
				pushSeqStack(S, temp);
				x = i;
				y = j;
				maze[x][y] = -1; //��λ��Ԫ����Ϊ-1 ��ʾ��λ�����߹��������ظ�̽Ѱ
				if (x == M || y == N) //�������
				{
					temp.x = x;
					temp.y = y;
					temp.d = d;
					pushSeqStack(S, temp);
					while (!isEmptySeqStack(S))
					{
						temp = getTopSeqStack(S);
						//������Ƶ���Ӧλ��
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), 
							COORD{ (short)(temp.y * 2 - 2), (short)(temp.x - 1) });
						//printf("(%d,%d)<-", temp.x, temp.y);
						printf("%d", S->top + 1); //�����Ϣ
						popSeqStack(S);
					}
					destroySeqStack(&S);
					return 1;
				}
				else
					d = 0;
			}
			else
				d++;
		}
	}
	destroySeqStack(&S);
	return 0;
}

int main()
{
	myMove[0].x = 0;	myMove[0].y = 1;
	myMove[1].x = 1;	myMove[1].y = 0;
	myMove[2].x = 0;	myMove[2].y = -1;
	myMove[3].x = -1;	myMove[3].y = 0;
	printMaze(maze);
	if (mazepath(maze, myMove, 1, 2) == 1)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ (short)0, (short)M });
		printf("·������ͼ�����ʾ");
	}
	else
		printf("δ�ҵ�·����");

	return 0;
}