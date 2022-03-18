#include<iostream>
using namespace std;

//实现通用 对数组进行排序的函数
//规则 从小到大
//算法 选择排序

//函数模板
template<class T> //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySort(T* arr,int len)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			T temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

int main()
{
	char c[] =  "dbcahgfhi" ;

	//int c[] = { 1,6,5,3,4,9,7 };

	int size = sizeof(c) / sizeof(c[0]);

	mySort(c, size);

	for (int i = 0; i < size; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;

	system("pause");

	return 0;
}