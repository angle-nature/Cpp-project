#include<iostream>
using namespace std;

bool max(int a, int b)
{
	return a > b;
}

bool min(int a, int b)
{
	return a < b;
}

long Pay(long arr[], int n,int k,bool(*pCompare)(int,int))
{													//	/*  ��������С����ʱ��
	int index = 0;  //�����±�								int temp = n; 
	long payEach = 0;  //ÿ�ϲ�k��ʯ�ѵķ���				while (n > k)   //������Ҫ��0�ĸ���
	int count = 0; //��ʯ�Ѹ���									n = n - k + 1;
	long result = 0; //���շ���								n = temp + (k - n);  //��k-n��������Ҫ���ϵ�0�ĸ���
	while (index<n)	//									*/
	{
		for (int i = index; i < n; i++)  //�����±�index��ʼ������Ԫ�ص���Сֵ�����ֵ�ŵ�arr[index]��λ��
		{
			if (pCompare(arr[i],arr[index])) //��Ԫ��arr[i]��arr[index]���бȽ� �������� �򽻻�
			{								 //���������� Ӧarr[i]>arr[index]  ��֮arr[i]<arr[index]
				int temp = arr[i];
				arr[i] = arr[index];
				arr[index] = temp;
			}
		}
		count++; //������һ
		payEach += arr[index];
		if (count == k)  //ÿ����k��ʯ��ʱ ����ѭ��
		{
			arr[index] = payEach; //����k��ʯ�Ѻϲ����ʯ�ѷŵ�arr[index]
			result += payEach;  //���շ��ü��Ϻϲ���k��ʯ�ѵķ���
			count = 0; //�ϲ�ʯ��������
			payEach = 0; //�ϲ�һ�εķ�������
		}
		else
			index++;  //����û�кϲ�k��ʯ�� ���±��һ
	}
	return result;
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	int temp = n; 
	while (n > k)   //������Ҫ��0�ĸ���
		n = n - k + 1;

	n = temp + (k - n);  //��k-n��������Ҫ���ϵ�0�ĸ���

	long* aMax = new long[temp];
	long* aMin = new long[n];
	for (int i = 0; i < temp; i++)
	{
		cin >> aMin[i];
		aMax[i] = aMin[i];
	}
	for (int i = temp; i < n; i++) //����
		aMin[i] = 0;
	

	cout << Pay(aMax, temp, 2, max) << " " << Pay(aMin, n, k, min) << endl;

	return 0;
}