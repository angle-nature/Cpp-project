#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

class Employee:public Worker
{
public:
	Employee(int Id, string name, int deptid);
	
	virtual void showInfo();

	virtual string getDepName();
};
