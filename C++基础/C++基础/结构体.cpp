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
	//�ṹ������
	struct student stuArray[3] =
	{
		{"����",19,96},
		{"����",20,95},
		{"����",21,70}
	};

	for (int i=0;i<3;i++)
	{
		cout << "������" << stuArray[i].name << " ���䣺" << stuArray[i].age << " ������" << stuArray[i].score << endl;
	}

	//�ṹ��ָ��
	student s = { "����",19,96 };
	student* p = &s;

	//��ָ����ʣ���ʹ�á�->��
	cout << "������" << p->name << " ���䣺" << p->age << " ������" << p->score << endl;
	return 0;
}