#include"employee.h"

Employee::Employee(int id, string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

void Employee::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t\t岗位：普通员工\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDepName()
{
	return "员工";
}