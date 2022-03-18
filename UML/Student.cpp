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
	Course() {}
	Course(string name, int fullScore) {
		this->name = name;
		this->fullScore = fullScore;
	}

	string getName() {
		return this->name;
	}

	int getFullScore() { return this->fullScore; }

	void addStudent(Student stu) {
		students.push_back(stu);
	}
};

class Student {
private:
	string name;
	vector<Course> courses;
public:
	Student(){}
	Student(string name) {
		this->name = name;
	}

	string getName() {
		return this->name;
	}

	vector<Course> getCourses() {
		return courses;
	}

	void selectCourse(Course course) {
		courses.push_back(course);
		course.addStudent(*this);
	}
};

class Score {
private:
	Student student;
	Course course;
	int score;
public:
	Score(Student stu,Course course,int score) {
		this->student = stu;
		this->course = course;
		this->score = score;
	}

	Student getStudent() { return student; }
	Course getCourse() { return course; }
	int getScore() { return score; }
};

ostream& operator<<(ostream& os, Score& score) {
	cout << "学生名：" << score.getStudent().getName() << endl;
	cout << "课程：" << score.getCourse().getName() << endl;
	cout << "成绩：" << score.getScore() << endl;
	return os;
}

//int main()
//{
//	Student st1("张三");
//	Student st2("李四");
//	Student st3("王五");
//
//	Course c1("07020001 UML",100);
//	Course c2("07020002 SoftwareTest",100);
//	Course c3("07030003 Java",100);
//	Course c4("07030004 C++",100);
//
//	st1.selectCourse(c1);
//	st1.selectCourse(c3);
//	st2.selectCourse(c1);
//	st2.selectCourse(c3);
//	st2.selectCourse(c4);
//	st3.selectCourse(c3);
//	st3.selectCourse(c4);
//
//	Score sc1(st1, c1, 85);
//	Score sc2(st1, c3, 92);
//	Score sc3(st2, c1, 77);
//	Score sc4(st2, c3, 87);
//	Score sc5(st2, c4, 92);
//	Score sc6(st3, c3, 81);
//	Score sc7(st3, c4, 88);
//
//	cout << sc1 << sc2 << sc3 << sc4 << sc5 << sc6 << sc7 << endl;
//
//	return 0;
//}