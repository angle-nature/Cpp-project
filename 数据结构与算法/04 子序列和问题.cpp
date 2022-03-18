#include<stdio.h>

//��С���к�  T(N)=O(N)
int MinSubsequenceSum(int* arr, int len)
{
	int thisSum = 0;
	int MinSum = 1000;
	for (int i = 0; i < len; i++)
	{
		thisSum += arr[i];
		if (thisSum < MinSum)
			MinSum = thisSum;
		if (thisSum > 0)
			thisSum = 0;
	}
	return MinSum;
}

//��С�������к�  T(N)=O(n2) ���÷��� ʱ�临�Ӷ�Ϊ O(NlogN)
int MinPostiveSubsequenceSum(int* arr, int len)
{
	int MinSum = 1000;
	for (int i = 0; i < len; i++)
	{
		int thisSum = 0;
		for (int j = i; j < len; j++)
		{
			thisSum += arr[j];
			if (thisSum < MinSum && thisSum>0)
				MinSum = thisSum;
		}
	}
	return MinSum;
}

//��С�����г˻�  T(N)=O(n2) ���÷��� ʱ�临�Ӷ�Ϊ O(NlogN)
long long MinSubsequenceProduct(int* arr, int len)
{
	long long MinProduct = 10000;
	for (int i = 0; i < len; i++)
	{
		long long thisProduct = 1;
		for (int j = i; j < len; j++)
		{
			thisProduct *= arr[j];
			if (thisProduct < MinProduct)
				MinProduct = thisProduct;
		}
	}
	return MinProduct;
}

int main()
{
	int arr[] = { 4,2,3,59,-45,-6,5,-5,8,-6 };
	int len = sizeof(arr) / sizeof(arr[0]);

	int Min = MinSubsequenceProduct(arr, len);

	printf("%d", Min);

	return 0;
}