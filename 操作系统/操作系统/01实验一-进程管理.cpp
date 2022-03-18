#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct PCB
{
	int pid;                 //���̱�ʶ��
	int priority;            //�������ȼ�
	int size;                //���̴�С
	char content[20];        //��������
	int state;               //����״̬   0��ʾ�����ڴ�   1��ʾ�ڴ�  2��ʾ����
};

struct PCB memory[20];     //�ڴ��С
int number = 0, pid_1;
int hangUp = 0;    //��������ܽ�����
int flag = 0;

//�����µĽ���
void create()  /* ����һ�����̵�ʾ�����������ĳ��� */
{
	if (number >= 20)       //�ж��Ƿ��д洢�ռ�
		printf("\n �ڴ���������ɾ���������������");
	else {

		int index;
		for (int i = 0; i < 20; i++)  //��˳�����ڴ���Ѱ�Ҵ����½��̵Ŀռ�
			if (memory[i].state == 0)    //state Ϊ 0  ��ʾ�����ڴ�
			{
				index = i;
				break;
			}
	
		printf("\n�������½����̵�pidֵ\n");
		scanf_s("%d", &memory[index].pid);

		for (int j = 0; j < index; j++)   //�ж��Ƿ�֮ǰ�Ѵ洢��ͬpid����
			if (memory[j].pid == memory[index].pid)
			{
				printf("\n�ý����Ѵ������ڴ���");
				return;
			}
		printf("\n�������½��̵����ȼ� \n");
		scanf_s("%d", &memory[index].priority);
		printf("\n�������½��̵Ĵ�С\n");
		scanf_s("%d", &memory[index].size);
		printf("\n�������½��̵�����\n");
		
		getchar();
		char c;
		int j = 0;
		while ((c=getchar())!='\n')
		{
			memory[index].content[j] = c;
			j++;
		}

		memory[index].state = 1;    //������״̬��Ϊ 1����ʾ���ڴ���
		number++;       //�ڴ��н�����Ŀ�� 1
	}
}

//�鿴����
void run()
{
	flag = 0;    //��ʾ�ڴ����Ƿ��н���

	for (int i = 0; i < 20; i++)
	{
		if (memory[i].state == 1)  //state Ϊ 1   ��ʾ�ڴ����н���
		{
			printf("\n pid=%d", memory[i].pid);
			printf("   priority=%d", memory[i].priority);
			printf("   size=%d", memory[i].size);
			printf("   content=%s", memory[i].content);
			flag = 1;  //��ʾ�ڴ����н���
		}
	}

	if (flag == 0)
		printf("\n�ڴ���û�н���!");

	getchar();
	getchar();
}

//��������
void huanchu()
{
	if (number == 0)  //num=0,��ʾ�ڴ����޽���
	{
		printf("\n��ǰû�����еĽ���\n");
		return;
	}
	printf("\n������Ҫ�����Ľ��̵�pidֵ\n");
	scanf_s("%d", &pid_1);

	flag = 0;

	for (int i = 0; i < 20; i++)
	{
		if (pid_1 == memory[i].pid)
		{
			if (memory[i].state == 1)
			{
				memory[i].state = 2;  //���ý��̵�״̬��Ϊ����
				hangUp++;
				number--;
				printf("\n�ý����ѳɹ����𻻳�\n");
			}
			else if (memory[i].state == 0)
				printf("\nҪ�����Ľ��̲�����\n");
			else 
				printf("\nҪ�����Ľ����Ѿ�������\n");
			flag = 1; break;
		}
	}
	if (flag == 0) 
		printf("\nҪ�����Ľ��̲�����\n");

	getchar();
	getchar();
}

//ɱ������
void kill()
{
	if (number == 0)  //num=0,��ʾ�ڴ����޽���
	{
		printf("\n��ǰû�����еĽ���\n");
		return;
	}

	printf("\n������Ҫɱ���Ľ��̵�pidֵ\n");
	scanf_s("%d", &pid_1);
	flag = 0;

	for (int i = 0; i < 20; i++)
	{
		if (pid_1 == memory[i].pid)
		{
			if (memory[i].state == 1)
			{
				memory[i].state = 0; //���ý��̵�״̬��Ϊ�����ڴ���
				number--;  //�ڴ��еĽ�����Ŀ����һ��
				printf("\n�ý����ѳɹ�ɱ��\n");
			}
			else if (memory[i].state == 0)
				printf("\nҪɱ���Ľ��̲�����\n");
			else 
				printf("\nҪɱ���Ľ����Ѿ�������\n");//ʣ��״̬Ϊ2������
			flag = 1; 
			break;
		}
	}
	if (flag == 0) 
		printf("\nҪɱ���Ľ��̲�����\n");

	getchar();
	getchar();
}

//����ͨѶ
void tongxun()
{
	if (number == 0)
	{
		printf("��ǰû�����еĽ���\n");
		getchar();
		getchar();
		return;
	}
	if (hangUp == 0)  //hangUp=0,��ʾû�й���Ľ���
	{
		printf("\n��ǰû�й���Ľ���\n");
		getchar();
		getchar();
		return;
	}
	printf("\n������Ҫ���ѵĽ��̵�pidֵ:\n");
	scanf_s("%d", &pid_1);
	for (int i = 0; i < 20; i++) {
		if (pid_1 == memory[i].pid)
		{
			if (memory[i].state == 2)
			{
				memory[i].state = 1; //���ý��̵�״̬��Ϊ����
				hangUp--;
				number++;
				printf("\n�ý����ѳɹ�����\n");
			}
			else if (memory[i].state == 0)
				printf("\nҪ���ѵĽ��̲�����\n");
			else 
				printf("\nҪ���ѵĽ����Ѿ����ڴ���\n");
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
		system("cls");   //����
		printf("\n********************************************");
		printf("\n*               ������ʾϵͳ               *");
		printf("\n********************************************");
		printf("\n     1.�����µĽ���      2.�鿴���н���     ");
		printf("\n     3.����ĳ������      4.ɱ�����н���     ");
		printf("\n     5.����֮��ͨ��      6.�˳�ϵͳ         ");
		printf("\n********************************************");
		printf("\n��ѡ��1��6��");
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