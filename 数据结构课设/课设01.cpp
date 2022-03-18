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
				printf("■");
			else
				printf("  ");
		putchar('\n');
	}
}

int mazepath(int maze[][N + 2], item move[], int x0, int y0)
{
	//求迷宫路径，入口参数：指向迷宫数组的指针，下标移动的增量数组，开始点（x0，y0），
	//到达（m，n），返回值：1表示出口路径，0表示无路径
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
		d = temp.d + 1; //更新方向	
		while (d < 4)
		{
			i = x + move[d].x;  //下一个方向的坐标
			j = y + move[d].y;
			if (maze[i][j] == 0)  //若为路，则继续前进
			{
				temp.x = x;
				temp.y = y;
				temp.d = d;
				pushSeqStack(S, temp);
				x = i;
				y = j;
				maze[x][y] = -1; //将位置元素置为-1 表示该位置已走过，避免重复探寻
				if (x == M || y == N) //到达出口
				{
					temp.x = x;
					temp.y = y;
					temp.d = d;
					pushSeqStack(S, temp);
					while (!isEmptySeqStack(S))
					{
						temp = getTopSeqStack(S);
						//将光标移到对应位置
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), 
							COORD{ (short)(temp.y * 2 - 2), (short)(temp.x - 1) });
						//printf("(%d,%d)<-", temp.x, temp.y);
						printf("%d", S->top + 1); //输出信息
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
		printf("路径如上图序号所示");
	}
	else
		printf("未找到路径！");

	return 0;
}