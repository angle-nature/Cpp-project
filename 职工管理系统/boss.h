#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

class Boss :public Worker
{
public:
	Boss(int Id, string name, int deptid);

	virtual void showInfo();

	virtual string getDepName();
};

