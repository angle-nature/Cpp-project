#include<iostream>
using namespace std;

long myCount = 0;

void calculate(long n) 
{
	if (n == 1)
		myCount++;

	long i = 2;
	while (i <= n)
	{
		if (n % i == 0)
			calculate(n / i);
		i++;
	}
}

int main()
{
	long n;
	cin >> n;
	calculate(n);
	cout << myCount << endl;

	return 0;
}