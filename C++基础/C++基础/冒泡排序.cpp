#include<iostream>
using namespace std;

int main()
{
	int size;
	cout << "���������ݸ�����" << endl;
	cin >> size;
	int *arr = new int[size];      //������̬����
	cout << "���������ݣ�" << endl;

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	
	//ð����������
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

	cout << "�����" << endl;
	
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
		if ((i+1) % 10 == 0)
			cout << endl;
	}

	delete[] arr;        //�ͷŶ�̬����ռ�
	return 0;
}