#include<stdio.h>
#include"linkStack.h"

int main()
{
	pLinkStack S = initLinkStack();

	char c[100];     //用来顺序存储输入的字符
	char ch;
	int i = 0;

	printf("请输入要判断的字符串，以换行符结尾：\n");
	while ((ch = getchar()) != '\n')
	{
		c[i] = ch;
		pushLinkStack(S, ch);  //依次入栈
		i++;
	}

	int j = 0;
	bool flag = true;
	while (!isEmptyLinkStack(S))
	{
		//如果栈顶元素的字符与顺序存储的字符不同 则 flag = false
		if (c[j] != getTopLinkStack(S))  
		{
			flag = false;
			break;
		}
		
		popLinkStack(S);  //出栈
		j++;
	}

	printf("判断结果：\n");
	if(flag)
		printf("YES!");
	else
		printf("NO!");

	return 0;
}