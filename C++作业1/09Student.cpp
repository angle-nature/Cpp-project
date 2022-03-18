#include<iostream>
using namespace std;

class Student
{
	friend float avgStudent(Student st1, Student st2);
private:
	string n_id;
	string n_name;
	float ChineseScore;
	float mathScore;
	float EnglishScore;
public:
	Student(string id,string name,float cs,float ms,float es)
	{
		this->n_id = id;
		this->n_name = name;
		this->ChineseScore = cs;
		this->mathScore = ms;
		this->EnglishScore = es;
	}

	float avgScore(){ return (ChineseScore + mathScore + EnglishScore) / 3; }
};

float avgStudent(Student st1, Student st2)
{
	float avg1= (st1.ChineseScore + st1.mathScore + st1.EnglishScore) / 3;
	float avg2= (st2.ChineseScore + st2.mathScore + st2.EnglishScore) / 3;
	return (avg1 + avg2) / 2;
}

int main()
{
	Student st1("001", "����", 92.0, 85.5, 90.0);
	Student st2("002", "����", 80.0, 96.0, 81.0);

	cout << "ѧ��������ƽ���ɼ�Ϊ��" << st1.avgScore() << endl;
	cout << "ѧ�����ĵ�ƽ���ɼ�Ϊ��" << st2.avgScore() << endl;
	cout << "ѧ��������ѧ�����ĵ�ƽ���ɼ�Ϊ��" << avgStudent(st1, st2) << endl;
	return 0;
}