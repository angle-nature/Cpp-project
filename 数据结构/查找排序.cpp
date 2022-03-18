#include<stdio.h>
#include<time.h>
#include <stdlib.h>

#define SIZE 30
#define NOFIND -1

void printArray(int* a)
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%4d", a[i]);
		if ((i + 1) % 10 == 0)
			putchar('\n');
	}
}

int orderFind(int *a,int X) //顺序查找
{
	for (int i = 0; i < SIZE; i++)
	{
		if (a[i] == X)
			return i;
	}
	return NOFIND;
}

void insertSort(int* a) //插入排序(升序)
{
	for (int i = 1; i < SIZE; i++)
	{	
		int temp = a[i];
		int j;
		for (j = i - 1; a[j] > temp; j--)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}
}

int Partition(int a[], int p, int r) //快排
{
	int i = p + 1, j = r;
	int key = a[p];
	// 将< x的元素交换到左边区域
	// 将> x的元素交换到右边区域
	while (true && (i <= j)) {
		while (a[i] < key) { i++; } //找到比关键字大的
		while (a[j] > key) { j--; } //找到比关键字小的
		if (i >= j) break;

		int  temp = a[i]; //交换a[i]和a[j]
		a[i] = a[j];
		a[j] = temp;

		i++;
		j--;
	}
	a[p] = a[j];
	a[j] = key;
	return j;
}

void quickSort(int a[], int p, int r) //快速排序
{
	if (p < r) {
		int q = Partition(a, p, r); //取中间下标
		quickSort(a, p, q - 1); //对左半段排序
		//for (int i = p; i < q; i++)
		//{
		//	printf("%d  ", a[i]);
		//}
		//printf("\n");
		quickSort(a, q + 1, r); //对右半段排序
		//for (int i = q + 1; i < r + 1; i++)
		//{
		//	printf("%d  ", a[i]);
		//}
		//printf("\n");
	}
}

void shellInsert(int *a,int gap)
{
	for (int i = gap; i < SIZE; i++)
	{
		if (a[i] < a[i - gap])
		{
			int j;
			int temp = a[i];
			for (j = i - gap; j > 0 && temp < a[j]; j = j - gap)
				a[j + gap] = a[j];
			a[j + gap] = temp;
		}
	}
}

void shellSort(int* a, int* gaps, int lenth)
{
	for (int k = 0; k < lenth; k++)
		shellInsert(a, gaps[k]);
}

int binaryFind(int* a,int X) //折半查找
{
	int left = 0;
	int right = SIZE - 1;

	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == X)
			return mid;
		else if (a[mid] < X)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return NOFIND;
}

void bubbleSort(int* a) //冒泡排序(升序)
{
	for (int i = 0; i < SIZE-1; i++)
	{
		for (int j = 0; j < SIZE-i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int a[SIZE];
	int gaps[3] = { 5,3,1 };
	for (int i = 0; i < 30; i++)
		a[i] = rand() % 100 + 1;
	printf("排序前：\n");
	printArray(a);
	printf("======================\n冒泡排序后：\n");
	bubbleSort(a); //冒泡排序
	printArray(a);
	printf("======================\n插入排序后：\n");
	insertSort(a); //插入排序
	printArray(a);
	printf("======================\n快速排序后：\n");
	quickSort(a, 0, 29); //快速排序
	printArray(a);
	printf("======================\n希尔排序后：\n");
	shellSort(a, gaps, 3); //希尔排序
	printArray(a);
	int X = 37;
	printf("顺序查找%d为：%d\n", X, orderFind(a, X));
	printf("折半查找%d为：%d\n", X, binaryFind(a, X));
	return 0;
}
