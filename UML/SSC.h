#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Student;

class Course {
private:
	string name;
	int fullScore;
	vector<Student> students;
public:
	Course();
	Course(string name, int fullScore);
	string getName();
	int getFullScore();
	void addStudent(Student stu);
};

class Student {
private:
	string name;
	vector<Course> courses;
public:
	Student();
	Student(string name);
	string getName();
	vector<Course> getCourses();
	void selectCourse(Course course);
};

class Score {
private:
	Student student;
	Course course;
	int score;
public:
	Score(Student stu, Course course, int score);
	Student getStudent();
	Course getCourse();
	int getScore();
};

ostream& operator<<(ostream& os, Score& score);