#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 100

void test01(int *arr,int len)
{
	for (int i = 0; i < len; i++)
	{
	FLAG:
		int temp = rand() % MAX + 1;
		for (int j = 0; j <= i; j++)
		{
			if (arr[j] == temp)
				goto FLAG;
		}
		arr[i] = temp;
	}
}

void test02(int* arr, int len)
{
	int Used[MAX + 1];

	for (int i = 0; i < len; i++)
	{
		int flag = 1;
		while (flag)
		{
			int temp = rand() % MAX + 1;
			if (Used[temp] != 1)
			{
				arr[i] = temp;
				Used[temp] = 1;
				flag = 0;
			}
		}		
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100];
	int len = sizeof(arr) / sizeof(arr[0]);

	test02(arr, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}