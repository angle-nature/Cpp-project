#include<iostream>
using namespace std;

//ʵ��ͨ�� �������������ĺ���
//���� ��С����
//�㷨 ѡ������

//����ģ��
template<class T> //����һ��ģ�壬���߱�������������н����ŵ�T��Ҫ����T��һ��ͨ����������
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