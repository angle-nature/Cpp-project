#include<iostream>
using namespace std;

int combination(int n, int k)
{
	if (k > n)
		return 0;
	else if (k == 0 || k == n)
		return 1;
	else
		return combination(n - 1, k) + combination(n - 1, k - 1);
}

int main()
{
	cout << "请输入整数N和K：" << endl;
	int N, K;
	cin >> N >> K;

	cout << combination(N, K) << endl;

	system("pause");
	return 0;
}