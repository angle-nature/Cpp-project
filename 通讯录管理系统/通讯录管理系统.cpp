#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MAX 1000
#define CHARLENTH 50

//菜单展示
void showMenu()
{
	printf("***************************\n");
	printf("*****  1、添加联系人  *****\n");
	printf("*****  2、显示联系人  *****\n");
	printf("*****  3、删除联系人  *****\n");
	printf("*****  4、查找联系人  *****\n");
	printf("*****  5、修改联系人  *****\n");
	printf("*****  6、清空联系人  *****\n");
	printf("*****  0、退出通讯录  *****\n");
	printf("***************************\n");
}

//建立联系人结构体
struct Person
{
	char m_Name[CHARLENTH];  //姓名
	char m_unit[CHARLENTH];  //单元
	char m_Addr[CHARLENTH];  //住址
	char m_Telephone[CHARLENTH];  //固定电话
	char m_MobilePhone[CHARLENTH];  //移动电话
	char m_Classify[CHARLENTH];  //分类
	char m_Email[CHARLENTH];  //邮箱
	char m_QQ[CHARLENTH];  //QQ
};

//建立通讯录结构体
struct AddressBooks
{
	struct Person personArray[MAX];
	int m_Size;
};

//打印联系人
void printPerson(Person person)
{
	printf("姓名：%s\t", person.m_Name);
	printf("单元：%s\t", person.m_unit);
	printf("住址：%s\t", person.m_Addr);
	printf("固定电话：%s\t", person.m_Telephone);
	printf("移动电话：%s\t", person.m_MobilePhone);
	printf("分类：%s\t", person.m_Classify);
	printf("Emali：%s\t", person.m_Email);
	printf("QQ：%s\n", person.m_QQ);
}

//添加联系人
void addPerson(struct AddressBooks* abs)
{

	if (abs->m_Size == MAX)
		printf("联系人已满，无法再添加！\n");
	
	else
	{
		printf("请输入姓名：\n");
		getchar();
		gets_s(abs->personArray[abs->m_Size].m_Name);
		
		printf("请输入单元：\n");
		gets_s(abs->personArray[abs->m_Size].m_unit);

		printf("请输入住址：\n");
		gets_s(abs->personArray[abs->m_Size].m_Addr);

		printf("请输入固定电话：\n");
		gets_s(abs->personArray[abs->m_Size].m_Telephone);

		printf("请输入移动电话：\n");
		gets_s(abs->personArray[abs->m_Size].m_MobilePhone);

		printf("请输入类别：\n");
		gets_s(abs->personArray[abs->m_Size].m_Classify);

		printf("请输入邮箱：\n");
		gets_s(abs->personArray[abs->m_Size].m_Email);

		printf("请输入QQ：\n");
		gets_s(abs->personArray[abs->m_Size].m_QQ);

		abs->m_Size++;

		printf("添加成功\n");
		system("pause");  //按任意键继续
		system("cls");    //清屏
	}
}

//显示联系人
void showPerson(struct AddressBooks* abs)
{
	if (abs->m_Size == 0)
		printf("当前通讯录没有联系人\n");
	
	else
	{
		printf("所有联系人如下：\n");
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

//删除联系人
void deletePerson(struct AddressBooks* abs)
{
	printf("请输入删除联系人姓名：\n");
	char name[20];
	getchar();
	gets_s(name);
	int sum = 0;
	int record[MAX];  //记录下标
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
		printf("删除成功！\n");
		cout << "删除成功！" << endl;
		system("pause");
		system("cls");
	}
	else if (sum > 1)
	{
		printf("有重名的联系人，请选择所要删除的联系人序号：\n");
		for (int i = 0; i < sum; i++)
		{
			printf("%d：\t", i + 1);
			printPerson(abs->personArray[record[i]]);
		}
		int order;
		scanf_s("%d", &order);
		for (int i = record[order - 1]; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		printf("删除成功!\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("此联系人不存在！\n");
		system("pause");
		system("cls");
	}
}

//查找联系人
void findPerson(AddressBooks* abs)
{
	printf("请输入要查找联系人姓名：\n");
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
		printf("此联系人不存在！\n");
	}
	else
	{
		printf("该联系人信息如下：\n");
		for (int i = 0; i < sum; i++)
		{
			printPerson(abs->personArray[record[i]]);
		}
	}

	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(AddressBooks* abs)
{
	printf("请输入要查找联系人姓名：\n");
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
		printf("此联系人不存在！\n");
	}
	else if (sum == 1)
	{
		printf("该联系人的信息如下：\n");
		printf("==============================\n");
		printPerson(abs->personArray[record[sum-1]]);
		printf("==============================\n");

		int select;
		printf("请选择需要修改的信息：\n1、单元\n2、住址\n3、固定电话\n4、移动电话\n5、分类\n6、Email\n7、QQ\n");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
		{
			printf("请输入单元：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_unit);
			break;
		}
		case 2:
		{
			printf("请输入住址：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Addr);
			break;
		}
		case 3:
		{
			printf("请输入固定电话：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Telephone);
			break;
		}
		case 4:
		{
			printf("请输入移动电话：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_MobilePhone);
			break;
		}
		case 5:
		{
			printf("请输入类别：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Classify);
			break;
		}
		case 6:
		{
			printf("请输入Email：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Email);
			break;
		}
		case 7:
		{
			printf("请输入QQ：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_QQ);
			break;
		}
		default:
			cout << "输入有误，请重新输入!" << endl;
			break;
		}
	}
	else
	{
		cout << "有重名的联系人，请选择修改" << endl;
		for (int i = 0; i < sum; i++)
		{
			printf("%d：\t", i + 1);
			printPerson(abs->personArray[record[i]]);
		}
		int order;
		scanf_s("%d", &order);
		int select;
		printf("请选择需要修改的信息：\n1、单元\n2、住址\n3、固定电话\n4、移动电话\n5、分类\n6、Email\n7、QQ\n");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
		{
			printf("请输入单元：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_unit);
			break;
		}
		case 2:
		{
			printf("请输入住址：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Addr);
			break;
		}
		case 3:
		{
			printf("请输入固定电话：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Telephone);
			break;
		}
		case 4:
		{
			printf("请输入移动电话：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_MobilePhone);
			break;
		}
		case 5:
		{
			printf("请输入类别：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Classify);
			break;
		}
		case 6:
		{
			printf("请输入Email：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_Email);
			break;
		}
		case 7:
		{
			printf("请输入QQ：\n");
			getchar();
			gets_s(abs->personArray[record[sum - 1]].m_QQ);
			break;
		}
		default:
			cout << "输入有误，请重新输入!" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}	

//清空联系人
void cleanPerson(AddressBooks* abs)
{
	printf("请确认是否清空？(y/n)\n");
	char select;
	getchar();
	select = getchar();
	if (select == 'y' || select == 'Y')
	{
		abs->m_Size = 0;
		printf("通讯录已清空！\n");
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

//读文件
int readFile(AddressBooks* abs)
{
	abs->m_Size = 0;
	FILE* fp;
	if ((fopen_s(&fp, "person.txt", "r")) != 0)
	{
		printf("文件打开失败！");
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

//写文件
int writeFile(AddressBooks* abs)
{
	FILE* fp;
	if ((fopen_s(&fp, "person.txt", "w")) != 0)
	{
		printf("文件打开失败！");
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
			printf("是否保存？(y/n)\n");
			char select;
			getchar();
			select = getchar();
			if (select == 'y' || select == 'Y')
				writeFile(&abs);
			printf("欢迎下次使用！\n");
			system("pause");
			return 0;
			break;
		}
		default:
			cout << "输入有误！请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}