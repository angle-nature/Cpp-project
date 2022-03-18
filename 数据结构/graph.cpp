#include<stdio.h>
#include<stdlib.h>
#include"SeqQueue.h"

#define MaxVerNum 100      /* ��󶥵���Ϊ*/
typedef enum { False, True } boolean;
boolean visited[MaxVerNum];

typedef struct node /* ����*/
{
    int adjvex;/* �ڽӵ���,һ���ǷŶ����Ӧ����Ż��ڱ�ͷ�����е��±�*/
    char  Info;         /*���(��)��ص���Ϣ*/
    struct node* next;   /* ָ����һ���ڽӵ��ָ����*/

}EdgeNode;

typedef struct vnode /* ������*/
{
    char  vertex; /* ������*/
    EdgeNode* firstedge;      /* �߱�ͷָ��*/

} VertexNode;


typedef  struct
{
    VertexNode  adjlist[MaxVerNum];    /* �ڽӱ�*/
    int n, e;                 /* �������ͱ���*/

} ALGraph; /* ALGraph�����ڽӱ�ʽ�洢��ͼ����*/

//����һ������ͼ���ڽӱ�洢���㷨���£�
void CreateALGraph(ALGraph* G)/* ��������ͼ���ڽӱ�洢*/
{
    int i, j, k;
    EdgeNode *p;
    printf("�����붥�����ͱ�����");
    scanf_s("%d %d", &G->n, &G->e);
    printf("n=%d,e=%d\n\n", G->n, G->e);
    getchar();
    for (i = 0; i < G->n; i++)   /* ������n������Ķ����*/
    {
        printf("�������%d�������ַ���Ϣ(��%d��)��", i + 1, G->n);
        scanf_s("%c", &(G->adjlist[i].vertex));   /* ���붥����Ϣ*/
        getchar();
        G->adjlist[i].firstedge = NULL;    /* ����ı߱�ͷָ����Ϊ��*/
    }

    for (k = 0; k < 2 * G->e; k++)              /* �����߱�*/
    {
        printf("�������<Vi,Vj>��Ӧ�Ķ������(��%d��)��", 2 * G->e);
        scanf_s("%d %d", &i, &j);/* �����<Vi,Vj>�Ķ����Ӧ���*/
        p = (EdgeNode*)malloc(sizeof(EdgeNode)); // �����±߱���p
        p->adjvex = j;  /* �ڽӵ����Ϊj */
        p->next = G->adjlist[i].firstedge;/* �����p���뵽����Vi������ͷ��*/
        G->adjlist[i].firstedge = p;
    }

    printf("\nͼ�ѳɹ�����!��Ӧ���ڽӱ����£�\n");
    for (i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstedge;
        printf("%c->", G->adjlist[i].vertex);
        while (p != NULL)
        {
            printf("[ %c ]", G->adjlist[p->adjvex].vertex);
            p = p->next;
        }
        printf("\n");

    }
    printf("\n");

}/*CreateALGraph*/

int FirstAdjVertex(ALGraph* g, int v)//��ͼg���붥��v���ڵĵ�һ������
{
    if (g->adjlist[v].firstedge != NULL) 
        return (g->adjlist[v].firstedge)->adjvex;
    else 
        return 0;
}

int NextAdjVertex(ALGraph* g, int vi, int vj)//��ͼg����vi���ڵģ�������ڶ���vj����һ�����ڶ���
{
    EdgeNode* p;
    p = g->adjlist[vi].firstedge;

    while (p != NULL && p->adjvex != vj) 
        p = p->next;
    if (p != NULL && p->next != NULL)  
        return p->next->adjvex;
    else return 0;
}

void  DFS(ALGraph* G, int v) /* �ӵ�v���������������ȱ���ͼG */
{
    EdgeNode* p;
    int w;
    printf("%c ", G->adjlist[v].vertex);

    visited[v] = True;   /* ���ʵ�v�����㣬���ѷ��ʱ�־��True */

    for (p = G->adjlist[v].firstedge; p; p = p->next)
    {
        w=p->adjvex;
        if (!visited[w])  /* ��v��δ���ʵ��ڽӶ���w�ݹ����DFS */
            DFS(G, w);
    }
      

}

void DFStraverse(ALGraph* G)
/*������ȱ������ڽӱ��ʾ��ͼG�������ڽӾ����ʾʱ���㷨��ȫ��ͬ*/
{
    int i, v;

    for (v = 0; v < G->n; v++)
        visited[v] = False;/*��־������ʼ��*/

    for(i=0;i<G->n;i++)
        if (!visited[i]) 
            DFS(G, i);

}/*DFS*/

void visit(ALGraph G, int v)
{
    printf("%c ", G.adjlist[v].vertex);
}

void BFS(ALGraph G, int v)
{
    EdgeNode* p;
    int u, w;
    pSeqQueue Q = initSeqQueue();
    visit(G, v);
    visited[v] = True;
    inSeqQueue(Q, v);
    while (!isEmptySeqQueue(Q))
    {
        u = frontSeqQueue(Q);
        outSeqQueue(Q);
        for (p = G.adjlist[u].firstedge; p; p = p->next)
        {
            w = p->adjvex;
            if (!visited[w])
            {
                visit(G, w);
                visited[w] = True;
                inSeqQueue(Q, w);
            }
        }
    }
}

void  BFStraverse(ALGraph  G)
{    /* ������ȱ���ͼG */

    int i, v;

    for (v = 0; v < G.n; v++)
        visited[v] = False;            /* ��־������ʼ��*/

    for (i = 0; i < G.n; i++)
        if(!visited[i])
            BFS(G,i);  /*  viδ���ʹ�����vi��ʼBFS����*/

}

int main()
{
    ALGraph G;

    CreateALGraph(&G);

    printf("������ͼ�����������������Ϊ��");
    DFStraverse(&G);

    printf("������ͼ�Ĺ��������������Ϊ��");
    BFStraverse(G);
    printf("\nSuccess!\n");
    return 0;
}



//�̲Ĺ�����ȱ����㷨�Ĳ��ֺ���(���ڽӾ���Ϊ�洢�ṹ)

//void  BFStraverse(MGraph  G)
//
//{    /* ������ȱ���ͼG */
//
//    int i, v;
//
//    for (v = 0; v < G.n; v++)
//
//        visited[v] = False;            /* ��־������ʼ��*/
//
//    for (i = 0; i < G.n; i++)
//
//        if(!visited[i])
//            BFS(G,i);  /*  viδ���ʹ�����vi��ʼBFS����*/
//
//}

//void  BFS(MGraph  G, int  v)
//{     /* ��vΪ�����㣬��ͼG����BFS����*/
//       int i��j;
//
//       PSeqQueue  Q;
//       Q = Init_SeqQueue();
//       Visite(v);                         /* ����*/
//       visited[v] = True;
//       In_SeqQueue(Q, v);                     /* ԭ�������*/
//       while(!Empty_SeqQueue(Q))
//       {  
//           Out_SeqQueue(Q,&i);                  /* vi������*/
//           for (j = 0; j < G.n; j++)            /* ��������vi���ڽӵ�vj */
//            if(G.edges[i][j] == 1 && !visited[j])   /* ��vjδ����*/
//            {  
//               Visite(j);                  /* ����vj  */
//               visited[j] = True;
//               In_SeqQueue(Q��j);                    /* ���ʹ���vj�����*/
//            }
//       }
//}/*BFS*/

