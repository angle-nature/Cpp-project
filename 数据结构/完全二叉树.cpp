#include <stdio.h>
#include<stdlib.h>

#define  max 30
#define NULL 0

//����ȫ������˼�뽫������ַ������ɶ�����
typedef struct BNode
{
    char  data;     /*������ */
    struct BNode* lchild, * rchild;;    //ָ��������Ů 
}BinTree;

void preorder(BinTree* t); //�����ȸ���������
void inorder(BinTree* t);  //�����и���������
void postorder(BinTree* t);//���������������
int leafs(BinTree* b);      //������Ҷ��������
int treedeep(BinTree* p);   //������������Ⱥ���
BinTree* swap(BinTree* p);  //�������������������н������������ĺ���


//���ַ����еĵ�i���ַ���ʼ��m���ַ���Ϊ�������ɶ�Ӧ�Ķ�����
BinTree* cre_tree(char* str, int i, int m)
{
    BinTree* p;

    if (i >= m)   //��Ч���
        return NULL;

    p = (BinTree*)malloc(sizeof(BinTree));//�����½��
    p->data = str[i];
    p->lchild = cre_tree(str, 2 * i + 1, m);//�����½���������
    p->rchild = cre_tree(str, 2 * i + 2, m);//�����½���������

    return p;
}


int main()
{
    int i, n;
    char str[max];
    BinTree* root;//�����

    printf("������������Ľ����:");
    scanf_s("%d", &n);
    getchar();//��������
    printf("�����볤��Ϊ %d ���ַ��� :", n);

    for (i = 0; i < n; i++)
        scanf_s("%c", &str[i]);

    printf("\n");
    root = cre_tree(str, 0, n);
    printf("�������ѳɹ�����! �������Ϊ��");
    for (i = 0; i < n; i++)
        printf(" %c ", str[i]);

    printf("\n");

    //�ȸ�����
    printf("\n�ȸ��������:");
    preorder(root);
    printf("\n");

    //�и�����
    printf("\n�и��������:");
    inorder(root);
    printf("\n");

    //�������
    printf("\n����������:");
    postorder(root);
    printf("\n");

    printf("\nҶ����Ϊ��%d\n", leafs(root));
    printf("\n�������Ϊ��%d\n", treedeep(root));
    printf("\n�������������������������Ϊ��");
    preorder(swap(root));

    printf("\n\n");
    return 0;
}

//�������
void preorder(BinTree* t)
{
    if (t != NULL)
    {
        printf(" %c ", t->data);
        if (t->lchild)
        {
            printf("->");
            preorder(t->lchild);
        }

        if (t->rchild)
        {
            printf("->");
            preorder(t->rchild);
        }
    }
}

//�������
void inorder(BinTree* t)
{
    if (t != NULL)
    {
        inorder(t->lchild);
        printf(" %c ", t->data);
        inorder(t->rchild);
    }
}

//�������
void postorder(BinTree* t)
{
    if (t != NULL)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf(" %c ", t->data);
    }
}


int leafs(BinTree* b)//��Ҷ����
{
    int num1, num2;
    if (b == NULL)  
        return (0);
    else if (b->lchild == NULL && b->rchild == NULL) 
        return (1);
    else
    {
        num1 = leafs(b->lchild);
        num2 = leafs(b->rchild);
        return(num1 + num2);
    }
}

int treedeep(BinTree* p)//���������
{
    int ldeep, rdeep, deep;

    if (p == NULL) 
        deep = 0;
    else
    {
        ldeep = treedeep(p->lchild);
        rdeep = treedeep(p->rchild);
        deep = (ldeep > rdeep ? ldeep : rdeep) + 1;
    }
    return deep;
}


BinTree* swap(BinTree* p)//���������������н�����������
{
    BinTree* stack[max];

    int k = 0;
    stack[k] = NULL;
    if (p != NULL)
    {
        stack[++k] = p->lchild;  //�������ڵ�����Һ�������
        p->lchild = p->rchild;
        p->rchild = stack[k];
        p->lchild = swap(p->lchild);  //����p->lchild�ĺ�����������
        p->rchild = swap(p->rchild);  //����p->rchild�ĺ�����������
    }

    return p;
}