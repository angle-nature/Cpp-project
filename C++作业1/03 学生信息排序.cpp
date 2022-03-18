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
	bool nSex; //true 代表男生  flase 代表女生
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
	cout << "生日：" << stu.birth.usYear << " " << stu.birth.byMonth << " " << stu.birth.byDay << endl;
	cout << "学号：" << stu.nID << endl;
	string sex;
	if (stu.nSex == 1)
		sex = "男";
	else
		sex = "女";
	cout << "性别：" << sex << endl;
	cout << "分数：" << stu.fMarks << endl;
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
		cout << "序号：" << i + 1 << endl;
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
	cout << "请输入学生个数：" << endl;
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
		cout << "请输入第" << i + 1 << "个学生的信息：" << endl;
		cout << "生日：(按yyyy mm dd的格式输入)" << endl;
		cin >> year >> month >> day;
		stu[i].birth.usYear = year;
		stu[i].birth.byMonth = month;
		stu[i].birth.byDay = day;
		cout << "学号：" << endl;
		cin >> ID;
		stu[i].nID = ID;
		cout << "性别：" << endl;
		cout << "1:男  0：女" << endl;
		cin >> sex;
		stu[i].nSex = sex;
		cout << "分数：" << endl;
		cin >> marks;
		stu[i].fMarks = marks;
	}

	cout << "--------------------------" << endl;

	cout << "按学号排序：" << endl;
	student_sort(stu, n, sortByID);

	cout << "--------------------------" << endl;

	cout << "按分数排序：" << endl;
	student_sort(stu, n, sortByMarks);
}

int main()
{
	//solve();
	readFile();

	system("pause");
	return 0;
}