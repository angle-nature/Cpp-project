#include<iostream>
using namespace std;
#include"WorkerManager.h"
#include"Worker.h"
#include"boss.h"
#include"employee.h"
#include"Manager.h"

int main()
{
	//ʵ���������߶���
	WorkerManager wm;
	int chioce = 0;
	while (true)
	{
		//����չʾ�˵���Ա����
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> chioce;

		switch (chioce)
		{
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.show_Employee();
			break;
		case 3:
			wm.del_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Sort_Empty();
			break;
		case 7:
			wm.Empty_Emp();
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	//test();

	system("pause");

	return 0;
}