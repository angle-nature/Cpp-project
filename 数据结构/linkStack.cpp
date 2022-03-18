#include<stdio.h>
#include<stdlib.h>
#include"linkStack.h"

//³õÊ¼»¯Á´Õ»
pLinkStack initLinkStack()
{
	BiTree t = (BiTree)malloc(sizeof(BiTNode));
	pLinkStack head;
	head = (pLinkStack)malloc(sizeof(linkStack));

	if (head != NULL)
	{
		head->data = t;
		head->next = NULL;
	}

	return head;
}

//ÅÐ¶ÏÁ´Õ»ÊÇ·ñÎª¿Õ
bool isEmptyLinkStack(pLinkStack S)
{
	if (S->next == NULL)
		return true;
	else
		return false;
}

//ÈëÕ»
bool pushLinkStack(pLinkStack S, DataType X)
{
	pLinkStack p;
	p = (pLinkStack)malloc(sizeof(linkStack));

	if (p == NULL)       //ÉêÇëÄÚ´æ¿Õ¼äÊ§°Ü£¬Õ»Âú  ÈëÕ»Ê§°Ü
		return false;

	else
	{
		p->data = X;
		p->next = S->next;
		S->next = p;
		return true;
	}
}

//³öÕ»
bool popLinkStack(pLinkStack S)
{
	if (isEmptyLinkStack(S))  //Õ»¿Õ  ³öÕ»Ê§°Ü
		return false;
	else
	{
		pLinkStack p;
		p = S->next;
		S->next = p->next;
		free(p);
		return true;
	}
}

//È¡Õ»¶¥ÔªËØ
DataType getTopLinkStack(pLinkStack S)
{
	if (!isEmptyLinkStack(S))
		return S->next->data;
	else
	{
		printf("Õ»Îª¿Õ£¡");
		return 0;
	}

}

//Ïú»ÙÕ»
void destroyLinkStack(pLinkStack S)
{
	if (!isEmptyLinkStack(S))
	{
		pLinkStack p;
		while (S->next != NULL)
		{
			p = S->next;
			S->next = p->next;
			free(p);
		}
	}
	free(S);
}

////´òÓ¡Õ»µÄËùÓÐÔªËØ
//void printLinkStack(pLinkStack S)
//{
//	if (!isEmptyLinkStack(S))
//	{
//		pLinkStack p;
//		p = S->next;
//		while (p != NULL)
//		{
//			printf("%d", p->data);
//			p = p->next;
//		}
//
//		putchar('\n');
//	}
//
//	else
//		printf("Õ»Îª¿Õ£¡");
//}