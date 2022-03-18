#include<iostream>
using namespace std;

void bubbleSort(int* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[] = { 2,3,5,4,9,8,7,1,6,10 };

	int len = sizeof(arr) / sizeof(arr[0]);

	bubbleSort(arr, len);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}