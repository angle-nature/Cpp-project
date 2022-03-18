#include<stdio.h>

void sortList(int *a,int length) //将小于0的数放在大于0的数的前面
{
	int i = 0, j = length - 1;
	while (i<j)
	{
		while (a[i] < 0)i++;
		while (a[j] > 0)j--;

		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

int main()
{
	int a[] = { -2,5,-3,6,-7,8,2,0,-6 };
	int length = sizeof(a) / sizeof(a[0]);

	sortList(a, length);

	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);

	return 0;
}