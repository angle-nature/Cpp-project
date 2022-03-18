#include<iostream>
#include<algorithm>
using namespace std;

#define MAXSIZE 1300000

struct Result
{
	int mode=0;  //����
	int numbers=0;  //����
};

Result solve(int A[], int left, int right)  //left ���±�  ��right  ���±�
{
	Result result;  //�������ս��
	int length = right - left + 1; //���鳤��
	//����Ϊ1�����
	if (length == 1)
	{
		result.mode = A[left];
		result.numbers = 1;
		return result;
	}
	//����Ϊ2�����
	else if (length == 2)
	{
		if (A[left] != A[right])
		{
			result.mode = min(A[left], A[right]);
			result.numbers = 1;
		}
		else
		{
			result.mode = A[left];
			result.numbers = 2;
		}

		return result;
	}
	//�� lenght>2
	else
	{
		int mid = (left + right) / 2;  //�м��±�
		Result resultL = solve(A, left, mid);   //��ߵĽ��
		Result resultR = solve(A, mid + 1, right);  //�ұߵĽ��			
		//ȡ�������Ľ�� ��������� ȡ������С��
		if (resultL.numbers != resultR.numbers)
			result = resultL.numbers > resultR.numbers ? resultL : resultR;
		else
			result = resultL.mode < resultR.mode ? resultL : resultR;
		int count = 0;  //�м���������
		for (int i = left; i<=right; i++)
			if (A[i] == A[mid])
				count++;
		//ȡ�������Ľ�� ��������� ȡ������С��
		if (count > result.numbers)
		{
			result.mode = A[mid];
			result.numbers = count;
		}
		else if (count == result.numbers)
			result.mode = result.mode < A[mid] ? result.mode : A[mid];
		return result;
	}
}

int main()
{
	int *A = new int[MAXSIZE]; //�ڴ����  ���������
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	sort(A, A + n); //������Ԫ�ؽ�������

	Result maxResult = solve(A, 0, n - 1);

	cout << maxResult.mode << endl;  //�������
	cout << maxResult.numbers << endl;  //�������

	return 0;
}