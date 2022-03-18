#include<iostream>
using namespace std;

struct student
{
	string name;
	int age;
	int score;
};
int main()
{
	//结构体数组
	struct student stuArray[3] =
	{
		{"张三",19,96},
		{"李四",20,95},
		{"王五",21,70}
	};

	for (int i=0;i<3;i++)
	{
		cout << "姓名：" << stuArray[i].name << " 年龄：" << stuArray[i].age << " 分数：" << stuArray[i].score << endl;
	}

	//结构体指针
	student s = { "张三",19,96 };
	student* p = &s;

	//用指针访问，需使用“->”
	cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;
	return 0;
}