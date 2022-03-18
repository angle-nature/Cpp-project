#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MAX 1000
#define CHARLENTH 50

//�˵�չʾ
void showMenu()
{
	printf("***************************\n");
	printf("*****  1�������ϵ��  *****\n");
	printf("*****  2����ʾ��ϵ��  *****\n");
	printf("*****  3��ɾ����ϵ��  *****\n");
	printf("*****  4��������ϵ��  *****\n");
	printf("*****  5���޸���ϵ��  *****\n");
	printf("*****  6�������ϵ��  *****\n");
	printf("*****  0���˳�ͨѶ¼  *****\n");
	printf("***************************\n");
}

//������ϵ�˽ṹ��
struct Person
{
	char m_Name[CHARLENTH];  //����
	char m_unit[CHARLENTH];  //��Ԫ
	char m_Addr[CHARLENTH];  //סַ
	char m_Telephone[CHARLENTH];  //�̶��绰
	char m_MobilePhone[CHARLENTH];  //�ƶ��绰
	char m_Classify[CHARLENTH];  //����
	char m_Email[CHARLENTH];  //����
	char m_QQ[CHARLENTH];  //QQ
};

//����ͨѶ¼�ṹ��
struct AddressBooks
{
	struct Person personArray[MAX];
	int m_Size;
};

//��ӡ��ϵ��
void printPerson(Person person)
{
	printf("������%s\t", person.m_Name);
	printf("��Ԫ��%s\t", person.m_unit);
	printf("סַ��%s\t", person.m_Addr);
	printf("�̶��绰��%s\t", person.m_Telephone);
	printf("�ƶ��绰��%s\t", person.m_MobilePhone);
	printf("���ࣺ%s\t", person.m_Classify);
	printf("Emali��%s\t", person.m_Email);
	printf("QQ��%s\n", person.m_QQ);
}

//�����ϵ��
void addPerson(struct AddressBooks* abs)
{

	if (abs->m_Size == MAX)
		printf("��ϵ���������޷�����ӣ�\n");
	
	else
	{
		printf("������������\n");
		getchar();
		gets_s(abs->personArray[abs->m_Size].m_Name);
		
		printf("�����뵥Ԫ��\n");
		gets_s(abs->personArray[abs->m_Size].m_unit);

		printf("������סַ��\n");
		gets_s(abs->personArray[abs->m_Size].m_Addr);

		printf("������̶��绰��\n");
		gets_s(abs->personArray[abs->m_Size].m_Telephone);

		printf("�������ƶ��绰��\n");
		gets_s(abs->personArray[abs->m_Size].m_MobilePhone);

		printf("���������\n");
		gets_s(abs->personArray[abs->m_Size].m_Classify);

		printf("���������䣺\n");
		gets_s(abs->personArray[abs->m_Size].m_Email);

		printf("������QQ��\n");
		gets_s(abs->personArray[abs->m_Size].m_QQ);

		abs->m_Size++;

		printf("��ӳɹ�\n");
		system("pause");  //�����������
		system("cls");    //����
	}
}

//��ʾ��ϵ��
void showPerson(struct AddressBooks* abs)
{
	if (abs->m_Size == 0)
		printf("��ǰͨѶ¼û����ϵ��\n");
	
	else
	{
		printf("������ϵ�����£�\n");
		for (int i = 0; i < abs->m_Size; i++)
		{
			
			printPerson(abs->personArray[i]);
			if (i % 9 == 0 && i != 0)
			{
				system("pause");
				system("cls");
				showMenu();
			}
		}
	}
			
	system("pause");
	system("cls");
}

