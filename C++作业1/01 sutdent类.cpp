#include<iostream>
using namespace std;

class Date
{
	friend class Student;

public:
	Date()
	{
		this->m_year = 2020;
		this->m_month = 10;
		this->m_day = 19;
	}

	Date(unsigned short year,unsigned short month,unsigned short day)
	{
		this->m_year = year;
		this->m_month = month;
		this->m_day = day;
	}

private:
	unsigned short m_year;
	unsigned short m_month;
	unsigned short m_day;
};

class Student
{
public:
	Student(string name,string sex,Date date,string ID)
	{
		this->m_name = name;
		this->m_sex = sex;
		this->m_date = date;
		this->m_ID = ID;
	}

	void showStudent()
	{
		cout << "ѧ��������" << this->m_name << endl;
		cout << "ѧ���Ա�" << this->m_sex << endl;
		cout << "ѧ�����գ�" << m_date.m_year<<"."<<m_date.m_month<<"."<<m_date.m_day << endl;
		cout << "ѧ��ѧ�ţ�" << this->m_ID << endl;
	}

private:
	string m_name;
	string m_sex;
	Date m_date;
	string m_ID;
};

int main()
{
	Date d(2000, 3, 17);
	Student s("����","��",d,"001");

	s.showStudent();

	return 0;
}