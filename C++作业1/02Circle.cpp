#include<iostream>
#include<cmath>
using namespace std;

class Point {
    double x, y;
public:
    virtual double getx() { return x; };
    virtual double gety() { return y; };
    Point(double xx = 10, double yy = 20) :x(xx), y(yy) {};
};

class Circle
{
private:
    const double PI = 3.1415926;//Բ����
    Point point; //Բ��
    double r;//�뾶
    static int number; //Բ�ĸ���
public:
    Circle(Point p,int r=0)
    {
        this->point = p;
        this->r = r;
        cout << ++number << endl; //���Բ��ID
    }
    //���
    double getArea() { return PI * r * r; }
    //�ܳ�
    double getCircumference() { return 2 * PI * r; }

    double distance(Circle c) //��������ԲԲ��֮��ľ���
    {
        double distance = sqrt((this->point.getx() - c.point.getx()) 
                               * (this->point.getx() - c.point.getx()) +
                               (this->point.gety() - c.point.gety()) 
                               * (this->point.gety() - c.point.gety()));
        return distance;
    }
};

int Circle::number = 0;

int main()
{
    Point p1(1,1), p2(3,4);
    Circle c1(p1,5), c2(p2,8);

    double area1 = c1.getArea();
    double circum = c1.getCircumference();
    double distance = c1.distance(c2);

    cout << "c1�����Ϊ��" << area1 << endl;
    cout << "c1���ܳ�Ϊ��" << circum << endl;
    cout << "c1Բ����c2Բ�ĵľ���Ϊ��" << distance << endl;
	return 0;
}