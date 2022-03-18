#include<iostream>
using namespace std;

long factorial1(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial1(n - 1);
}

long factorial2(int n)
{
	if (n == 0)
		return 1;
	else
	{
		long result = 1;
		for (int i = n; i >= 1; i--)
		{
			result *= i;
		}
		return result;
	}
}

int main()
{
	cout << "请输入整数n：" << endl;
	int n;
	cin >> n;

	cout <<"递归求得："<< factorial1(n) << endl;
	cout <<"循环求得：" << factorial2(n) << endl;

	system("pause");
	return 0;
}