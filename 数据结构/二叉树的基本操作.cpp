#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include"linkStack.h"

#define MAXLEN 100
#define NLAYER  4

//typedef struct BiTNode               // ����������ڵ�ṹ
//{
//	char data;                       // ������
//	struct BiTNode* LChild, * RChild;  // ���Һ���ָ����
//}BiTNode, * BiTree;
BiTree T;

//����������
BiTree CreateBiTree()// �����������н����������Ķ�������Ĺ���
{
	BiTree bt;
	char ch;
	ch = getchar();
	if (ch == '#') 
		bt = NULL;
	else
	{
		bt = (BiTree)malloc(sizeof(BiTNode)); // ����һ���½��
		bt->data = ch;
		bt->LChild = CreateBiTree();      // ����������
		bt->RChild = CreateBiTree();      // ����������
	}
	return bt;
}

////���ʹ�ӡ������
//void TranslevelPrint(BiTree bt)
//{  //���㷨ʵ�ֶ������İ����ӡ
//	struct node
//	{
//		BiTree vec[MAXLEN];           // ����������
//		int layer[MAXLEN];            // ������ڵĲ�
//		int locate[MAXLEN];           // ��ӡ����λ��
//		int front, rear;
//	}q;                               // �������q
//	int i, j, k;
//	int nLocate;
//	j = 1;
//	k = 0;
//	q.front = 0;                      // ��ʼ������q��ͷ����β
//	q.rear = 0;
//	printf(" ");
//	q.vec[q.rear] = bt;               // �����������ڵ������
//	q.layer[q.rear] = 1;
//	q.locate[q.rear] = 20;
//	q.rear = q.rear + 1;
//	while (q.front < q.rear)
//	{
//		bt = q.vec[q.front];
//		i = q.layer[q.front];
//		nLocate = q.locate[q.front];
//		if (j < i)                      // �����ӡʱ����
//		{
//			printf("\n");
//			printf("\n");
//			j = j + 1;
//			k = 0;
//			while (k < nLocate)
//			{
//				printf(" ");
//				k++;
//			}
//		}
//		while (k < (nLocate - 1))          // ���ý����ȿ��ƺ���λ��
//		{
//			printf(" ");
//			k++;
//		}
//		printf("%c", bt->data);
//		q.front = q.front + 1;
//		if (bt->LChild != NULL)          // �����������������������ڵ������
//		{
//			q.vec[q.rear] = bt->LChild;
//			q.layer[q.rear] = i + 1;
//			q.locate[q.rear] = (int)(nLocate - pow(2, NLAYER - i - 1));
//			q.rear = q.rear + 1;
//		}
//		if (bt->RChild != NULL)         // �����������������������ڵ������
//		{
//			q.vec[q.rear] = bt->RChild;
//			q.layer[q.rear] = i + 1;
//			q.locate[q.rear] = (int)(nLocate + pow(2, NLAYER - i - 1));
//			q.rear = q.rear + 1;
//		}
//	}
//}

//������
void Visit(char ch)
{
	printf("%c  ", ch);
}

//�ݹ��������������
void  PreOrder(BiTree root)
{// �������������, rootΪָ�������(��ĳһ����)������ָ��
	if (root != NULL)
	{
		Visit(root->data);       // ���ʸ����
		PreOrder(root->LChild);  // �������������
		PreOrder(root->RChild);  // �������������
	}
}

//�ݹ��������������
void  InOrder(BiTree root)
{// �������������, rootΪָ�������(��ĳһ����)������ָ��
	if (root != NULL)
	{
		InOrder(root->LChild);    // �������������
		Visit(root->data);        // ���ʸ����
		InOrder(root->RChild);    // �������������
	}
}

//�ݹ�������������
void  PostOrder(BiTree root)
{//���������������rootΪָ�������(��ĳһ����)������ָ��
	if (root != NULL)
	{
		PostOrder(root->LChild);  // �������������
		PostOrder(root->RChild);  // �������������
		Visit(root->data);        // ���ʸ����
	}
}

//�ǵݹ��������������
void preOrder(const BiTree bt)
{
	BiTree p = bt;
	pLinkStack S;
	S = initLinkStack();  //��ʼ��ջ
	while (p||!isEmptyLinkStack(S))
	{
		if (p)
		{
			Visit(p->data);  //�ȷ���
			pushLinkStack(S,p); 
			p = p->LChild; //������������
		}
		else
		{
			p = getTopLinkStack(S); //ȡջ��Ԫ�ظ�p
			popLinkStack(S); //��ջ
			p = p->RChild; //pָ��p��������
		}
	}
}

//�ǵݹ��������������
void inOrder(const BiTree bt)
{
	BiTree p = bt;
	pLinkStack S;
	S = initLinkStack();  //��ʼ��ջ
	while (p || !isEmptyLinkStack(S))
	{
		if (p)
		{
			pushLinkStack(S, p); 
			p = p->LChild; //������������
		}
		else
		{
			p = getTopLinkStack(S); //ȡջ��Ԫ�ظ�p
			popLinkStack(S); //��ջ
			Visit(p->data);  //����
			p = p->RChild; //pָ��p��������
		}
	}
}

