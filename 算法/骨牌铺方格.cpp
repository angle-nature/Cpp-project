#include<iostream>
using namespace std;

long long total(int left, int right) //left ���±�  ��right  ���±�
{	
	if (right - left <= 2)
		return (long long)right-(long long)left;
	else
	{
		int mid = (right + left) / 2;
		long long countL1 = total(left, mid);  //��߷�������
		long long countR1 = total(mid , right);	//�ұ߷�������
		long long countL2;
		if (mid - 1 == left) //�����߲���ֻ��һ������ ���Խ�м����벿�ֵķ�������Ϊ1
			countL2 = 1; //�������  ���뵥��д��
		else
			countL2 = total(left, mid - 1);  //��Խ�м����벿�ֵķ�������

		long long countR2 = total(mid + 1, right); //��Խ�м���Ұ벿�ֵķ�������

		return countL1 * countR1 + countL2 * countR2;  //���շ�������
	}

}

int main()
{
	int n;
	cin >> n;
	cout << total(0, n) << endl;

	return 0;
}