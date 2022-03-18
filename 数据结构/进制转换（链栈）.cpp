#include<stdio.h>
#include"linkStack.h"

void conversion(int N, int  r)
{
	pLinkStack S = initLinkStack();

	while (N != 0)
	{
		pushLinkStack(S, N % r);  //��������ջ
		N /= r;  
	}

	printLinkStack(S);        //���ջ�е�Ԫ��

	destroyLinkStack(S);      //����ջ
}

int main()
{
	int N, r;
	printf("������Ҫת������N�ͽ�����r��");
	scanf_s("%d%d", &N, &r);

	conversion(N, r);

	return 0;
}