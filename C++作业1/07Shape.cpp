#include<iostream>
using namespace std;

class Shape
{
public:
	virtual double getArea() = 0; //计算面积
	virtual double getPerim() = 0; //计算周长
};

class Rectangle :public Shape
{
private:
	double a, b;//长，宽
public:
	Rectangle(double a,double b):a(a),b(b){}

	double getArea(){ return a * b; }
	double getPerim() { return 2 * (a + b); }
};

class Circle :public Shape
{
private:
	const double PI = 3.14; //圆周率
	double r;//半径
public:
	Circle(double r) :r(r) {}
	double getArea() { return PI * r * r; }
	double getPerim() { return 2 * PI * r; }
};


int main()
{
	Rectangle rec(2, 4);
	Circle c(2);
	cout << "长方形的面积为：" << rec.getArea() << endl;
	cout << "长方形的周长为：" << rec.getPerim() << endl;
	cout << "圆的面积为：" << c.getArea() << endl;
	cout << "圆的周长为：" << c.getPerim() << endl;
	return 0;
}