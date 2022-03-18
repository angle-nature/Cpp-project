#include<iostream>
#include<algorithm>
using namespace std;

int P[20][20], Q[20][20], flag[20]{0};
int n;
int W[20];
int maxSum = 0;

//时间复杂度较高  超时了
int solve(int i)
{
	int max = 0; //最终结果

	for (int j = 0; j < n&&i<n; j++)
	{
		int max1=0; //每一种情况的和
		if (flag[j] == 0)
		{
			flag[j] = 1; //若此列已被取用 flag标记为1
			max1 = P[i][j] * Q[j][i] + solve(i + 1); //计算每种情况的和
			flag[j] = 0; //一种情况已被遍历完 flag重新标记为0
		}
		max = max > max1 ? max : max1; //取每种情况的最大值
	}
	return max;
}

void Compute()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += P[i][W[i]] * Q[W[i]][i];
	}
	maxSum = max(maxSum, sum);
}

void BackTrack(int t)
{
	if (t >= n)
		Compute();
	else
		for (int i = 0; i < n; i++)
		{
			swap(W[t], W[i]);
			BackTrack(t + 1);
			swap(W[i], W[t]);
		}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> P[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> Q[i][j];
	
	for (int i = 0; i < n; i++)
		W[i] = i;

	//cout << solve(0);
	BackTrack(0);
	cout << maxSum << endl;
	return 0;
}