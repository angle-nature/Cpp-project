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
    const double PI = 3.1415926;//圆周率
    Point point; //圆心
    double r;//半径

public:
    Circle(Point p, int r = 0)
    {
        this->point = p;
        this->r = r;

    }
    //面积
    double getArea() { return PI * r * r; }
    //周长
    double getCircumference() { return 2 * PI * r; }
    //获取半径
    int getR() { return r; }
    Circle operator++(int) //后置自增
    {
        Circle temp = *this;
        this->r++;
        return temp;
    }

    Circle& operator++() //前置自增
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

    cout << "圆c的面积为：" << area1 << endl;
    cout << "圆c的周长为：" << circum << endl;
    cout << "圆c初始半径为：" << c.getR() << endl;
    cout << "圆c前置自增后的半径为：" << (++c).getR() << endl;
    cout << "圆c后置自增后的半径为：" << c++.getR() << endl;

    return 0;
}