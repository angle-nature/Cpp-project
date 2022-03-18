#include<iostream>
using namespace std;

class MyClass
{
	static int number;
public:
	MyClass()
	{
		cout << "无参构造函数已调用!" << ++number << endl;
	}

	MyClass(int)
	{
		cout << "有参构造函数已调用!" << ++number << endl;
	}
};

int MyClass::number = 0;

int main()
{
	//int a = 3;
	//int b = 1;
	//double c = 1.0;
	//int* const p1 = &a;
	//const int* p2 = &a;
	//*p1 = b;
	////p1 = &b;
	////*p2 = b;
	//p2 = &a;
	//p2 = &b;

	//int* p3 = &a;
	//int* p4 = &b;
	//double* p5 = &c;
	////p3 + p4;

	//(p3 || p4);
	//p3 || p5;
	//p3&& p5;
	////p5 = p4;
	//p3 = NULL;
	//float(*fp)[25][9] = new float[10][25][9];
	//cout << *p1 << endl;

	//MyClass  obj1(2), objarr[3], * pObj[4];

	int arr[2][3] = { {1,2,3},{4,5,6} };

	cout << *(arr[1] + 2) << endl;

	return 0;
}