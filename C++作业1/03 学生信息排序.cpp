#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
using namespace std;

typedef struct date
{
	unsigned short usYear;
	unsigned short byMonth;
	unsigned short byDay;
} Date;

typedef struct student
{
	Date birth;
	unsigned int nID;
	bool nSex; //true ��������  flase ����Ů��
	float fMarks;
} STUDENT;

int sortByID(STUDENT& A, STUDENT& B)
{
	if (A.nID > B.nID)
		return 1;
	else if (A.nID == B.nID)
		return 0;
	else
		return -1;
}

int sortByMarks(STUDENT& A, STUDENT& B)
{
	if (A.fMarks > B.fMarks)
		return 1;
	else if (A.fMarks == B.fMarks)
		return 0;
	else
		return -1;
}

void printStu(STUDENT& stu)
{
	cout << "���գ�" << stu.birth.usYear << " " << stu.birth.byMonth << " " << stu.birth.byDay << endl;
	cout << "ѧ�ţ�" << stu.nID << endl;
	string sex;
	if (stu.nSex == 1)
		sex = "��";
	else
		sex = "Ů";
	cout << "�Ա�" << sex << endl;
	cout << "������" << stu.fMarks << endl;
}

void student_sort(STUDENT* pStu, int n, int (*pFunc)(STUDENT&, STUDENT&))
{
	for (int i = 0; i < n; i++)
	{
		student min = pStu[i];
		for (int j = i; j < n; j++)
		{
			if (pFunc(pStu[i], pStu[j]) == 1)
			{
				student temp = pStu[i];
				pStu[i] = pStu[j];
				pStu[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << "��ţ�" << i + 1 << endl;
		printStu(pStu[i]);
	}
}

void readFile()
{
	ifstream ifs;
	ifs.open("student.txt", ios::in);

	
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}
}

void solve()
{
	int n;
	cout << "������ѧ��������" << endl;
	cin >> n;

	student* stu = new student[n];

	unsigned short year;
	unsigned short month;
	unsigned short day;
	unsigned int ID;
	bool sex;
	float marks;

	for (int i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "��ѧ������Ϣ��" << endl;
		cout << "���գ�(��yyyy mm dd�ĸ�ʽ����)" << endl;
		cin >> year >> month >> day;
		stu[i].birth.usYear = year;
		stu[i].birth.byMonth = month;
		stu[i].birth.byDay = day;
		cout << "ѧ�ţ�" << endl;
		cin >> ID;
		stu[i].nID = ID;
		cout << "�Ա�" << endl;
		cout << "1:��  0��Ů" << endl;
		cin >> sex;
		stu[i].nSex = sex;
		cout << "������" << endl;
		cin >> marks;
		stu[i].fMarks = marks;
	}

	cout << "--------------------------" << endl;

	cout << "��ѧ������" << endl;
	student_sort(stu, n, sortByID);

	cout << "--------------------------" << endl;

	cout << "����������" << endl;
	student_sort(stu, n, sortByMarks);
}

int main()
{
	//solve();
	readFile();

	system("pause");
	return 0;
}