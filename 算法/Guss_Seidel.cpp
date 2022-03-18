#include<stdio.h>

//高斯-赛德尔迭代法
void Guss_Seidel()
{
	//t[1][1] t[1][2] t[2][1] t[2][2]分别是t1 t2 t3 t4
	float t[4][4] =
	{
		{0,500,500,0},
		{100,300,300,100},
		{100,200,200,100},
		{0,100,100,0}
	};

	printf("近似值\tt1\tt2\tt3\tt4\n");
	printf("第0次\t");
	for (int i = 1; i < 3; i++)
		for (int j = 1; j < 3; j++)
			printf("%.2f\t", t[i][j]);
	putchar('\n');
	int times[2][2] = {0}; //记录节点温度值之差小于0.5的次数
	int count = 0; //记录计算次数
	while (true)
	{
		count++;
		for (int i = 1; i < 3; i++)
		{
			for (int j = 1; j < 3; j++)
			{
				float lastTemperatrue = t[i][j]; //记录上一次温度
				//高斯-赛德尔迭代公式
				t[i][j] = (t[i - 1][j] + t[i + 1][j] + t[i][j - 1] + t[i][j + 1]) / 4;

				if ((lastTemperatrue - t[i][j]) < 0.5)
					times[i - 1][j - 1]++;

				if (times[0][0] == 2 && times[0][1] == 2 && times[1][0] == 2 && times[1][1] == 2)
					return;
			}		
		}
		printf("第%d次\t",count);
		for (int i = 1; i < 3; i++)
			for (int j = 1; j < 3; j++)
				printf("%.2f\t", t[i][j]);
		putchar('\n');
	}	
}

int main()
{
	Guss_Seidel();

	return 0;
}