#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct node
{
	int arr[MAXSIZE];
	int length;
}seqList,*pSeqList;

//创建包含 n 个数的顺序表
pSeqList creatSeqList(int n)
{
	pSeqList p = (pSeqList)malloc(sizeof(node));
	p->length = n;
	
	//从 arr[0] 开始存 1
	for (int i = 0; i < n; i++)
	{
		p->arr[i] = i+1;
	}

	return p;
}

//删除指定下标数组元素
void deleteSeqList(pSeqList p,int index)
{
	for (int i = index; i < p->length-1; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}

	p->length--;
}

//解决约瑟夫环问题
pSeqList josephus_SeqList(pSeqList p, int circleCount)
{
	int count = 0;
	int i = 0;
	while (p->length > 1)
	{
		i = (i + 1) % p->length;  //数组下标  对数组长度取模构成循环
		count++;  //循环次数
		if (count == circleCount-1 )  //每当循环到循环次数的前一个人时  进入条件语句
		{
			printf("%d号已出局\n", p->arr[i]);  //因为数组下标从0开始  故删除下标i对应的数组元素
			deleteSeqList(p, i);  //删除元素
			count = 0;  //删除后将count置零  开始下一轮循环
		}

	}

	return p;
}

int main()
{
	printf("顺序表实现：\n\n");

	int number, circleCount;
	printf("请输入总人数n和循环次数c：");
	scanf_s("%d%d", &number, &circleCount);

	printf("=================\n出局顺序为：\n");
	pSeqList p=josephus_SeqList(creatSeqList(number), circleCount);

	printf("=====================\n");
	printf("未出局人id：%d\n",p->arr[0]);

	free(p);

	return 0;
}