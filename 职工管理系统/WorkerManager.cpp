#include"WorkerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1、文件不存在
	if (!ifs.is_open())
	{
		//初始化属性
		this->m_EmpNum = 0;
		this->EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2、文件已有但为空
	char c;
	ifs >> c;
	if (ifs.eof())
	{
		//初始化属性
		this->m_EmpNum = 0;
		this->EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	}

	//3、文件已有数据
	this->m_EmpNum = this->get_EmpNum();
	
	//开辟空间
	this->EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->init_Emp();
}

void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "********** 欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.推出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量" << endl;

	int addNum = 0; //保存用户输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum; //新空间大小=原来记录人数+新增人数
		
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间下的数据拷贝到新空间中
		if (this->EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
				newSpace[i] = this->EmpArray[i];
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id; //职工编号
			string name; //职工姓名
			int dSelect; //部门选择

			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			while (IsExist(id)!=-1)
			{
				cout << "编号重复，请重新输入" << endl;
				cin >> id;
			}

			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;

			cout << "请选择该职工岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
			default:
				break;
			}

			//将创建的职工职责，保存在数组中
			newSpace[this->m_EmpNum+i] = worker;

			//释放原来空间
			delete[] this->EmpArray;

			//更新新空间的指向
			this->EmpArray = newSpace;

			//更新新的职工人数
			this->m_EmpNum = newSize;

			this->m_FileIsEmpty = false;

			//提示添加成功
			cout << "添加成功！" << endl;

			//保存在文件中
			this->save();
		}
	}
	else
	{
		cout << "输入数据有误！" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0); //退出程序
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->EmpArray[i]->m_Id << " "
			<< this->EmpArray[i]->m_Name << " "
			<< this->EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	int num = 0;

	while(ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;

		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else if(did==3)
		{
			worker = new Boss(id, name, did);
		}
		this->EmpArray[index++] = worker;
	}
	ifs.close();
}

//显示职工
void WorkerManager::show_Employee()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用程序窗口
			this->EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在
int WorkerManager::IsExist(int id)
{
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->EmpArray[i]->m_Id == id)
			return i;
	}
	return -1;
}

//删除职工
void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int id;
		cout << "请输入需要删除员工的编号：" << endl;
		cin >> id;

		if (IsExist(id) == -1)
		{
			cout << "该员工不存在" << endl;
		}

		else
		{
			int flag = IsExist(id);
			for (int i = flag; i < this->m_EmpNum - 1; i++)
			{
				this->EmpArray[i] = this->EmpArray[i + 1];
			}

			this->m_EmpNum--;

			//同步更新文件
			this->save();

			cout << "该员工删除成功！" << endl;
		}

		//如果数据被删完，将m_FileIsEmpty重新置为true
		if (this->m_EmpNum == 0)
		{
			this->m_FileIsEmpty = true;
		}

	}	
	system("pause");
	system("cls");
}

//修改职工信息
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int id;
		cout << "请输入需要修改员工的编号：" << endl;
		cin >> id;

		if (IsExist(id) == -1)
		{
			cout << "该员工不存在" << endl;
		}

		else
		{
			cout << "请选择该员工改动后的岗位：" << endl;
			cout << "1、普通员工" << endl
				<< "2、经理" << endl
				<< "3、老板" << endl;
			int select;
			cin >> select;

			this->EmpArray[IsExist(id)]->m_DeptId = select;

			this->save();

			cout << "修改成功！" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

//查找员工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入需要查找员工的编号" << endl;
		int id;
		cin >> id;
		if (this->IsExist(id) == -1)
		{
			cout << "查无此人！" << endl;
		}
		else
		{
			this->EmpArray[IsExist(id)]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//按编号排序(冒泡排序)
void WorkerManager::Sort_Empty()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请选择排列方式：" << endl;
		cout << "1、升序" << endl;
		cout << "2、降序" << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			//升序
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				for (int j = 0; j < this->m_EmpNum - i - 1; j++)
				{
					if (this->EmpArray[j]->m_Id > this->EmpArray[j + 1]->m_Id)
					{
						Worker* temp = this->EmpArray[j];
						EmpArray[j] = EmpArray[j + 1];
						EmpArray[j + 1] = temp;
					}
				}
			}
			break;
		case 2:
			//降序
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				for (int j = 0; j < this->m_EmpNum - i - 1; j++)
				{
					if (this->EmpArray[j]->m_Id < this->EmpArray[j + 1]->m_Id)
					{
						Worker* temp = this->EmpArray[j];
						EmpArray[j] = EmpArray[j + 1];
						EmpArray[j + 1] = temp;
					}
				}
			}
			break;
		default:
			cout << "输入有误！" << endl;
			break;
		}

		//同步更新到文件
		this->save();

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用程序窗口
			this->EmpArray[i]->showInfo();
		}
	}
	
	system("pause");
	system("cls");
}

//清空数据
void WorkerManager::Empty_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请再次确认是否要清空数据！" << endl;
		cout << "1、是" << endl;
		cout << "2、否" << endl;
		int select;
		cin >> select;
		if (select == 2)
		{
			cout << "你已取消操作" << endl;
		}
		else
		{
			if (this->EmpArray != NULL)
			{
				for (int i = 0; i < m_EmpNum; i++)
				{
					if (this->EmpArray[i] != NULL)
					{
						delete EmpArray[i];
						EmpArray[i] = NULL;
					}
				}
				delete[] this->EmpArray;
				this->EmpArray = NULL;
			}
			this->m_EmpNum = 0;

			this->save();

			this->m_FileIsEmpty = true;

			cout << "成功清空数据" << endl;
		}
	}
	system("pause");
	system("cls");
	
}

//利用析构函数清空内存
WorkerManager::~WorkerManager()
{
	if (this->EmpArray != NULL)
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (this->EmpArray[i] != NULL)
			{
				delete EmpArray[i];
				EmpArray[i] = NULL;
			}
		}
		delete[] this->EmpArray;
		this->EmpArray = NULL;
	}
}