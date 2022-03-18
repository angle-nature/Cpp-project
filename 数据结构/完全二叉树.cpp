#include <stdio.h>
#include<stdlib.h>

#define  max 30
#define NULL 0

//按完全二叉树思想将输入的字符串生成二叉树
typedef struct BNode
{
    char  data;     /*数据域 */
    struct BNode* lchild, * rchild;;    //指向左右子女 
}BinTree;

void preorder(BinTree* t); //声明先根遍历函数
void inorder(BinTree* t);  //声明中根遍历函数
void postorder(BinTree* t);//声明后根遍历函数
int leafs(BinTree* b);      //声明求叶子数函数
int treedeep(BinTree* p);   //声明求树的深度函数
BinTree* swap(BinTree* p);  //声明交换二叉树的所有结点的左右子树的函数


//将字符串中的第i个字符开始的m个字符作为数据生成对应的二叉树
BinTree* cre_tree(char* str, int i, int m)
{
    BinTree* p;

    if (i >= m)   //无效结点
        return NULL;

    p = (BinTree*)malloc(sizeof(BinTree));//生成新结点
    p->data = str[i];
    p->lchild = cre_tree(str, 2 * i + 1, m);//创建新结点的左子树
    p->rchild = cre_tree(str, 2 * i + 2, m);//创建新结点的右子树

    return p;
}


int main()
{
    int i, n;
    char str[max];
    BinTree* root;//根结点

    printf("请输入二叉树的结点数:");
    scanf_s("%d", &n);
    getchar();//输入数字
    printf("请输入长度为 %d 的字符串 :", n);

    for (i = 0; i < n; i++)
        scanf_s("%c", &str[i]);

    printf("\n");
    root = cre_tree(str, 0, n);
    printf("二叉树已成功创建! 结点序列为：");
    for (i = 0; i < n; i++)
        printf(" %c ", str[i]);

    printf("\n");

    //先根遍历
    printf("\n先根遍历结果:");
    preorder(root);
    printf("\n");

    //中根遍历
    printf("\n中根遍历结果:");
    inorder(root);
    printf("\n");

    //后根遍历
    printf("\n后根遍历结果:");
    postorder(root);
    printf("\n");

    printf("\n叶子数为：%d\n", leafs(root));
    printf("\n树的深度为：%d\n", treedeep(root));
    printf("\n交换左右子树后先序遍历序列为：");
    preorder(swap(root));

    printf("\n\n");
    return 0;
}

//先序遍历
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

//中序遍历
void inorder(BinTree* t)
{
    if (t != NULL)
    {
        inorder(t->lchild);
        printf(" %c ", t->data);
        inorder(t->rchild);
    }
}

//后序遍历
void postorder(BinTree* t)
{
    if (t != NULL)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf(" %c ", t->data);
    }
}


int leafs(BinTree* b)//求叶子数
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

int treedeep(BinTree* p)//求树的深度
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


BinTree* swap(BinTree* p)//交换二叉树的所有结点的左右子树
{
    BinTree* stack[max];

    int k = 0;
    stack[k] = NULL;
    if (p != NULL)
    {
        stack[++k] = p->lchild;  //交换根节点的左右孩子子树
        p->lchild = p->rchild;
        p->rchild = stack[k];
        p->lchild = swap(p->lchild);  //交换p->lchild的孩子左右子树
        p->rchild = swap(p->rchild);  //交换p->rchild的孩子左右子树
    }

    return p;
}