#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 100
#define NLAYER  4

typedef struct BiTNode               // 定义二叉树节点结构
{
	char data;                       // 数据域
	struct BiTNode* LChild, * RChild;  // 左右孩子指针域
}BiTNode, * BiTree;
BiTree T;

//建立二叉树
void CreateBiTree(BiTree* bt)
{ // 按照先序序列建立二叉树的二叉链表的过程
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')
		*bt = NULL;
	else
	{
		*bt = (BiTree)malloc(sizeof(BiTNode)); // 生成一个新结点
		(*bt)->data = ch;
		CreateBiTree(&((*bt)->LChild));      // 生成左子树
		CreateBiTree(&((*bt)->RChild));      // 生成右子树
	}
}

//树型打印二叉树
void TranslevelPrint(BiTree bt)
{  //本算法实现二叉树的按层打印
	struct node
	{
		BiTree vec[MAXLEN];           // 存放树根结点
		int layer[MAXLEN];            // 结点所在的层
		int locate[MAXLEN];           // 打印结点的位置
		int front, rear;
	}q;                               // 定义队列q
	int i, j, k;
	int nLocate;
	j = 1;
	k = 0;
	q.front = 0;                      // 初始化队列q队头，队尾
	q.rear = 0;
	printf(" ");
	q.vec[q.rear] = bt;               // 将二叉树根节点入队列
	q.layer[q.rear] = 1;
	q.locate[q.rear] = 20;
	q.rear = q.rear + 1;
	while (q.front < q.rear)
	{
		bt = q.vec[q.front];
		i = q.layer[q.front];
		nLocate = q.locate[q.front];
		if (j < i)                      // 进层打印时换行
		{
			printf("\n");
			printf("\n");
			j = j + 1;
			k = 0;
			while (k < nLocate)
			{
				printf(" ");
				k++;
			}
		}
		while (k < (nLocate - 1))          // 利用结点深度控制横向位置
		{
			printf(" ");
			k++;
		}
		printf("%c", bt->data);
		q.front = q.front + 1;
		if (bt->LChild != NULL)          // 存在左子树，将左子树根节点入队列
		{
			q.vec[q.rear] = bt->LChild;
			q.layer[q.rear] = i + 1;
			q.locate[q.rear] = (int)(nLocate - pow(2, NLAYER - i - 1));
			q.rear = q.rear + 1;
		}
		if (bt->RChild != NULL)         // 存在右子树，将右子树根节点入队列
		{
			q.vec[q.rear] = bt->RChild;
			q.layer[q.rear] = i + 1;
			q.locate[q.rear] = (int)(nLocate + pow(2, NLAYER - i - 1));
			q.rear = q.rear + 1;
		}
	}
}

//输出结点
void Visit(char ch)
{
	printf("%c  ", ch);
}

//先序遍历二叉树
void  PreOrder(BiTree root)
{// 先序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针
	if (root != NULL)
	{
		Visit(root->data);       // 访问根结点
		PreOrder(root->LChild);  // 先序遍历左子树
		PreOrder(root->RChild);  // 先序遍历右子树
	}
}

//中序遍历二叉树
void  InOrder(BiTree root)
{// 中序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针
	if (root != NULL)
	{
		InOrder(root->LChild);    // 中序遍历左子树
		Visit(root->data);        // 访问根结点
		InOrder(root->RChild);    // 中序遍历右子树
	}
}

//后序遍历二叉树
void  PostOrder(BiTree root)
{//后序遍历二叉树，root为指向二叉树(或某一子树)根结点的指针
	if (root != NULL)
	{
		PostOrder(root->LChild);  // 后序遍历左子树
		PostOrder(root->RChild);  // 后序遍历右子树
		Visit(root->data);        // 访问根结点
	}
}
int main()
{
	printf("首先请输入二叉树的结点序列：\n");
	CreateBiTree(&T);
	printf("树形结构为：\n");
	TranslevelPrint(T);
	printf("\n先序遍历：");
	PreOrder(T);
	printf("\n中序遍历：");
	InOrder(T);
	printf("\n后序遍历：");
	PostOrder(T);
	return 0;
}
