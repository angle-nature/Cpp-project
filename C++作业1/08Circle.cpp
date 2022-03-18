#include<iostream>
#include<cmath>
using namespace std;

class Point {
    int x, y;
public:
    int getx() { return x; };
    int gety() { return y; };
    Point(int xx = 10, int yy = 20) :x(xx), y(yy) {};
};

class Circle
{
private:
    const double PI = 3.1415926;//Բ����
    Point point; //Բ��
    double r;//�뾶

public:
    Circle(Point p, int r = 0)
    {
        this->point = p;
        this->r = r;

    }
    //���
    double getArea() { return PI * r * r; }
    //�ܳ�
    double getCircumference() { return 2 * PI * r; }
    //��ȡ�뾶
    int getR() { return r; }
    Circle operator++(int) //��������
    {
        Circle temp = *this;
        this->r++;
        return temp;
    }

    Circle& operator++() //ǰ������
    {
        this->r++;
        return *this;
    }
};

int main()
{
    Point p(1, 1);
    Circle c(p, 5);

    double area1 = c.getArea();
    double circum = c.getCircumference();

    cout << "Բc�����Ϊ��" << area1 << endl;
    cout << "Բc���ܳ�Ϊ��" << circum << endl;
    cout << "Բc��ʼ�뾶Ϊ��" << c.getR() << endl;
    cout << "Բcǰ��������İ뾶Ϊ��" << (++c).getR() << endl;
    cout << "Բc����������İ뾶Ϊ��" << c++.getR() << endl;

    return 0;
}