#include<iostream>
#include<iomanip>
using namespace std;

void printInformation()
{
	string name, productID;
	float price;
	int number;

	cout << "Please input your name:" << endl;
	cin >> name;

	cout << "Please input product ID,price,number:" << endl;
	cin >> productID >> price >> number;

	cout << "============================" << endl;
	cout << "Name:" << name << endl;
	cout << "product ID    Price    Num    Total" << endl;
	cout << dec << fixed << showpoint << setprecision(2);
	cout << setiosflags(ios::right) << setfill('0') << setw(7) << productID<<"       "
		<< setiosflags(ios::left) << setfill(' ') << setw(5) << price<<"  "
		<< setw(3) << number << "    "
		<< setw(7) << setprecision(2) << price * number << endl;
	cout<<"                       Total"
		<< setw(7) << setprecision(2) << price * number << endl;
}

int main()
{
	printInformation();

	system("pause");
	return 0;
}