#include<iostream>
#include<algorithm>
using namespace std;

int myCount = 0;

int subsequencSum(int left, int right,const int *arr)
{
	myCount++;

	if (left == right)
	{
		return arr[left] > 0 ? arr[left] : 0;
	}

	else if (left < right)
	{
		int mid = (left + right) / 2;
		int maxL = subsequencSum(left, mid, arr);
		int maxR = subsequencSum(mid + 1, right, arr);
		int Max = max(maxL, maxR);

		int leftSum = 0, maxLeftSum = 0;
		for (int i = mid; i >= left; i--)
		{
			leftSum += arr[i];
			if (leftSum > maxLeftSum)
				maxLeftSum = leftSum;
		}

		int rightSum = 0, maxRightSum = 0;
		for (int i = mid + 1; i <= right; i++)
		{
			rightSum += arr[i];
			if (rightSum > maxRightSum)
				maxRightSum = rightSum;
		}
		return max(Max, maxLeftSum + maxRightSum);
	}
}

int main()
{
	int n;
	cin >> n;
	int* A = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	cout << subsequencSum(0, n - 1, A) <<" ";
	cout << myCount << endl;

	return 0;
}