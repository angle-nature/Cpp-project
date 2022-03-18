#include<iostream>
#include<algorithm>
using namespace std;
#define MAXSIZE 100

int main(void)
{
	int n;
	int arr[MAXSIZE][MAXSIZE];
	cin >> n;

	//输入二维数组
	for (int i = 0; i < n; i++)	
		for (int j = 0; j <= i; j++)
			cin >> arr[i][j];

	//动态规划思想 从三角形的底边一直计算到顶点（采用递归时间复杂度太高）
	for (int i = n-1; i > 0; i--)  //从最后一行遍历到第一行
		for (int j = 0; j < i; j++) //从第一列遍历到每一行的最后一列
			arr[n - 1][j] = max(arr[n - 1][j] + arr[i-1][j], arr[n - 1][j + 1] + arr[i-1][j]);
			//将每一行的每个点的路径最大值对应的存储在最后一行的的数组中

	cout << arr[n - 1][0]; //最后一行的数组中的第一个元素即是最终结果
	
	return 0;
}