#include<iostream>
using namespace std;

int main()
{
	int size;
	cout << "请输入数据个数：" << endl;
	cin >> size;
	int *arr = new int[size];      //创建动态数组
	cout << "请输入数据：" << endl;

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	
	//冒泡排序排序
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << "排序后：" << endl;
	
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
		if ((i+1) % 10 == 0)
			cout << endl;
	}

	delete[] arr;        //释放动态数组空间
	return 0;
}