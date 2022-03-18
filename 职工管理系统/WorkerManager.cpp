#include"WorkerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1���ļ�������
	if (!ifs.is_open())
	{
		//��ʼ������
		this->m_EmpNum = 0;
		this->EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2���ļ����е�Ϊ��
	char c;
	ifs >> c;
	if (ifs.eof())
	{
		//��ʼ������
		this->m_EmpNum = 0;
		this->EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	}

	//3���ļ���������
	this->m_EmpNum = this->get_EmpNum();
	
	//���ٿռ�
	this->EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();
}

void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "********** ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�Ƴ��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ������" << endl;

	int addNum = 0; //�����û���������
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum; //�¿ռ��С=ԭ����¼����+��������
		
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ��µ����ݿ������¿ռ���
		if (this->EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
				newSpace[i] = this->EmpArray[i];
		}

		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id; //ְ�����
			string name; //ְ������
			int dSelect; //����ѡ��

			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			while (IsExist(id)!=-1)
			{
				cout << "����ظ�������������" << endl;
				cin >> id;
			}

			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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

			//��������ְ��ְ�𣬱�����������
			newSpace[this->m_EmpNum+i] = worker;

			//�ͷ�ԭ���ռ�
			delete[] this->EmpArray;

			//�����¿ռ��ָ��
			this->EmpArray = newSpace;

			//�����µ�ְ������
			this->m_EmpNum = newSize;

			this->m_FileIsEmpty = false;

			//��ʾ��ӳɹ�
			cout << "��ӳɹ���" << endl;

			//�������ļ���
			this->save();
		}
	}
	else
	{
		cout << "������������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0); //�˳�����
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

//��ʼ��Ա��
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

//��ʾְ��
void WorkerManager::show_Employee()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ó��򴰿�
			this->EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����
int WorkerManager::IsExist(int id)
{
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->EmpArray[i]->m_Id == id)
			return i;
	}
	return -1;
}

//ɾ��ְ��
void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		int id;
		cout << "��������Ҫɾ��Ա���ı�ţ�" << endl;
		cin >> id;

		if (IsExist(id) == -1)
		{
			cout << "��Ա��������" << endl;
		}

		else
		{
			int flag = IsExist(id);
			for (int i = flag; i < this->m_EmpNum - 1; i++)
			{
				this->EmpArray[i] = this->EmpArray[i + 1];
			}

			this->m_EmpNum--;

			//ͬ�������ļ�
			this->save();

			cout << "��Ա��ɾ���ɹ���" << endl;
		}

		//������ݱ�ɾ�꣬��m_FileIsEmpty������Ϊtrue
		if (this->m_EmpNum == 0)
		{
			this->m_FileIsEmpty = true;
		}

	}	
	system("pause");
	system("cls");
}

//�޸�ְ����Ϣ
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		int id;
		cout << "��������Ҫ�޸�Ա���ı�ţ�" << endl;
		cin >> id;

		if (IsExist(id) == -1)
		{
			cout << "��Ա��������" << endl;
		}

		else
		{
			cout << "��ѡ���Ա���Ķ���ĸ�λ��" << endl;
			cout << "1����ͨԱ��" << endl
				<< "2������" << endl
				<< "3���ϰ�" << endl;
			int select;
			cin >> select;

			this->EmpArray[IsExist(id)]->m_DeptId = select;

			this->save();

			cout << "�޸ĳɹ���" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

//����Ա��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������Ҫ����Ա���ı��" << endl;
		int id;
		cin >> id;
		if (this->IsExist(id) == -1)
		{
			cout << "���޴��ˣ�" << endl;
		}
		else
		{
			this->EmpArray[IsExist(id)]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//���������(ð������)
void WorkerManager::Sort_Empty()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��ѡ�����з�ʽ��" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			//����
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
			//����
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
			cout << "��������" << endl;
			break;
		}

		//ͬ�����µ��ļ�
		this->save();

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ó��򴰿�
			this->EmpArray[i]->showInfo();
		}
	}
	
	system("pause");
	system("cls");
}

//�������
void WorkerManager::Empty_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "���ٴ�ȷ���Ƿ�Ҫ������ݣ�" << endl;
		cout << "1����" << endl;
		cout << "2����" << endl;
		int select;
		cin >> select;
		if (select == 2)
		{
			cout << "����ȡ������" << endl;
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

			cout << "�ɹ��������" << endl;
		}
	}
	system("pause");
	system("cls");
	
}

//����������������ڴ�
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