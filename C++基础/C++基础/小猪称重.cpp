#include<iostream>
using namespace std;

int main()
{
	int arr[5] = { 200,150,600,400,350 };
	int max=0;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	cout << "���ص�С������Ϊ��" << max << endl;
	return 0;
}