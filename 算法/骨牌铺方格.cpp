#include<iostream>
using namespace std;

long long total(int left, int right) //left 左下标  ，right  右下标
{	
	if (right - left <= 2)
		return (long long)right-(long long)left;
	else
	{
		int mid = (right + left) / 2;
		long long countL1 = total(left, mid);  //左边方案总数
		long long countR1 = total(mid , right);	//右边方案总数
		long long countL2;
		if (mid - 1 == left) //如果左边部分只有一个方格 则跨越中间的左半部分的方案总数为1
			countL2 = 1; //特殊情况  必须单独写出
		else
			countL2 = total(left, mid - 1);  //跨越中间的左半部分的方案总数

		long long countR2 = total(mid + 1, right); //跨越中间的右半部分的方案总数

		return countL1 * countR1 + countL2 * countR2;  //最终方案总数
	}

}

int main()
{
	int n;
	cin >> n;
	cout << total(0, n) << endl;

	return 0;
}