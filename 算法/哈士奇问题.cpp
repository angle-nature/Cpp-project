#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N, X;
	int Pi[1000], Mi[1000];

	while (cin>>N>>X) //��������  N�������ʿ������� X��Ǯ��
	{
		for (int i = 0; i < N; i++) //����ÿ����ʿ��ļ�Ǯ����ֵ
			cin >> Pi[i] >> Mi[i];

		int MiSum[1001] = { 0 };  //�洢��Ӧ X �������ֵ
		for (int i = 0; i < N; i++)
			for (int j = X; j >= Pi[i]; j--) //����ǰǮ�����ڵ��ڹ�ʿ��ļ۸� ����ѭ��
				MiSum[j] = max(MiSum[j], MiSum[j - Pi[i]] + Mi[i]); //ȡ������ֻ�Ͳ�������ֻ�����ֵ

		cout << MiSum[X] << endl; //���Ǯ��ΪX�������ֵ
	}

	return 0;
}