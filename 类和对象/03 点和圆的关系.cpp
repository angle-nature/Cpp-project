#include<iostream>
using namespace std;

//����
class Point
{
public:

	void setX_Y(int x,int y)
	{
		m_X = x;
		m_Y = y;
	}

	int getX()
	{
		return m_X;
	}

	int getY()
	{
		return m_Y;
	}

private:

	int m_X;
	int m_Y;
};


//Բ��
class Circle
{

public:

	void setCenter(Point center)
	{
		m_Center = center;
	}

	Point getCenter()
	{
		return m_Center;
	}

	void setR(int r)
	{
		m_R = r;
	}

	int getR()
	{
		return m_R;
	}

	//��Ա�����жϹ�ϵ
	void isInCircle(Point& p)
	{
		int distance=
			(p.getX() - getCenter().getX()) * (p.getX() - getCenter().getX()) +
			(p.getY() - getCenter().getY()) * (p.getY() - getCenter().getY());

		int rDistance = getR() * getR();

		if (distance == rDistance)
		{
			cout << "����Բ��" << endl;
		}

		else if (distance < rDistance)
		{
			cout << "����Բ��" << endl;
		}

		else
		{
			cout << "����Բ��" << endl;
		}
	}

private:
	
	int m_R;
	
	//һ�����п��Ե�����һ����
	Point m_Center;
};

//ȫ�ֺ����жϹ�ϵ
void isInCircle(Circle& c, Point& p)
{
	int distance =
		(p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) +
		(p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY());

	int rDistance = c.getR() * c.getR();

	if (distance == rDistance)
	{
		cout << "����Բ��" << endl;
	}

	else if (distance < rDistance)
	{
		cout << "����Բ��" << endl;
	}

	else
	{
		cout << "����Բ��" << endl;
	}

}

int main()
{
	Circle c;
	Point p1;
	Point p2;
	
	p1.setX_Y(10, 20);
	p2.setX_Y(10, 10);

	c.setCenter(p2);
	c.setR(10);

	isInCircle(c, p1);
	isInCircle(c, p2);

	c.isInCircle(p1);
	c.isInCircle(p2);
	
	system("pause");
	return 0;
}