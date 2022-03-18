#include<iostream>
#include<ctime>
using namespace std;

//����ѧ���ṹ��
struct student
{
	string Sname;
	int score;
};

//������ʦ�ṹ��
struct teacher
{
	string Tname;
	struct student sArray[5];
};

//����ʦ��ѧ����Ϣ��ֵ
void allocateSpace(struct teacher tArray[], int len)
{
	string nameSeed = "ABCDE";   //��������
	for (int i = 0; i < 3; i ++ )
	{
		tArray[i].Tname = "teacher_" ;
		tArray[i].Tname+= nameSeed[i];  //����ֱ�Ӽ����Ͼ�
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].Sname= "student_" ;
			tArray[i].sArray[j].Sname += nameSeed[j];

			int random = rand() % 61 + 40;  //�����������  40~100
			tArray[i].sArray[j].score = random;
		}
	}
}

//��ӡ��ʦ��ѧ����Ϣ
void printfInfo(struct teacher *tArray, int len)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "��ʦ������" << tArray[i].Tname << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\tѧ��������" << tArray[i].sArray[j].Sname << " ѧ��������" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));  //�����������

	struct teacher tArray[3];
	int len = sizeof(tArray) / sizeof(tArray[0]);

	allocateSpace(tArray, len);
	printfInfo(tArray, len);

	return 0;
}