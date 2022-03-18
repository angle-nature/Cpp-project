#include<iostream>
using namespace std;

//�жϸ����������ڼ�
int Week(int year, int month, int day)
{
	int day_org = ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;

	int day_pass=0;

	int daysOfFebruary = (year % 100 != 0 && year % 4 == 0) ? 29 : 28;

	switch(month)
	{
	case 1:
		day_pass = day;
		break;
	case 2:
		day_pass = day + 31;
		break;
	case 3:			
		day_pass = day + daysOfFebruary+31;
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

//�ж����������Ƿ�Ϸ�
bool IsLegal(int year, int month, int day)
{
	if (year <= 2100 && year >= 1900 && month <= 12 && month >= 1 && day <= 31 && day >= 1)
	{
		switch (month)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			if (day <= 30)
				return true;
			else
				return false;
			break;
		case 2:
		{
			if ((year % 100 != 0 && year % 4 == 0) && day <= 29)
				return true;
			else if (day <= 28)
				return true;
			else
				return false;
			break;
		default:
			return true;
		}
		}
	}
	else
		return false;
}

int main()
{
	cout << "�밴��ʽ yyyy mm dd���������գ���1900<yyyy<2100��" << endl;
	int yyyy, mm, dd;

	cin >> yyyy >> mm >> dd;

	if (IsLegal(yyyy, mm, dd))
	{
		switch (Week(yyyy, mm, dd))
		{
		case 0:
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
		}
	}
	else
	{
		cout << "�Ƿ����������룡" << endl;
		exit(0);
	}

	system("pause");

	return 0;
}