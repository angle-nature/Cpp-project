#include"Manager.h"

Manager::Manager(int id, string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t\t��λ������\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

string Manager::getDepName()
{
	return "����";
}