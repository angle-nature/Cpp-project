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

//选择hufftree数组中权值最小的两个元素的下标
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
	//哈夫曼树存放在静态链表huftree中，w存放结点权重，n是叶子个数，最后是编码放在cd[]
	int i, j, k, s1, s2, s, m, f, c, sum;
	char temp[N]; //暂存叶子编码字符串，最后需要转置
	m = 2 * n - 1; //计算哈夫曼树的结点总数2

	for (i = 1; i <= n; i++)//初始化所有叶子结点
	{
		huftree[i].weight = w[i - 1];
		huftree[i].lChild = huftree[i].rChild = huftree[i].parent = -1;
		printf("请输入第%d个结点的符号：", i);
		huftree[i].ch = getchar();
		getchar();
	}

	for (i = n + 1; i <= m; i++)//初始化所有生成结点
	{
		huftree[i].weight = -1;
		huftree[i].lChild = huftree[i].rChild = huftree[i].parent = -1;
	}

	for (i = 1; i <= n - 1; i++)
	{
		select(huftree,n+i-1,&s1,&s2); //选取最小的权值的两个结点的下标
		sum = huftree[s1].weight + huftree[s2].weight;
		huftree[n + i].weight = sum;
		huftree[s1].parent = huftree[s2].parent = n + i; //生成结点按序放入huftree数组中
		huftree[n + i].lChild = s1;
		huftree[n + i].rChild = s2;
	}

	for (i = 1; i <= n; i++)
	{
		c = 0;//编码长度
		for (k = i, f = huftree[i].parent; f != -1; k = f, f = huftree[f].parent) //从叶子结点向根结点遍历
			if (huftree[f].lChild == k)
			{
				temp[c] = '0'; //左孩子编码为 0
				c++; //编码长度加一
			}
			else
			{
				temp[c] = '1'; //右孩子编码为 1
				c++;
			}
		cd[i].code = (char*)malloc((c + 1) * sizeof(char)); //申请长度为c+1的char数组  +1是存放结尾标志'\0'
		cd[i].code[c] = '\0';
		c--;
		k = 0;
		while (c>=0)
			cd[i].code[k++] = temp[c--]; //转置 因为之前编码是从叶子结点向根结点编码

		cd[i].leaf = huftree[i].ch;
		cd[i].length = k;
	}
}

int main()
{
	int n;  //叶子结点个数
	int w[N]; //权值
	char ch[N];//字符
	printf("请输入叶子结点个数：");
	scanf_s("%d", &n);

	printf("请输入各叶子结点权值：");
	for (int i = 0; i < n; i++)
		scanf_s("%d", &w[i]);

	getchar();
	HtNode huftree[2 * N - 1];
	codeType code[N+1];

	HufCoding(huftree, code, w, n); //构建哈夫曼树并编码

	printf("\n构建的哈夫曼树如下如下：\n");
	printf("序号\t双亲结点\t左孩子\t右孩子\n");
	for (int i = 1; i <= 2 * n - 1; i++)
		printf("%d\t%d\t\t%d\t%d\n", i, huftree[i].parent, huftree[i].lChild, huftree[i].rChild);
		
	printf("\n各符号哈夫曼编码如下：\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%c：", code[i].leaf);
		puts(code[i].code);
		//putchar('\n');
	}

	return 0;
}