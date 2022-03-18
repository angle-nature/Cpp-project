#include<stdio.h>
#include<time.h>
#include <stdlib.h>

//选择问题：设有一组数而要确定其中的第k个最大者
//算法1

int selection01(int* arr, int len, int k)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] < arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	return arr[k - 1];
}

int selection02(int* arr, int len, int k)
{
	//对前k个数进行降序排列
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = 0; j < k - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	//将剩下的元素与第k个元素对比
	for (int i = k; i < len; i++)
	{
		if (arr[i] > arr[k - 1])
		{
			for (int j = 0; j < k; j++)
			{
				//插入到正确的位置
				if (arr[i]<arr[j] && arr[i]>arr[j + 1])
				{
					for (int m = k-1; m > j+1; m--)
					{
						arr[m] = arr[m - 1];
					}
					arr[j + 1] = arr[i];
				}					
			}
			
		}
	}
	return arr[k - 1];
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[1000];
	for (int i = 0; i < 1000; i++)
	{
		arr[i] = rand() % 1000 + 1;
	}
	int len = sizeof(arr) / sizeof(arr[0]);

	//selection02函数更快
	//printf("%d\n", selection01(arr, len, 4));
	printf("%d", selection02(arr, len, 500));

	return 0;
}