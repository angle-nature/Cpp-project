#include<iostream>
using namespace std;

bool max(int a, int b)
{
	return a > b;
}

bool min(int a, int b)
{
	return a < b;
}

long Pay(long arr[], int n,int k,bool(*pCompare)(int,int))
{													//	/*  当计算最小费用时：
	int index = 0;  //数组下标								int temp = n; 
	long payEach = 0;  //每合并k堆石堆的费用				while (n > k)   //计算需要补0的个数
	int count = 0; //合石堆个数									n = n - k + 1;
	long result = 0; //最终费用								n = temp + (k - n);  //（k-n）即是需要加上的0的个数
	while (index<n)	//									*/
	{
		for (int i = index; i < n; i++)  //将从下标index开始的数组元素的最小值或最大值放到arr[index]的位置
		{
			if (pCompare(arr[i],arr[index])) //将元素arr[i]和arr[index]进行比较 条件满足 则交换
			{								 //若求最大费用 应arr[i]>arr[index]  反之arr[i]<arr[index]
				int temp = arr[i];
				arr[i] = arr[index];
				arr[index] = temp;
			}
		}
		count++; //计数加一
		payEach += arr[index];
		if (count == k)  //每加上k个石堆时 进入循环
		{
			arr[index] = payEach; //将这k个石堆合并后的石堆放到arr[index]
			result += payEach;  //最终费用加上合并这k个石堆的费用
			count = 0; //合并石堆数置零
			payEach = 0; //合并一次的费用置零
		}
		else
			index++;  //若还没有合并k个石堆 则下标加一
	}
	return result;
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	int temp = n; 
	while (n > k)   //计算需要补0的个数
		n = n - k + 1;

	n = temp + (k - n);  //（k-n）即是需要加上的0的个数

	long* aMax = new long[temp];
	long* aMin = new long[n];
	for (int i = 0; i < temp; i++)
	{
		cin >> aMin[i];
		aMax[i] = aMin[i];
	}
	for (int i = temp; i < n; i++) //补零
		aMin[i] = 0;
	

	cout << Pay(aMax, temp, 2, max) << " " << Pay(aMin, n, k, min) << endl;

	return 0;
}