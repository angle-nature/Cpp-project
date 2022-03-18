#include<stdio.h>
#include"linkStack.h"

void conversion(int N, int  r)
{
	pLinkStack S = initLinkStack();

	while (N != 0)
	{
		pushLinkStack(S, N % r);  //将余数入栈
		N /= r;  
	}

	printLinkStack(S);        //输出栈中的元素

	destroyLinkStack(S);      //销毁栈
}

int main()
{
	int N, r;
	printf("请输入要转换的数N和进制数r：");
	scanf_s("%d%d", &N, &r);

	conversion(N, r);

	return 0;
}