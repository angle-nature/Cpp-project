#include<iostream>
using namespace std;

#define MAXNUMBER 1001

int main()
{
	int n, k,myCount = 0;    //n������ÿ�μ��Ϳ���ʻ����   k������վ����
	cin >> n >> k;
	int constant[MAXNUMBER];
	for (int i = 0; i < k+1; i++)
		cin >> constant[i];

	int constantable = n;  //����ʣ�����ʻ����

	for (int i = 0; i < k + 1; i++)
	{
		if (n < constant[i]) //������������Ϳ���ʻ����С��������վ֮��ľ��� ���޷�����
		{
			cout << "No Solution!" << endl;
			exit(0);
		}
		else if (constantable >= constant[i]) //���ʣ�����ʻ����ɴﵽ��һ������վ���������ʻ		 
			constantable -= constant[i]; //����ʣ�����ʻ����
		else
		{
			myCount++; //ʣ�����ʻ�����޷����� �����
			constantable =  n - constant[i]; //����ʣ�����ʻ����
		}
	}
	cout << myCount << endl; //������ʹ���
	return 0;
}