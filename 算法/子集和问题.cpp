#include<iostream>
using namespace std;

int n,c;
int arr[10001];
int sub[10001]{0}; 
bool flag;

bool subset1(int k)
{
	int sum = 0, r = 0;
	for (int i = 0; i <= k; i++)  //��ǰ�Ӽ��ĺ�
		sum += arr[i] * sub[i];
	for (int i = k+1 ; i < n; i++) //ʣ��Ԫ�غ�
		r += arr[i];
	if (sum == c)
	{
		for (int i = 0; i <= k; i++)  //������
			if (sub[i] == 1)
				cout << arr[i] << " ";
		flag = true; //��־������Ϊtrue
		exit(0);
	}
	else if ((k < n-1) && (sum<c) && ((sum + r)>=c)) //�޶�������֧
	{
		sub[k + 1] = 1;  //��������һ��Ԫ��  
		bool flag1 = subset1(k + 1); //����������
		sub[k + 1] = 0; //������һ��Ԫ��
		bool flag2 = subset1(k + 1); //����������

		flag = (flag1 || flag2); //����������������һ��Ϊtrue���ʾ����Ϊtrue
	}
	else
		flag = false;
	return flag;
}

int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	flag = subset1(-1);
	if (!flag)
		cout << "No Solution!";

	return 0;
}