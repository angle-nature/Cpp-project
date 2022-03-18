#include<iostream>
using namespace std;

int main()
{
	int n, c, sum = 0, total = 0; //n:集合元素个数  c:目标值  sum：和  total：元素集合总和
	int count = 0;  //子集集合下标 兼 个数
	cin >> n >> c;
	int* arr = new int[n];  //集合
	int* index = new int[n] {0}; //子集 存储集合对应下标

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		total += arr[i];
	}
	if (total < c)  //若总和小于目标值 则肯定无解
	{
		cout << "No Solution!" << endl;
		exit(0);
	}
	int surplus = total;  //当前元素后面的剩余元素的总和
	int start = 0;  //开始下标
	while (index[0]!=n-1)  //当没有遍历到最后元素时
	{
		for (int i = start; i < n; i++)
		{
			if (sum + surplus < c)  //如果当前和和剩余和的和小于目标值 则此遍历无解 跳出循环
				break;
			if (arr[i] == c) //如果元素值等于目标值 直接输出结果
			{
				sum = c;
				cout << arr[i] << endl;			
				exit(0);
			}
			else if (arr[i] + sum > c)  //如果当前元素与当前和的和大于目标值 则跳过该元素
			{
				surplus -= arr[i];  //剩余值减掉当前元素值
				continue;
			}
			else
			{
				sum += arr[i]; 
				surplus -= arr[i];  //剩余值减掉当前元素
				index[count++] = i; //子集存储相应下标

				if (sum == c)  //若当前和等于目标值 输出结果
				{
					for (int i = 0; i < count; i++)
						cout << arr[index[i]] << " ";
					exit(0);
				}
			}
		}
		surplus = total - arr[start];  //剩余值等于
		start = index[count - 1] + 1;  //开始下标变为子集存储的最后一个下标的下一个（回溯）
		sum -= arr[index[count - 1]]; //更新当前和
		count--; //子集元素减一
	}

	cout << "No Solution!" << endl;

	return 0;
}