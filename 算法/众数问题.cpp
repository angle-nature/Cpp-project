#include<iostream>
#include<algorithm>
using namespace std;

#define MAXSIZE 1300000

struct Result
{
	int mode=0;  //众数
	int numbers=0;  //重数
};

Result solve(int A[], int left, int right)  //left 左下标  ，right  右下标
{
	Result result;  //用来接收结果
	int length = right - left + 1; //数组长度
	//长度为1的情况
	if (length == 1)
	{
		result.mode = A[left];
		result.numbers = 1;
		return result;
	}
	//长度为2的情况
	else if (length == 2)
	{
		if (A[left] != A[right])
		{
			result.mode = min(A[left], A[right]);
			result.numbers = 1;
		}
		else
		{
			result.mode = A[left];
			result.numbers = 2;
		}

		return result;
	}
	//当 lenght>2
	else
	{
		int mid = (left + right) / 2;  //中间下标
		Result resultL = solve(A, left, mid);   //左边的结果
		Result resultR = solve(A, mid + 1, right);  //右边的结果			
		//取重数最大的结果 若重数相等 取众数较小的
		if (resultL.numbers != resultR.numbers)
			result = resultL.numbers > resultR.numbers ? resultL : resultR;
		else
			result = resultL.mode < resultR.mode ? resultL : resultR;
		int count = 0;  //中间结果的重数
		for (int i = left; i<=right; i++)
			if (A[i] == A[mid])
				count++;
		//取重数最大的结果 若重数相等 取众数较小的
		if (count > result.numbers)
		{
			result.mode = A[mid];
			result.numbers = count;
		}
		else if (count == result.numbers)
			result.mode = result.mode < A[mid] ? result.mode : A[mid];
		return result;
	}
}

int main()
{
	int *A = new int[MAXSIZE]; //内存过大  需存放入堆区
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	sort(A, A + n); //将数组元素进行排序

	Result maxResult = solve(A, 0, n - 1);

	cout << maxResult.mode << endl;  //输出众数
	cout << maxResult.numbers << endl;  //输出重数

	return 0;
}