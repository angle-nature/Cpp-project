#include<stdio.h>
void Swap(int* x1, int* y1)
{
	int temp = *x1;
	*x1 = *y1;
	*y1 = temp;

}
int Partition(int a[], int p, int r)
{
	int i = p + 1, j = r;
	int x = a[p];
	// 将< x的元素交换到左边区域
	// 将> x的元素交换到右边区域
	while (true && (i <= j)) {
		while (a[i] < x) { i++; }
		while (a[j] > x) { j--; }
		if (i >= j) break;
		Swap(&a[i], &a[j]);
		//int  xx = a[i];
		//a[i] = a[j];
		//a[j] = xx;
		i++;
		j--;
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

void QuickSort(int a[], int p, int r)
{
	if (p < r) {
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1); //对左半段排序
		for (int i = p; i < q; i++)
		{
			printf("%d  ",a[i]);
		}
		printf("\n");
		QuickSort(a, q + 1, r); //对右半段排序
		for (int i = q + 1; i < r + 1; i++)
		{
			printf("%d  ",a[i]);
		}
		printf("\n");
	}
}


int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	int b[] = { 49,38,65,97,76,13,27,49 };
	QuickSort(b, 0, 7);
	for (int i = 0; i < 8; i++)
	{
		printf("%d  ", b[i]);
	}
	printf("Hello World!\n");
	return 0;
}


