#include<stdio.h>
#include"linkStack.h"

int main()
{
	pLinkStack S = initLinkStack();

	char c[100];     //����˳��洢������ַ�
	char ch;
	int i = 0;

	printf("������Ҫ�жϵ��ַ������Ի��з���β��\n");
	while ((ch = getchar()) != '\n')
	{
		c[i] = ch;
		pushLinkStack(S, ch);  //������ջ
		i++;
	}

	int j = 0;
	bool flag = true;
	while (!isEmptyLinkStack(S))
	{
		//���ջ��Ԫ�ص��ַ���˳��洢���ַ���ͬ �� flag = false
		if (c[j] != getTopLinkStack(S))  
		{
			flag = false;
			break;
		}
		
		popLinkStack(S);  //��ջ
		j++;
	}

	printf("�жϽ����\n");
	if(flag)
		printf("YES!");
	else
		printf("NO!");

	return 0;
}