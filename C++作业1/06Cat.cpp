#include<iostream>
using namespace std;

class Cat
{
private:
	static int count;
public:
	Cat(){ count++; }

	static int getTotalNumber()
	{
		return count;
	}
};

int Cat::count = 0;

int main()
{
	Cat cat[12];

	cout << "Cat��Ŀǰ��" << cat[0].getTotalNumber() << "������" << endl;

	return 0;
}