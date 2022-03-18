#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define N 20

typedef int DataType;
typedef struct node
{
	char ch;
	DataType weight;
	int lChild, rChild, parent;
}HtNode;

typedef struct
{
	char* code;
	char leaf;
	int length;
}codeType;

//ѡ��hufftree������Ȩֵ��С������Ԫ�ص��±�
void select(HtNode huftree[], int n, int* s1, int* s2)
{
	int min1 = INT_MAX, min2 = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		if (huftree[i].weight < min1 && huftree[i].parent == -1)
		{
			min1 = huftree[i].weight;
			*s1 = i;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (huftree[i].weight < min2 && i!=(*s1) && huftree[i].parent == -1)
		{
			min2 = huftree[i].weight;
			*s2 = i;
		}
	}
}

void HufCoding(HtNode huftree[], codeType cd[], int w[], int n)
{
	//������������ھ�̬����huftree�У�w��Ž��Ȩ�أ�n��Ҷ�Ӹ���������Ǳ������cd[]
	int i, j, k, s1, s2, s, m, f, c, sum;
	char temp[N]; //�ݴ�Ҷ�ӱ����ַ����������Ҫת��
	m = 2 * n - 1; //������������Ľ������2

	for (i = 1; i <= n; i++)//��ʼ������Ҷ�ӽ��
	{
		huftree[i].weight = w[i - 1];
		huftree[i].lChild = huftree[i].rChild = huftree[i].parent = -1;
		printf("�������%d�����ķ��ţ�", i);
		huftree[i].ch = getchar();
		getchar();
	}

	for (i = n + 1; i <= m; i++)//��ʼ���������ɽ��
	{
		huftree[i].weight = -1;
		huftree[i].lChild = huftree[i].rChild = huftree[i].parent = -1;
	}

	for (i = 1; i <= n - 1; i++)
	{
		select(huftree,n+i-1,&s1,&s2); //ѡȡ��С��Ȩֵ�����������±�
		sum = huftree[s1].weight + huftree[s2].weight;
		huftree[n + i].weight = sum;
		huftree[s1].parent = huftree[s2].parent = n + i; //���ɽ�㰴�����huftree������
		huftree[n + i].lChild = s1;
		huftree[n + i].rChild = s2;
	}

	for (i = 1; i <= n; i++)
	{
		c = 0;//���볤��
		for (k = i, f = huftree[i].parent; f != -1; k = f, f = huftree[f].parent) //��Ҷ�ӽ�����������
			if (huftree[f].lChild == k)
			{
				temp[c] = '0'; //���ӱ���Ϊ 0
				c++; //���볤�ȼ�һ
			}
			else
			{
				temp[c] = '1'; //�Һ��ӱ���Ϊ 1
				c++;
			}
		cd[i].code = (char*)malloc((c + 1) * sizeof(char)); //���볤��Ϊc+1��char����  +1�Ǵ�Ž�β��־'\0'
		cd[i].code[c] = '\0';
		c--;
		k = 0;
		while (c>=0)
			cd[i].code[k++] = temp[c--]; //ת�� ��Ϊ֮ǰ�����Ǵ�Ҷ�ӽ�����������

		cd[i].leaf = huftree[i].ch;
		cd[i].length = k;
	}
}

int main()
{
	int n;  //Ҷ�ӽ�����
	int w[N]; //Ȩֵ
	char ch[N];//�ַ�
	printf("������Ҷ�ӽ�������");
	scanf_s("%d", &n);

	printf("�������Ҷ�ӽ��Ȩֵ��");
	for (int i = 0; i < n; i++)
		scanf_s("%d", &w[i]);

	getchar();
	HtNode huftree[2 * N - 1];
	codeType code[N+1];

	HufCoding(huftree, code, w, n); //������������������

	printf("\n�����Ĺ��������������£�\n");
	printf("���\t˫�׽��\t����\t�Һ���\n");
	for (int i = 1; i <= 2 * n - 1; i++)
		printf("%d\t%d\t\t%d\t%d\n", i, huftree[i].parent, huftree[i].lChild, huftree[i].rChild);
		
	printf("\n�����Ź������������£�\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%c��", code[i].leaf);
		puts(code[i].code);
		//putchar('\n');
	}

	return 0;
}