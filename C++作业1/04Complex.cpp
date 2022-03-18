#include<iostream>
using namespace std;

class Complex
{
private:
	int real; //实部
	int imag; //虚部 imaginary part
public:
	Complex(int r = 0, int i = 0):real(r),imag(i){} //有参构造

	void display()
	{
		if (imag >= 0)
			cout << real << "+" << imag << "i" << endl;
		else
			cout << real << "-" << imag << "i" << endl;			
	}

	Complex operator+(Complex& c)
	{
		Complex temp;
		temp.real = this->real + c.real;
		temp.imag = this->imag + c.imag;
		return temp;
	}

	Complex operator-(Complex& c)
	{
		Complex temp;
		temp.real = this->real - c.real;
		temp.imag = this->imag - c.imag;
		return temp;
	}

	Complex operator*(Complex& c)
	{
		Complex temp;
		temp.real = (this->real * c.real) - (this->imag * c.imag);
		temp.imag = (this->real * c.imag) + (this->imag * c.real);
		return temp;
	}
};

int main()
{
	Complex cp1(1, 2), cp2(4, 3), cp3;

	cp3 = cp1 + cp2;
	cp3.display();
	cp3 = cp2 - cp1;
	cp3.display();
	cp3 = cp1 * cp2;
	cp3.display();
	return 0;
}