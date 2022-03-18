#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

class Manager :public Worker
{
public:
	Manager(int Id, string name, int deptid);

	virtual void showInfo();

	virtual string getDepName();
};

