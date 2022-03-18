#pragma once
#define MAXNUM 50

typedef char DataType;
typedef struct BiTNode/*�����������ݽṹ����*/
{
	DataType data;
	struct BiTNode* lchild, * rchild;
}BiTree;

BiTree* BiTreeCreate();
void BiTreePreTra(BiTree* t);
void BiTreeInTra(BiTree* t);
void BiTreePostTra(BiTree* t);
int BiTreeDepthPost(BiTree* t);