#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N, X;
	int Pi[1000], Mi[1000];

	while (cin>>N>>X) //多组输入  N：购买哈士奇的数量 X：钱数
	{
		for (int i = 0; i < N; i++) //输入每条哈士奇的价钱和萌值
			cin >> Pi[i] >> Mi[i];

		int MiSum[1001] = { 0 };  //存储对应 X 的最大萌值
		for (int i = 0; i < N; i++)
			for (int j = X; j >= Pi[i]; j--) //当当前钱数大于等于哈士奇的价格 进入循环
				MiSum[j] = max(MiSum[j], MiSum[j - Pi[i]] + Mi[i]); //取购买这只和不购买这只的最大值

		cout << MiSum[X] << endl; //输出钱数为X的最大萌值
	}

	return 0;
}