//ɾ����ϵ��
void deletePerson(struct AddressBooks* abs)
{
	printf("������ɾ����ϵ��������\n");
	char name[20];
	getchar();
	gets_s(name);
	int sum = 0;
	int record[MAX];  //��¼�±�
	for (int i = 0; i < abs->m_Size; i++)	
		if (strcmp(name,abs->personArray[i].m_Name)==0)		
			record[sum++] = i;					
	
	if (sum == 1)
	{
		for (int i = record[sum-1]; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		printf("ɾ���ɹ���\n");
		cout << "ɾ���ɹ���" << endl;
		system("pause");
		system("cls");
	}
	else if (sum > 1)
	{
		printf("����������ϵ�ˣ���ѡ����Ҫɾ������ϵ����ţ�\n");
		for (int i = 0; i < sum; i++)
		{
			printf("%d��\t", i + 1);
			printPerson(abs->personArray[record[i]]);
		}
		int order;
		scanf_s("%d", &order);
		for (int i = record[order - 1]; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		printf("ɾ���ɹ�!\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("����ϵ�˲����ڣ�\n");
		system("pause");
		system("cls");
	}
}

//������ϵ��
void findPerson(AddressBooks* abs)
{
	printf("������Ҫ������ϵ��������\n");
	char name[20];
	getchar();
	gets_s(name);
	int sum = 0;
	int record[MAX];
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (strcmp(name, abs->personArray[i].m_Name) == 0)
		{
			record[sum++] = i;
		}
	}

	if (sum == 0)
	{
		printf("����ϵ�˲����ڣ�\n");
	}
	else
	{
		printf("����ϵ����Ϣ���£�\n");
		for (int i = 0; i < sum; i++)
		{
			printPerson(abs->personArray[record[i]]);
		}
	}

	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(AddressBooks* abs)
{
	printf("������Ҫ������ϵ��������\n");
	char name[20];
	getchar();
	gets_s(name);
	int sum = 0;
	int record[MAX];
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (strcmp(name, abs->personArray[i].m_Name) == 0)
		{
			record[sum++] = i;
		}
	}
	if (sum == 0)
	{
		printf("����ϵ�˲����ڣ�\n");
	}
	else if (sum == 1)
	{
		printf("����ϵ�˵���Ϣ���£�\n");
		printf("==============================\n");
		printPerson(abs->personArray[record[sum-1]]);
		printf("==============================\n");

		int select;
		printf("��ѡ����Ҫ�޸ĵ���Ϣ��\n1����Ԫ\n2��סַ\n3���̶��绰\n4���ƶ��绰\n5������\n6��Email\n7��QQ\n");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
		{
			printf("�����뵥Ԫ��\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_unit);
			break;
		}
		case 2:
		{
			printf("������סַ��\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Addr);
			break;
		}
		case 3:
		{
			printf("������̶��绰��\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Telephone);
			break;
		}
		case 4:
		{
			printf("�������ƶ��绰��\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_MobilePhone);
			break;
		}
		case 5:
		{
			printf("���������\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Classify);
			break;
		}
		case 6:
		{
			printf("������Email��\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Email);
			break;
		}
		case 7:
		{
			printf("������QQ��\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_QQ);
			break;
		}
		default:
			cout << "������������������!" << endl;
			break;
		}
	}
	else
	{
		cout << "����������ϵ�ˣ���ѡ���޸�" << endl;
		for (int i = 0; i < sum; i++)
		{
			printf("%d��\t", i + 1);
			printPerson(abs->personArray[record[i]]);
		}
		int order;
		scanf_s("%d", &order);
		int select;
		printf("��ѡ����Ҫ�޸ĵ���Ϣ��\n1����Ԫ\n2��סַ\n3���̶��绰\n4���ƶ��绰\n5������\n6��Email\n7��QQ\n");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
		{
			printf("�����뵥Ԫ��\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_unit);
			break;
		}
		case 2:
		{
			printf("������סַ��\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Addr);
			break;
		}
		case 3:
		{
			printf("������̶��绰��\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Telephone);
			break;
		}
		case 4:
		{
			printf("�������ƶ��绰��\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_MobilePhone);
			break;
		}
		case 5:
		{
			printf("���������\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Classify);
			break;
		}
		case 6:
		{
			printf("������Email��\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Email);
			break;
		}
		case 7:
		{
			printf("������QQ��\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_QQ);
			break;
		}
		default:
			cout << "������������������!" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}	

//�����ϵ��
void cleanPerson(AddressBooks* abs)
{
	printf("��ȷ���Ƿ���գ�(y/n)\n");
	char select;
	getchar();
	select = getchar();
	if (select == 'y' || select == 'Y')
	{
		abs->m_Size = 0;
		printf("ͨѶ¼����գ�\n");
	}
	system("pause");
	system("cls");
}

void cutStr(char* str)
{
	int i = 0;
	while (str[i] != '\n'){i++; }
	str[i] = '\0';
}

char* strConnect(char* desStr)
{
	int i = 0;
	while(desStr[i]!='\0'){i++;}
	desStr[i] = '\n';
	desStr[i + 1] = '\0';
	return desStr;
}

//���ļ�
int readFile(AddressBooks* abs)
{
	abs->m_Size = 0;
	FILE* fp;
	if ((fopen_s(&fp, "person.txt", "r")) != 0)
	{
		printf("�ļ���ʧ�ܣ�");
		return -1;
	}
	int index = 0;
	while (!feof(fp))
	{
		//if(fgets(strout,80,fp))
		//	puts(strout);
		if (index % 8 == 0)
		{
			fgets(abs->personArray[abs->m_Size].m_Name, CHARLENTH, fp);
			cutStr(abs->personArray[abs->m_Size].m_Name);
		}
		else if (index%8 == 1)
		{
			fgets(abs->personArray[abs->m_Size].m_unit, CHARLENTH, fp);
			cutStr(abs->personArray[abs->m_Size].m_unit);
		}
		else if (index%8 == 2)
		{
			fgets(abs->personArray[abs->m_Size].m_Addr, CHARLENTH, fp);
			cutStr(abs->personArray[abs->m_Size].m_Addr);
		}
		else if (index%8 == 3)
		{
			fgets(abs->personArray[abs->m_Size].m_Telephone, CHARLENTH, fp);
			cutStr(abs->personArray[abs->m_Size].m_Telephone);
		}
		else if (index%8 == 4)
		{
			fgets(abs->personArray[abs->m_Size].m_MobilePhone, CHARLENTH, fp);
			cutStr(abs->personArray[abs->m_Size].m_MobilePhone);
		}
		else if (index%8 == 5)
		{
			fgets(abs->personArray[abs->m_Size].m_Classify, CHARLENTH, fp);
			cutStr(abs->personArray[abs->m_Size].m_Classify);
		}
		else if (index%8 == 6)
		{
			fgets(abs->personArray[abs->m_Size].m_Email, CHARLENTH, fp);
			cutStr(abs->personArray[abs->m_Size].m_Email);
		}
		else if (index%8 == 7)
		{
			fgets(abs->personArray[abs->m_Size].m_QQ, CHARLENTH, fp);
			cutStr(abs->personArray[abs->m_Size].m_QQ);
			abs->m_Size++;
			//printPerson(abs->personArray[abs->m_Size-1]);
			//system("pause");
		}
		index++;
	}
	fclose(fp);
	return 1;
}

//д�ļ�
int writeFile(AddressBooks* abs)
{
	FILE* fp;
	if ((fopen_s(&fp, "person.txt", "w")) != 0)
	{
		printf("�ļ���ʧ�ܣ�");
		return -1;
	}
	for (int i = 0; i < abs->m_Size; i++)
	{
		fputs(strConnect(abs->personArray[i].m_Name), fp);
		fputs(strConnect(abs->personArray[i].m_unit), fp);
		fputs(strConnect(abs->personArray[i].m_Addr), fp);
		fputs(strConnect(abs->personArray[i].m_Telephone), fp);
		fputs(strConnect(abs->personArray[i].m_MobilePhone), fp);
		fputs(strConnect(abs->personArray[i].m_Classify), fp);
		fputs(strConnect(abs->personArray[i].m_Email), fp);
		fputs(strConnect(abs->personArray[i].m_QQ), fp);
	}
	fclose(fp);
	return 1;
}

int main()
{
	int select = 0;

	struct AddressBooks abs;
	readFile(&abs);
	while (1)
	{		
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:		
			deletePerson(&abs);					
			break;
		case 4:		
			findPerson(&abs);					
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
		{
			printf("�Ƿ񱣴棿(y/n)\n");
			char select;
			getchar();
			select = getchar();
			if (select == 'y' || select == 'Y')
				writeFile(&abs);
			printf("��ӭ�´�ʹ�ã�\n");
			system("pause");
			return 0;
			break;
		}
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}