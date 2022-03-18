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
double width = 1000 * 1.0 / SIZE; //���ο��

//���ȿ�ľ���
void drawRectangle(int* a, int length)
{
	double width = 1000 * 1.0 / length; //ÿ�����εĿ��
	for (int i = 0; i < length; i++)
		solidrectangle(i * width, a[i], i * width + width, 0);
}	

//�����鸳���ֵ
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

//ð������(����)
void bubbleSort(int* a,int length)
{
	double width = 1000 * 1.0 / length; //ÿ�����εĿ��
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

//��������(����)
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

//ѡ������(����)
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

//���ţ�������
int Partition(int a[], int p, int r) 
{
	int i = p + 1, j = r;
	int key = a[p]; //ѡȡ��һ��Ԫ��Ϊ�ؼ���
	// ��< x��Ԫ�ؽ������������
	// ��> x��Ԫ�ؽ������ұ�����
	while (true && (i <= j)) {
		while (a[i] < key) { i++; } //�ҵ��ȹؼ��ִ��
		while (a[j] > key) { j--; } //�ҵ��ȹؼ���С��
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

//��������(����)
void quickSort(int a[], int p, int r) 
{
	if (p < r) {
		int q = Partition(a, p, r); //ȡ�ؼ��������±�
		quickSort(a, p, q - 1); //����������
		quickSort(a, q + 1, r); //���Ұ������
	}
}

//ϣ�����򣨲��룩
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

//ϣ������
void shellSort(int a[], int length) 
{
	int i;
	int j;
	int k;
	int gap;	//gap�Ƿ���Ĳ���
	int temp;	//ϣ����������ֱ�Ӳ�������Ļ�����ʵ�ֵ�,������Ȼ��Ҫ�ڱ�
	for (gap = length / 2; gap > 0; gap = gap / 2) //���ò��� ����ÿ�μ���
	{ 
		for (i = 0; i < gap; i++) //ÿ��
		{
			for (j = i + gap; j < length; j = j + gap) //��ÿһ���ڵ�Ԫ�ؽ��е����Ĳ�������
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

//ϣ������
//void shellSort(int* a, int* gaps, int lenth)
//{
//	for (int k = 0; k < lenth; k++)
//		shellInsert(a, gaps[k]);
//}

//�鲢���򣨷ָ
void Merge(int* a, int left, int mid, int right)
{
	int* temp = new int[right - left + 1];  //����ռ�����������������鲢�����ʱ����
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

	//����ʱ������������Ԫ�أ����ϵ�ԭ������
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

//�鲢����
void MergeSort(int* a, int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		MergeSort(a, left, mid); //�ݹ�ָ���벿��
		MergeSort(a, mid + 1, right);//�ݹ�ָ��Ұ벿��
		Merge(a, left, mid, right);//�鲢
	}
}

int main()
{
	int* arr = new int[SIZE];	

	
	srand((unsigned)time(NULL));

	initgraph(1000, 650);
	setaspectratio(1, -1); //�޸���y������Ϊ��
	setorigin(0, 650); //�޸�����ԭ��Ϊ���½�
	setfillcolor(WHITE); //���������ɫ

#ifndef Bubble_Sort
	creatArr(arr);
	drawRectangle(arr, 1000);
	setaspectratio(1, 1);//�޸���y������Ϊ��
	outtextxy(10, -640, _T("ð������"));
	system("pause");
	setaspectratio(1, -1);
	bubbleSort(arr, 1000);
	system("pause");
#endif // !Bubble_Sort

#ifndef Insert_Sort
	cleardevice(); //����
	creatArr(arr);
	drawRectangle(arr, 2500);
	setaspectratio(1, 1);
	outtextxy(10, -640, _T("��������"));
	setaspectratio(1, -1);
	insertSort(arr, 2500);
	system("pause");
#endif // !Inset_Sort

#ifndef Select_Sort
	cleardevice(); //����
	creatArr(arr);
	drawRectangle(arr, 5000);
	setaspectratio(1, 1);
	outtextxy(10, -640, _T("ѡ������"));
	setaspectratio(1, -1);
	selectSort(arr, 5000);
	system("pause");
#endif // !Select_Sort

#ifndef Quick_Sort
	cleardevice(); //����
	creatArr(arr);
	drawRectangle(arr, SIZE);
	setaspectratio(1, 1);
	outtextxy(10, -640, _T("��������"));
	setaspectratio(1, -1);
	quickSort(arr, 0, SIZE);
	system("pause");
#endif // !Quick_Sort

#ifndef Shell_Sort

	//int* gaps = new int[SIZE / 2]; //ϣ�������еĲ�������
	//int count = 0;
	//gaps[count] = SIZE / 2;
	//while (gaps[count] != 1)//���������鸳ֵ
	//{
	//	gaps[count + 1] = (gaps[count] - 3) / 2;
	//	count++;
	//}

	cleardevice(); //����
	creatArr(arr);
	drawRectangle(arr, SIZE);
	setaspectratio(1, 1);
	outtextxy(10, -640, _T("ϣ������"));
	setaspectratio(1, -1);
	//shellSort(arr, gaps, count + 1);
	shellSort(arr, SIZE);
	system("pause");
#endif // !Shell_Sort

#ifndef Merge_Sort
	cleardevice(); //����
	creatArr(arr);
	drawRectangle(arr, SIZE);
	setaspectratio(1, 1);
	outtextxy(10, -640, _T("�鲢����"));
	setaspectratio(1, -1);
	MergeSort(arr, 0, SIZE);
	system("pause");
#endif // !Merge_Sort

	return 0;
}