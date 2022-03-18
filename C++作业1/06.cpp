#include<iostream>
using namespace std;

const int day = 1;

//判断该日期是星期几
int Week(int year, int month, int day)
{
	int day_org = ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;

	int day_pass = 0;

	int daysOfFebruary = (year % 100 != 0 && year % 4 == 0) ? 29 : 28;

	switch (month)
	{
	case 1:
		day_pass = day;
		break;
	case 2:
		day_pass = day + 31;
		break;
	case 3:
		day_pass = day + daysOfFebruary + 31;
		break;
	case 4:
		day_pass = day + 31 + daysOfFebruary + 31l;
		break;
	case 5:
		day_pass = day + 31 + daysOfFebruary + 31 + 30;
		break;
	case 6:
		day_pass = day + 31 + daysOfFebruary + 31 + 30 + 31;
		break;
	case 7:
		day_pass = day + 31 + daysOfFebruary + 31 + 30 + 31 + 30;
		break;
	case 8:
		day_pass = day + 31 + daysOfFebruary + 31 + 30 + 31 + 30 + 31;
		break;
	case 9:
		day_pass = day + 31 + daysOfFebruary + 31 + 30 + 31 + 30 + 31 + 31;
		break;
	case 10:
		day_pass = day + 31 + daysOfFebruary + 31 + 30 + 31 + 30 + 31 + 31 + 30;
		break;
	case 11:
		day_pass = day + 31 + daysOfFebruary + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
		break;
	case 12:
		day_pass = day + 31 + daysOfFebruary + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
		break;
	}

	return (day_org + day_pass) % 7;
}

//判断输入日期是否合法
bool IsLegal(int year, int month)
{
	if (year <= 2100 && year >= 1900 && month <= 12 && month >= 1)
		return true;
	else
		return false;
}

//打印日历
void showCalendar(int year, int month)
{
	int days;
	int count = 0;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		days = 31;
	else if ((year % 100 != 0 && year % 4 == 0) && month == 2)
		days = 29;
	else if (month == 2)
		days = 28;
	else
		days = 30;

	string m[12] = { "January" ,"February" ,"March" ,"April" ,"May" ,"June" ,
		"July" ,"August" ,"September" ," October" ," November" ,"December" };

	cout << m[month - 1] << "\t\t\t\t\t" << year << endl << endl;

	cout << "SUN" << "\t" << "MON" << "\t" << "TUE" << "\t" << "WED" << "\t" << "THU" << "\t" << "FRI" << "\t" << "SAT" << "\n\n";

	for (int i = 0; i < Week(year, month, day); i++)
		cout << "\t";

	for (int i = 1; i <= 7-Week(year,month,day); i++)
		cout << i << "\t";

	cout << endl << endl;

	for (int i = 8- Week(year, month, day); i <= days; i++)
	{
		cout << i << "\t";

		count++;
		if (count % 7 == 0)
			cout << endl << endl;
	}
	cout << endl << endl;
}

int main()
{
	cout << "请按格式 yyyy mm 输入年月：（1900<yyyy<2100）" << endl;
	int yyyy, mm;

	cin >> yyyy >> mm ;

	if (IsLegal(yyyy, mm))
		showCalendar(yyyy, mm);
	else
		cout << "非法的日期输入！" << endl;

	system("pause");
	return 0;
}