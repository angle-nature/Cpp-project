#include<iostream>
#include<vector>
#include"SSC.h"
using namespace std;

Course::Course() {}
Course::Course(string name, int fullScore) {
	this->name = name;
	this->fullScore = fullScore;
}

string Course::getName() {
	return this->name;
}

int Course::getFullScore() { return this->fullScore; }

void Course::addStudent(Student stu) {
	students.push_back(stu);
}


Student::Student() {}
Student::Student(string name) {
	this->name = name;
}

string Student::getName() {
	return this->name;
}

vector<Course> Student::getCourses() {
	return courses;
}

void Student::selectCourse(Course course) {
	courses.push_back(course);
	course.addStudent(*this);
}

Score::Score(Student stu, Course course, int score) {
	this->student = stu;
	this->course = course;
	this->score = score;
}

Student Score::getStudent() { return student; }
Course Score::getCourse() { return course; }
int Score::getScore() { return score; }


ostream& operator<<(ostream& os, Score& score) {
	cout << "ѧ������" << score.getStudent().getName() << endl;
	cout << "�γ̣�" << score.getCourse().getName() << endl;
	cout << "�ɼ���" << score.getScore() << endl;
	return os;
}

int main()
{
	Student st1("����");
	Student st2("����");
	Student st3("����");

	Course c1("07020001 UML", 100);
	Course c2("07020002 SoftwareTest", 100);
	Course c3("07030003 Java", 100);
	Course c4("07030004 C++", 100);

	st1.selectCourse(c1);
	st1.selectCourse(c3);
	st2.selectCourse(c1);
	st2.selectCourse(c3);
	st2.selectCourse(c4);
	st3.selectCourse(c3);
	st3.selectCourse(c4);

	Score sc1(st1, c1, 85);
	Score sc2(st1, c3, 92);
	Score sc3(st2, c1, 77);
	Score sc4(st2, c3, 87);
	Score sc5(st2, c4, 92);
	Score sc6(st3, c3, 81);
	Score sc7(st3, c4, 88);

	cout << sc1 << sc2 << sc3 << sc4 << sc5 << sc6 << sc7 << endl;

	return 0;
}