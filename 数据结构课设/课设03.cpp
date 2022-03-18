#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<ctime>

#define Bubble_Sort
#define Insert_Sort
//#define Select_Sort
//#define Quick_Sort
//#define Shell_Sort
//#define Merge_Sort

#define SIZE 50000
double width = 1000 * 1.0 / SIZE; //矩形宽度

//画等宽的矩形
void drawRectangle(int* a, int length)
{
	double width = 1000 * 1.0 / length; //每个矩形的宽度
	for (int i = 0; i < length; i++)
		solidrectangle(i * width, a[i], i * width + width, 0);
}	

//给数组赋随机值
void creatArr(int* a)
{
	for (int i = 0; i < SIZE; i++)
		a[i] = rand() % 600 + 1;
}

inline void swap(int *a, int i, int j,int width) 
{
	int temp = a[i];
	setfillcolor(BLACK);
	solidrectangle(i * width, a[i], i * width + width, 0);
	a[i] = a[j];
	setfillcolor(WHITE);
	solidrectangle(i * width, a[i], i * width + width, 0);
	setfillcolor(BLACK);
	solidrectangle(j * width, a[j], j * width + width, 0);
	a[j] = temp;
	setfillcolor(WHITE);
	solidrectangle(j * width, a[j], j * width + width, 0);
}

//冒泡排序(升序)
void bubbleSort(int* a,int length)
{
	double width = 1000 * 1.0 / length; //每个矩形的宽度
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (a[j] > a[j + 1])
				swap(a, j, j+1, width);
			//Sleep(1);
		}
	}
}

//插入排序(升序)
void insertSort(int* a,int length) 
{
	double width = 1000 * 1.0 / length;
	for (int i = 1; i < length; i++)
	{
		int temp = a[i];
		int j;
		for (j = i - 1; a[j] > temp; j--)
		{
			setfillcolor(BLACK);
			solidrectangle((j + 1) * width, a[j + 1], (j + 1) * width + width, 0);
			a[j + 1] = a[j];
			setfillcolor(WHITE);
			solidrectangle((j + 1) * width, a[j + 1], (j + 1) * width + width, 0);
		}
		setfillcolor(BLACK);
		solidrectangle((j + 1) * width, a[j + 1], (j + 1) * width + width, 0);
		a[j + 1] = temp;
		setfillcolor(WHITE);
		solidrectangle((j + 1) * width, a[j + 1], (j + 1) * width + width, 0);
	}
}

//选择排序(升序)
void selectSort(int* a, int length)
{
	double width = 1000 * 1.0 / length;
	int min;
	for (int i = 0; i < length - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
			if (a[j] < a[min])
				min = j;

		//swap(a, i, min, width);
		int temp = a[i];
		setfillcolor(BLACK);
		solidrectangle(i * width, a[i], i * width + width, 0);
		a[i] = a[min];
		setfillcolor(WHITE);
		solidrectangle(i * width, a[i], i * width + width, 0);
		setfillcolor(BLACK);
		solidrectangle(min * width, a[min], min * width + width, 0);
		a[min] = temp;
		setfillcolor(WHITE);
		solidrectangle(min * width, a[min], min * width + width, 0);

	Sleep(1);
	}
}

//快排（分区）
int Partition(int a[], int p, int r) 
{
	int i = p + 1, j = r;
	int key = a[p]; //选取第一个元素为关键字
	// 将< x的元素交换到左边区域
	// 将> x的元素交换到右边区域
	while (true && (i <= j)) {
		while (a[i] < key) { i++; } //找到比关键字大的
		while (a[j] > key) { j--; } //找到比关键字小的
		if (i >= j) break;

		//swap(a, i, j, width);

		int temp = a[i];
		setfillcolor(BLACK);
		solidrectangle(i * width, a[i], i * width + width, 0);
		a[i] = a[j];
		setfillcolor(WHITE);
		solidrectangle(i * width, a[i], i * width + width, 0);
		setfillcolor(BLACK);
		solidrectangle(j * width, a[j], j * width + width, 0);
		a[j] = temp;
		setfillcolor(WHITE);
		solidrectangle(j * width, a[j], j * width + width, 0);

		i++;
		j--;
		//Sleep(1);
	}
	setfillcolor(BLACK);
	solidrectangle(p * width, a[p], p * width + width, 0);
	a[p] = a[j];
	setfillcolor(WHITE);
	solidrectangle(p * width, a[p], p * width + width, 0);
	setfillcolor(BLACK);
	solidrectangle(j * width, a[j], j * width + width, 0);
	a[j] = key;
	setfillcolor(WHITE);
	solidrectangle(j * width, a[j], j * width + width, 0);
	return j;
}

//快速排序(升序)
void quickSort(int a[], int p, int r) 
{
	if (p < r) {
		int q = Partition(a, p, r); //取关键字所处下标
		quickSort(a, p, q - 1); //对左半段排序
		quickSort(a, q + 1, r); //对右半段排序
	}
}

//希尔排序（插入）
void shellInsert(int* a, int gap)
{
	for (int i = gap; i < SIZE; i++)
	{
		if (a[i] < a[i - gap])
		{
			int j;
			int temp = a[i];
			for (j = i - gap; j > 0 && temp < a[j]; j = j - gap)
			{
				setfillcolor(BLACK);
				solidrectangle((j + gap) * width, a[j + gap], (j + gap) * width + width, 0);
				a[j + gap] = a[j];
				setfillcolor(WHITE);
				solidrectangle((j + gap) * width, a[j + gap], (j + gap) * width + width, 0);
			}
			setfillcolor(BLACK);
			solidrectangle((j + gap) * width, a[j + gap], (j + gap) * width + width, 0);
			a[j + gap] = temp;
			setfillcolor(WHITE);
			solidrectangle((j + gap) * width, a[j + gap], (j + gap) * width + width, 0);
		}
		//Sleep(0.1);
	}
}

