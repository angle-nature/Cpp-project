#include<iostream>
using namespace std;

class Person
{
private:
	static int count;
	char name[10];
	int age;
public:
	Person(char n[], int age)
	{
		for (int i = 0; i < 10; i++)
			this->name[i] = n[i];
		this->age = age;
		count++;
	}
	Person(const Person& p)
	{
		for (int i = 0; i < 10; i++)
			this->name[i] = p.name[i];
		this->age = p.age;
		count++;
	}

	void printInfo()
	{
		cout << "����Ϊ��" << name << endl;
		cout << "����Ϊ��" << this->age << endl;
	}

	static int getNumber()
	{
		return count;
	}
};

int Person::count = 0;

int main()
{
	char name[10] = "����";
	Person p1(name, 19);
	Person p2(p1);
	cout << "p1����Ϣ���£�" << endl;
	p1.printInfo();
	cout << "p2����Ϣ���£�" << endl;
	p2.printInfo();
	cout << "������Ϊ��" << Person::getNumber();
	return 0;
}