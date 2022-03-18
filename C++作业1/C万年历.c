#include<stdio.h>
#include<stdlib.h>

const int day = 1;
int mm[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };

//�ж��Ƿ�Ϊ���겢Ϊ����������ֵ
void isRun(int year)
{
	int daysOfFebruary = (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0) ? 29 : 28;
	mm[1] = daysOfFebruary;
}

//�жϸ����������ڼ�
int Week(int year, int month, int day)
{
	int day_org = ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;

	int day_pass = day;

	for (int i = 0; i < month - 1; i++)
		day_pass += mm[i];

	return (day_org + day_pass) % 7;
}

//�ж���������Ƿ�Ϸ�
bool IsLegal(int year)
{
	if (year <= 3000 && year >= 1)
		return true;
	else
		return false;
}

//��ӡ����
void showCalendar(int year, int month)
{
	int count = 0;

	char m[12][10] = { "January" ,"February" ,"March" ,"April" ,"May" ,"June" ,
		"July" ,"August" ,"September" ," October" ," November" ,"December" };

	printf("%s\t\t\t\t\t%d\n\n", m[month - 1], year);


	printf("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n\n");
	for (int i = 0; i < Week(year, month, day); i++)
		putchar('\t');

	for (int i = 1; i <= 7 - Week(year, month, day); i++)
		printf("%d\t", i);

	putchar('\n');
	putchar('\n');

	for (int i = 8 - Week(year, month, day); i <= mm[month-1]; i++)
	{
		printf("%d\t", i);

		count++;
		if (count % 7 == 0)
		{
			putchar('\n');
			putchar('\n');
		}
	}
	putchar('\n');
}

int main()
{
	int yyyy;

	while (true) 
	{
		system("cls");
		printf("��������Ҫ��ѯ����ݣ�0<year<=3000��\n");
		scanf_s("%d", &yyyy);
		printf("----------------------------------------------------\n");
		if (IsLegal(yyyy))
		{
			isRun(yyyy); //�ж��Ƿ�Ϊ���겢Ϊ����������ֵ
			for (int i = 1; i <= 12; i++)
			{
				showCalendar(yyyy, i);
				printf("----------------------------------------------------\n");
			}
		}
		else
			printf("�Ƿ����������룡\n");
		system("pause");
	}
	return 0;
}