//希尔排序
void shellSort(int a[], int length) 
{
	int i;
	int j;
	int k;
	int gap;	//gap是分组的步长
	int temp;	//希尔排序是在直接插入排序的基础上实现的,所以仍然需要哨兵
	for (gap = length / 2; gap > 0; gap = gap / 2) //设置步长 步长每次减半
	{ 
		for (i = 0; i < gap; i++) //每组
		{
			for (j = i + gap; j < length; j = j + gap) //对每一组内的元素进行单独的插入排序
			{	
				if (a[j] < a[j - gap]) 
				{
					temp = a[j];	
					k = j - gap;
					while (k >= 0 && a[k] > temp) 
					{
						setfillcolor(BLACK);
						solidrectangle((k + gap) * width, a[k + gap], (k + gap) * width + width, 0);
						a[k + gap] = a[k];
						setfillcolor(WHITE);
						solidrectangle((k + gap) * width, a[k + gap], (k + gap) * width + width, 0);
						k = k - gap;
					}
					setfillcolor(BLACK);
					solidrectangle((k + gap) * width, a[k + gap], (k + gap) * width + width, 0);
					a[k + gap] = temp;
					setfillcolor(WHITE);
					solidrectangle((k + gap) * width, a[k + gap], (k + gap) * width + width, 0);
				}
				//Sleep(1);
			}
		}
	}
}

//希尔排序
//void shellSort(int* a, int* gaps, int lenth)
//{
//	for (int k = 0; k < lenth; k++)
//		shellInsert(a, gaps[k]);
//}

//归并排序（分割）
void Merge(int* a, int left, int mid, int right)
{
	int* temp = new int[right - left + 1];  //申请空间来存放两个有序区归并后的临时区域
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= right)
	{
		temp[k++] = a[j++];
	}

	//将临时区域中排序后的元素，整合到原数组中
	for (i = 0; i < k; i++)
	{
		setfillcolor(BLACK);
		solidrectangle((left + i) * width, a[(left + i)], (left + i) * width + width, 0);
		a[left + i] = temp[i];
		setfillcolor(WHITE);
		solidrectangle((left + i) * width, a[(left + i)], (left + i) * width + width, 0);
		//Sleep(1);
	}
	delete[] temp;
}

//归并排序
void MergeSort(int* a, int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		MergeSort(a, left, mid); //递归分割左半部分
		MergeSort(a, mid + 1, right);//递归分割右半部分
		Merge(a, left, mid, right);//归并
	}
}

int main()
{
	int* arr = new int[SIZE];	

	
	srand((unsigned)time(NULL));

	initgraph(1000, 650);
	setaspectratio(1, -1); //修改让y轴向上为正
	setorigin(0, 650); //修改坐标原点为左下角
	setfillcolor(WHITE); //设置填充颜色

#ifndef Bubble_Sort
	creatArr(arr);
	drawRectangle(arr, 1000);
	setaspectratio(1, 1);//修改让y轴向下为正
	outtextxy(10, -640, _T("冒泡排序"));
	system("pause");
	setaspectratio(1, -1);
	bubbleSort(arr, 1000);
	system("pause");
#endif // !Bubble_Sort

#ifndef Insert_Sort
	cleardevice(); //清屏
	creatArr(arr);
	drawRectangle(arr, 2500);
	setaspectratio(1, 1);
	outtextxy(10, -640, _T("插入排序"));
	setaspectratio(1, -1);
	insertSort(arr, 2500);
	system("pause");
#endif // !Inset_Sort

#ifndef Select_Sort
	cleardevice(); //清屏
	creatArr(arr);
	drawRectangle(arr, 5000);
	setaspectratio(1, 1);
	outtextxy(10, -640, _T("选择排序"));
	setaspectratio(1, -1);
	selectSort(arr, 5000);
	system("pause");
#endif // !Select_Sort

#ifndef Quick_Sort
	cleardevice(); //清屏
	creatArr(arr);
	drawRectangle(arr, SIZE);
	setaspectratio(1, 1);
	outtextxy(10, -640, _T("快速排序"));
	setaspectratio(1, -1);
	quickSort(arr, 0, SIZE);
	system("pause");
#endif // !Quick_Sort

#ifndef Shell_Sort

	//int* gaps = new int[SIZE / 2]; //希尔排序中的步长数组
	//int count = 0;
	//gaps[count] = SIZE / 2;
	//while (gaps[count] != 1)//给步长数组赋值
	//{
	//	gaps[count + 1] = (gaps[count] - 3) / 2;
	//	count++;
	//}

	cleardevice(); //清屏
	creatArr(arr);
	drawRectangle(arr, SIZE);
	setaspectratio(1, 1);
	outtextxy(10, -640, _T("希尔排序"));
	setaspectratio(1, -1);
	//shellSort(arr, gaps, count + 1);
	shellSort(arr, SIZE);
	system("pause");
#endif // !Shell_Sort

#ifndef Merge_Sort
	cleardevice(); //清屏
	creatArr(arr);
	drawRectangle(arr, SIZE);
	setaspectratio(1, 1);
	outtextxy(10, -640, _T("归并排序"));
	setaspectratio(1, -1);
	MergeSort(arr, 0, SIZE);
	system("pause");
#endif // !Merge_Sort

	return 0;
}