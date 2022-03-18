#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
#include"employee.h"
#include"Manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:

	WorkerManager();

	//显示菜单
	void Show_Menu();

	//退出程序
	void exitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** EmpArray;

	//添加职工
	void Add_Emp();

	//保存至文件
	void save();

	//判断文件存在
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void show_Employee();

	//删除职工
	void del_Emp();

	//判断职工是否存在
	int IsExist(int id);

	//修改职工信息
	void Mod_Emp();

	//查找员工
	void Find_Emp();

	//按编号排序
	void Sort_Empty();

	//清空数据
	void Empty_Emp();

	~WorkerManager();
};
