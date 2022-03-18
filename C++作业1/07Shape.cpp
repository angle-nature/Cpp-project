#include<iostream>
using namespace std;

class Shape
{
public:
	virtual double getArea() = 0; //�������
	virtual double getPerim() = 0; //�����ܳ�
};

class Rectangle :public Shape
{
private:
	double a, b;//������
public:
	Rectangle(double a,double b):a(a),b(b){}

	double getArea(){ return a * b; }
	double getPerim() { return 2 * (a + b); }
};

class Circle :public Shape
{
private:
	const double PI = 3.14; //Բ����
	double r;//�뾶
public:
	Circle(double r) :r(r) {}
	double getArea() { return PI * r * r; }
	double getPerim() { return 2 * PI * r; }
};


int main()
{
	Rectangle rec(2, 4);
	Circle c(2);
	cout << "�����ε����Ϊ��" << rec.getArea() << endl;
	cout << "�����ε��ܳ�Ϊ��" << rec.getPerim() << endl;
	cout << "Բ�����Ϊ��" << c.getArea() << endl;
	cout << "Բ���ܳ�Ϊ��" << c.getPerim() << endl;
	return 0;
}