#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 100

//随机赋值
void test01(int* arr, int len)
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

//升序排序
void sort(int* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//二分查找
int binarySeach(int *arr, int len, int i)
{
	int left = 0, right = len - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (i < arr[mid])
		{
			right = mid - 1;
		}
		else if (i > arr[mid])
		{
			left = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100];
	int len = sizeof(arr) / sizeof(arr[0]);

	test01(arr, len);
	sort(arr, len);
	int pos=binarySeach(arr, len, 62);

	if (pos == -1)
		printf("没找到该数字");
	else
		printf("找到该数字，arr[%d]=%d", pos, arr[pos]);

	return 0;
}