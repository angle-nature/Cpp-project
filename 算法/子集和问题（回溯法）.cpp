#include<iostream>
using namespace std;

int main()
{
	int n, c, sum = 0, total = 0; //n:����Ԫ�ظ���  c:Ŀ��ֵ  sum����  total��Ԫ�ؼ����ܺ�
	int count = 0;  //�Ӽ������±� �� ����
	cin >> n >> c;
	int* arr = new int[n];  //����
	int* index = new int[n] {0}; //�Ӽ� �洢���϶�Ӧ�±�

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		total += arr[i];
	}
	if (total < c)  //���ܺ�С��Ŀ��ֵ ��϶��޽�
	{
		cout << "No Solution!" << endl;
		exit(0);
	}
	int surplus = total;  //��ǰԪ�غ����ʣ��Ԫ�ص��ܺ�
	int start = 0;  //��ʼ�±�
	while (index[0]!=n-1)  //��û�б��������Ԫ��ʱ
	{
		for (int i = start; i < n; i++)
		{
			if (sum + surplus < c)  //�����ǰ�ͺ�ʣ��͵ĺ�С��Ŀ��ֵ ��˱����޽� ����ѭ��
				break;
			if (arr[i] == c) //���Ԫ��ֵ����Ŀ��ֵ ֱ��������
			{
				sum = c;
				cout << arr[i] << endl;			
				exit(0);
			}
			else if (arr[i] + sum > c)  //�����ǰԪ���뵱ǰ�͵ĺʹ���Ŀ��ֵ ��������Ԫ��
			{
				surplus -= arr[i];  //ʣ��ֵ������ǰԪ��ֵ
				continue;
			}
			else
			{
				sum += arr[i]; 
				surplus -= arr[i];  //ʣ��ֵ������ǰԪ��
				index[count++] = i; //�Ӽ��洢��Ӧ�±�

				if (sum == c)  //����ǰ�͵���Ŀ��ֵ ������
				{
					for (int i = 0; i < count; i++)
						cout << arr[index[i]] << " ";
					exit(0);
				}
			}
		}
		surplus = total - arr[start];  //ʣ��ֵ����
		start = index[count - 1] + 1;  //��ʼ�±��Ϊ�Ӽ��洢�����һ���±����һ�������ݣ�
		sum -= arr[index[count - 1]]; //���µ�ǰ��
		count--; //�Ӽ�Ԫ�ؼ�һ
	}

	cout << "No Solution!" << endl;

	return 0;
}