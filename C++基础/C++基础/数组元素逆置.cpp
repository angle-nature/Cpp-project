#include<iostream>
using namespace std;

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int start = 0;
	int end = sizeof(arr) / sizeof(arr[0]) - 1;
	while(start<end)
	{
		int temp = arr[start];
		arr[start++] = arr[end];
		arr[end--] = temp;
	}
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}