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
	cout << "����������n��" << endl;
	int n;
	cin >> n;

	cout <<"�ݹ���ã�"<< factorial1(n) << endl;
	cout <<"ѭ����ã�" << factorial2(n) << endl;

	system("pause");
	return 0;
}