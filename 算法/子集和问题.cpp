#include<iostream>
using namespace std;

int n,c;
int arr[10001];
int sub[10001]{0}; 
bool flag;

bool subset1(int k)
{
	int sum = 0, r = 0;
	for (int i = 0; i <= k; i++)  //当前子集的和
		sum += arr[i] * sub[i];
	for (int i = k+1 ; i < n; i++) //剩余元素和
		r += arr[i];
	if (sum == c)
	{
		for (int i = 0; i <= k; i++)  //输出结果
			if (sub[i] == 1)
				cout << arr[i] << " ";
		flag = true; //标志变量变为true
		exit(0);
	}
	else if ((k < n-1) && (sum<c) && ((sum + r)>=c)) //限定条件剪支
	{
		sub[k + 1] = 1;  //不放入下一个元素  
		bool flag1 = subset1(k + 1); //搜索左子树
		sub[k + 1] = 0; //放入下一个元素
		bool flag2 = subset1(k + 1); //搜索右子树

		flag = (flag1 || flag2); //左子树和右子树有一个为true则表示变量为true
	}
	else
		flag = false;
	return flag;
}

int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	flag = subset1(-1);
	if (!flag)
		cout << "No Solution!";

	return 0;
}