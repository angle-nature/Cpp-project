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

	//��ʾ�˵�
	void Show_Menu();

	//�˳�����
	void exitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** EmpArray;

	//���ְ��
	void Add_Emp();

	//�������ļ�
	void save();

	//�ж��ļ�����
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void show_Employee();

	//ɾ��ְ��
	void del_Emp();

	//�ж�ְ���Ƿ����
	int IsExist(int id);

	//�޸�ְ����Ϣ
	void Mod_Emp();

	//����Ա��
	void Find_Emp();

	//���������
	void Sort_Empty();

	//�������
	void Empty_Emp();

	~WorkerManager();
};
