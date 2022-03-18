#include<iostream>
using namespace std;

const int day = 1;

//判断该日期是星期几
int Week(int year, int month, int day)
{
	int day_org = ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;

	int day_pass = day;

	int daysOfFebruary = (year % 100 != 0 && year % 4 == 0) ? 29 : 28;

	int m[12] = { 31,daysOfFebruary,31,30,31,30,31,31,30,31,30,31 };
	
	for (int i = 0; i < month - 1; i++) 
		day_pass += m[i];

	return (day_org + day_pass) % 7;
}

//判断输入日期是否合法
bool IsLegal(int year, int month)
{
	if (year <= 3000 && year >= 1 && month <= 12 && month >= 1)
		return true;
	else
		return false;
}

//打印月历
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

	for (int i = 1; i <= 7 - Week(year, month, day); i++)
		cout << i << "\t";

	cout << endl << endl;

	for (int i = 8 - Week(year, month, day); i <= days; i++)
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
	cout << "请按格式 yyyy 输入年份：（0<yyyy<=3000）" << endl;
	int yyyy;

	cin >> yyyy;
	cout << "----------------------------------------------------\n";
	for (int mm = 1; mm <= 12; mm++)
		if (IsLegal(yyyy, mm))
		{
			showCalendar(yyyy, mm);
			cout << "----------------------------------------------------\n";
		}
		else
			cout << "非法的日期输入！" << endl;

	system("pause");
	return 0;
}