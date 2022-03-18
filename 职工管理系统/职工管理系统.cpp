#include<iostream>
using namespace std;
#include"WorkerManager.h"
#include"Worker.h"
#include"boss.h"
#include"employee.h"
#include"Manager.h"

int main()
{
	//实例化管理者对象
	WorkerManager wm;
	int chioce = 0;
	while (true)
	{
		//调用展示菜单成员函数
		wm.Show_Menu();
		cout << "请输入您的选择：" << endl;
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
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	//test();

	system("pause");

	return 0;
}