//�ǵݹ�������������
void postOrder(const BiTree bt)
{
	BiTree p = bt;
	pLinkStack S1;  //����������ջ
	pLinkStack S2;  //����ջ
	S1 = initLinkStack();
	S2 = initLinkStack();  //��ʼ��ջ
	while (p || !isEmptyLinkStack(S2))
	{
		if (p)
		{
			pushLinkStack(S1, p);
			pushLinkStack(S2, p); 
			p = p->RChild; 
		}
		else
		{
			p = getTopLinkStack(S2); //ȡջ��Ԫ�ظ�p
			popLinkStack(S2); //��ջ
			p = p->LChild; 
		}
	}

	while (!isEmptyLinkStack(S1))
	{
		p = getTopLinkStack(S1); //ȡջ��Ԫ�ظ�p
		popLinkStack(S1); //��ջ
		Visit(p->data); //���ʽ��
	}
}

//���Ҷ�ӽ��
void  PreOrderLeaf(BiTree root)
{//������������������Ҷ�ӽ��, rootΪָ�������������ָ��
	if (root != NULL)
	{
		if (root->LChild == NULL && root->RChild == NULL)
			printf("%c  ", root->data);   // ���Ҷ�ӽ��
		PreOrderLeaf(root->LChild);      // �������������
		PreOrderLeaf(root->RChild);      // �������������
	}
}

//���Ҷ�ӽ��ĸ���
int LeafCount(BiTree root)
{
	int LeafNum;
	if (root == NULL)
		LeafNum = 0;
	else
		if ((root->LChild == NULL) && (root->RChild == NULL))
			LeafNum = 1;
		else
			LeafNum = LeafCount(root->LChild) + LeafCount(root->RChild);	// Ҷ����Ϊ����������Ҷ����Ŀ֮��

	return LeafNum;
}
/*
int leafCount(BiTree root)
{   //����������洢��root.a[1]����a[N],�ս����'#'��ʾ
	int sum = 0;

	for(i=1;i<=N;i++)
		if(root.a[i] != '#' && ( i>N/2 || root.a[i*2]=='#'&&a[i*2+1]=='#'))
			sum++;
	return sum;
}
*/
//��������������
int PostTreeDepth(BiTree root)   // ������������������ȵݹ��㷨 
{
	int hl, hr, max;
	if (root != NULL)
	{
		hl = PostTreeDepth(root->LChild);  // �������������
		hr = PostTreeDepth(root->RChild);  // ������������� 
		max = hl > hr ? hl : hr;           // �õ�����������Ƚϴ���
		return(max + 1);                   // ����������� 
	}
	else return 0;                      // ����ǿ������򷵻�0 
}



////(10) ��Ҫ�����������������û�����
//void mainwork()
//{
//	int yourchoice;
//
//	printf("\n------------------------��ӭʹ�ö�����������������---------------------------\n");
//	printf("\n                               �� �� ѡ ��                                 \n\n");
//	printf("        1. ��״���������                        2. �������������             \n");
//	printf("        3. �������������                        4. �������������             \n");
//	printf("        5. ���Ҷ�ӽ��                          6. ���Ҷ�ӽ�����           \n");
//	printf("        7. ��������������                      8. �˳�                       \n");
//	printf("\n-----------------------------------------------------------------------------\n");
//	printf("���������ѡ��");
//	scanf_s("%d", &yourchoice);
//	while (!(yourchoice == 1 || yourchoice == 2 || yourchoice == 3 || yourchoice == 4 || yourchoice == 5 || yourchoice == 6
//		|| yourchoice == 7 || yourchoice == 8))
//	{
//		printf("����ѡ����ȷ��������\n");
//		scanf_s("%d", &yourchoice);
//	}
//	while (1)
//	{
//		switch (yourchoice)
//		{
//		case 1:	printf("������״Ϊ:\n"); TranslevelPrint(T);  getchar();		break;
//		case 2:	printf("�����������Ϊ:"); PreOrder(T);	break;
//		case 3:	printf("\n�����������Ϊ:"); InOrder(T); break;
//		case 4:	printf("\n�����������Ϊ:"); PostOrder(T);	break;
//		case 5:	printf("Ҷ�ӽ��Ϊ:"); PreOrderLeaf(T); 	break;
//		case 6:	printf("Ҷ�ӽ�����Ϊ:%d", LeafCount(T));	        break;
//		case 7: printf("�����������Ϊ:%d", PostTreeDepth(T));   break;
//		case 8: system("cls");	exit(0); 			break;
//		default:  break;
//		}
//
//		printf("\n------------------------��ӭʹ�ö�����������������---------------------------\n");
//		printf("\n                               �� �� ѡ ��                                 \n\n");
//		printf("        1. ��״���������                        2. �������������             \n");
//		printf("        3. �������������                        4. �������������             \n");
//		printf("        5. ���Ҷ�ӽ��                          6. ���Ҷ�ӽ�����           \n");
//		printf("        7. ��������������                      8. �˳�                       \n");
//		printf("\n-----------------------------------------------------------------------------\n");
//
//		printf("\n���������ѡ��");
//		scanf_s("%d", &yourchoice);
//	}//endwhile(1)
//
//}//mainwork

//(11) �����������������������ù�����ģ�麯��
int main()
{
	printf("�밴�������������㣺('#'����ս��)\n");
	BiTree bt = CreateBiTree();
	printf("\n�ݹ�������������\n");
	PreOrder(bt);
	printf("\n�ݹ�������������\n");
	InOrder(bt);
	printf("\n�ݹ������������\n");
	PostOrder(bt);
	printf("\n�ǵݹ�������������\n");
	preOrder(bt);
	printf("\n�ǵݹ�������������\n");
	inOrder(bt);
	printf("\n�ǵݹ������������\n");
	postOrder(bt);
	printf("\nҶ�ӽ�����Ϊ��\n");
	printf("%d", LeafCount(bt));
	printf("\n�������Ϊ��\n");
	printf("%d",PostTreeDepth(bt));

	return 0;
}
