#include<stdio.h>
#include<time.h>
#include <stdlib.h>

//ѡ�����⣺����һ������Ҫȷ�����еĵ�k�������
//�㷨1

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
	//��ǰk�������н�������
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
	//��ʣ�µ�Ԫ�����k��Ԫ�ضԱ�
	for (int i = k; i < len; i++)
	{
		if (arr[i] > arr[k - 1])
		{
			for (int j = 0; j < k; j++)
			{
				//���뵽��ȷ��λ��
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

	//selection02��������
	//printf("%d\n", selection01(arr, len, 4));
	printf("%d", selection02(arr, len, 500));

	return 0;
}