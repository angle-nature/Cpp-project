#include<stdio.h>

#define MAXSIZE 100
typedef int DataType;

typedef struct node
{
	DataType data[MAXSIZE];
	int length;
}*SeqList,*PSeqList;

void divide(SeqList L)
{
	int low = 0, high = L->length - 1;

	while (low < high)
	{
		while (low < high && L->data[high] >= 0)
			high--;
		while (low < high && L->data[low] < 0)
			low++;
		if (low < high)
		{
			int temp = L->data[low];
			L->data[low] = L->data[high];
			L->data[high] = temp;
		}
	}
}

int main()
{
	node L;

	
	L.data[0] = -1;
	L.data[1] = 5;
	L.data[2] = 2;
	L.data[3] = -5;
	L.data[4] = 6;
	L.data[5] = -7;
	L.data[6] = -1;
	L.data[7] = -9;
	L.length = 8;

	printf("交换前：\n");
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}

	putchar('\n');
	divide(&L);

	printf("交换后：\n");
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}

	return 0;
}