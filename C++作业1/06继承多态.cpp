#include<iostream>
using namespace std;

class A
{
protected:
	int a, b;
public:
	A(int a, int b) :a(a), b(b) {}

	int geta() { return a; }
	int getb() { return b; }
};

class B:public A
{
public:
	B(int a, int b):A(a,b)
	{
		this->a = a;
		this->b = b;
	}
	int geta() { return 2 * a; }
};

int main()
{
	B b(1, 1);
	cout << b.geta() << endl;
	return 0;
}