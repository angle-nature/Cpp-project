#include<stdio.h>
#include"linkStack.h"

bool isLegal(char *a, int n)
{
	pLinkStack S = initLinkStack();

	for (int i = 0; i < n; i++)
	{
		if (a[i] == 'I')
			pushLinkStack(S, a[i]);
		if (a[i] == 'O')
			if (isEmptyLinkStack(S))
				return false;
			else
				popLinkStack(S);
	}
	if (isEmptyLinkStack(S))
		return true;
	else
		return false;
}

int main()
{
	char ch[100];
	char c;
	int i = 0;
	while ((c=getchar())!='\n')
	{
		ch[i] = c;
		i++;
	}

	if (isLegal(ch, i ))
		printf("�����кϷ���");
	else
		printf("�����в��Ϸ���");

	return 0;
}