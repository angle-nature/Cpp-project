#include<iostream>
#include<algorithm>
using namespace std;
#define MAXSIZE 100

int main(void)
{
	int n;
	int arr[MAXSIZE][MAXSIZE];
	cin >> n;

	//�����ά����
	for (int i = 0; i < n; i++)	
		for (int j = 0; j <= i; j++)
			cin >> arr[i][j];

	//��̬�滮˼�� �������εĵױ�һֱ���㵽���㣨���õݹ�ʱ�临�Ӷ�̫�ߣ�
	for (int i = n-1; i > 0; i--)  //�����һ�б�������һ��
		for (int j = 0; j < i; j++) //�ӵ�һ�б�����ÿһ�е����һ��
			arr[n - 1][j] = max(arr[n - 1][j] + arr[i-1][j], arr[n - 1][j + 1] + arr[i-1][j]);
			//��ÿһ�е�ÿ�����·�����ֵ��Ӧ�Ĵ洢�����һ�еĵ�������

	cout << arr[n - 1][0]; //���һ�е������еĵ�һ��Ԫ�ؼ������ս��
	
	return 0;
}