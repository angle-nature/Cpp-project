#include<iostream>
#include<ctime>
using namespace std;

//定义学生结构体
struct student
{
	string Sname;
	int score;
};

//定义老师结构体
struct teacher
{
	string Tname;
	struct student sArray[5];
};

//给老师、学生信息赋值
void allocateSpace(struct teacher tArray[], int len)
{
	string nameSeed = "ABCDE";   //名字序列
	for (int i = 0; i < 3; i ++ )
	{
		tArray[i].Tname = "teacher_" ;
		tArray[i].Tname+= nameSeed[i];  //不可直接加在上句
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].Sname= "student_" ;
			tArray[i].sArray[j].Sname += nameSeed[j];

			int random = rand() % 61 + 40;  //生成随机分数  40~100
			tArray[i].sArray[j].score = random;
		}
	}
}

//打印老师、学生信息
void printfInfo(struct teacher *tArray, int len)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "老师姓名：" << tArray[i].Tname << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名：" << tArray[i].sArray[j].Sname << " 学生分数：" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));  //生成随机种子

	struct teacher tArray[3];
	int len = sizeof(tArray) / sizeof(tArray[0]);

	allocateSpace(tArray, len);
	printfInfo(tArray, len);

	return 0;
}