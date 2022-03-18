#include"Manager.h"

Manager::Manager(int id, string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t\t岗位：经理\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::getDepName()
{
	return "经理";
}