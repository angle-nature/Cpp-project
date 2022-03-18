#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct PCB
{
	int pid;                 //进程标识符
	int priority;            //进程优先级
	int size;                //进程大小
	char content[20];        //进程内容
	int state;               //进程状态   0表示不在内存   1表示内存  2表示挂起
};

struct PCB memory[20];     //内存大小
int number = 0, pid_1;
int hangUp = 0;    //被挂起的总进程数
int flag = 0;

//创建新的进程
void create()  /* 创建一个进程的示例（不完整的程序） */
{
	if (number >= 20)       //判断是否有存储空间
		printf("\n 内存已满，请删除或挂起其他程序");
	else {

		int index;
		for (int i = 0; i < 20; i++)  //按顺序在内存中寻找创建新进程的空间
			if (memory[i].state == 0)    //state 为 0  表示不在内存
			{
				index = i;
				break;
			}
	
		printf("\n请输入新建进程的pid值\n");
		scanf_s("%d", &memory[index].pid);

		for (int j = 0; j < index; j++)   //判断是否之前已存储相同pid进程
			if (memory[j].pid == memory[index].pid)
			{
				printf("\n该进程已存在于内存中");
				return;
			}
		printf("\n请输入新进程的优先级 \n");
		scanf_s("%d", &memory[index].priority);
		printf("\n请输入新进程的大小\n");
		scanf_s("%d", &memory[index].size);
		printf("\n请输入新进程的内容\n");
		
		getchar();
		char c;
		int j = 0;
		while ((c=getchar())!='\n')
		{
			memory[index].content[j] = c;
			j++;
		}

		memory[index].state = 1;    //将进程状态设为 1，表示在内存中
		number++;       //内存中进程数目加 1
	}
}

//查看进程
void run()
{
	flag = 0;    //表示内存中是否有进程

	for (int i = 0; i < 20; i++)
	{
		if (memory[i].state == 1)  //state 为 1   表示内存中有进程
		{
			printf("\n pid=%d", memory[i].pid);
			printf("   priority=%d", memory[i].priority);
			printf("   size=%d", memory[i].size);
			printf("   content=%s", memory[i].content);
			flag = 1;  //表示内存中有进程
		}
	}

	if (flag == 0)
		printf("\n内存中没有进程!");

	getchar();
	getchar();
}

//换出进程
void huanchu()
{
	if (number == 0)  //num=0,表示内存中无进程
	{
		printf("\n当前没有运行的进程\n");
		return;
	}
	printf("\n请输入要换出的进程的pid值\n");
	scanf_s("%d", &pid_1);

	flag = 0;

	for (int i = 0; i < 20; i++)
	{
		if (pid_1 == memory[i].pid)
		{
			if (memory[i].state == 1)
			{
				memory[i].state = 2;  //将该进程的状态设为挂起
				hangUp++;
				number--;
				printf("\n该进程已成功挂起换出\n");
			}
			else if (memory[i].state == 0)
				printf("\n要换出的进程不存在\n");
			else 
				printf("\n要换出的进程已经被挂起\n");
			flag = 1; break;
		}
	}
	if (flag == 0) 
		printf("\n要换出的进程不存在\n");

	getchar();
	getchar();
}

//杀死进程
void kill()
{
	if (number == 0)  //num=0,表示内存中无进程
	{
		printf("\n当前没有运行的进程\n");
		return;
	}

	printf("\n请输入要杀死的进程的pid值\n");
	scanf_s("%d", &pid_1);
	flag = 0;

	for (int i = 0; i < 20; i++)
	{
		if (pid_1 == memory[i].pid)
		{
			if (memory[i].state == 1)
			{
				memory[i].state = 0; //将该进程的状态设为不在内存中
				number--;  //内存中的进程数目减少一个
				printf("\n该进程已成功杀死\n");
			}
			else if (memory[i].state == 0)
				printf("\n要杀死的进程不存在\n");
			else 
				printf("\n要杀死的进程已经被挂起\n");//剩余状态为2，挂起
			flag = 1; 
			break;
		}
	}
	if (flag == 0) 
		printf("\n要杀死的进程不存在\n");

	getchar();
	getchar();
}

//进程通讯
void tongxun()
{
	if (number == 0)
	{
		printf("当前没有运行的进程\n");
		getchar();
		getchar();
		return;
	}
	if (hangUp == 0)  //hangUp=0,表示没有挂起的进程
	{
		printf("\n当前没有挂起的进程\n");
		getchar();
		getchar();
		return;
	}
	printf("\n请输入要唤醒的进程的pid值:\n");
	scanf_s("%d", &pid_1);
	for (int i = 0; i < 20; i++) {
		if (pid_1 == memory[i].pid)
		{
			if (memory[i].state == 2)
			{
				memory[i].state = 1; //将该进程的状态设为运行
				hangUp--;
				number++;
				printf("\n该进程已成功唤醒\n");
			}
			else if (memory[i].state == 0)
				printf("\n要唤醒的进程不存在\n");
			else 
				printf("\n要唤醒的进程已经在内存中\n");
		}
	}
	getchar();
	getchar();
}

int main()
{
	int n = 1;
	char a;

	while (n == 1)
	{
		system("cls");   //清屏
		printf("\n********************************************");
		printf("\n*               进程演示系统               *");
		printf("\n********************************************");
		printf("\n     1.创建新的进程      2.查看运行进程     ");
		printf("\n     3.换出某个进程      4.杀死运行进程     ");
		printf("\n     5.进程之间通信      6.退出系统         ");
		printf("\n********************************************");
		printf("\n请选择（1～6）");
		a = getchar();
		switch (a)
		{
		case'1':
			create();
			break;
		case'2':
			run();
			break;
		case'3':
			huanchu();
			break;
		case'4':
			kill();
			break;
		case'5':
			tongxun();
			break;
		case'6': 
			exit(0);
		default: n = 0;
		}
	}
	return 0;
}