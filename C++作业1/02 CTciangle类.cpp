#include<iostream>
#include<cmath>
using namespace std;

class CTciangle
{
public:
	CTciangle()
	{
		this->m_A = 0;
		this->m_B = 0;
		this->m_C = 0;
	}

	void setEdge(float a, float b, float c)
	{
		this->m_A = a;
		this->m_B = b;
		this->m_C = c;
	}

	float getArea()
	{
		float p = (m_A + m_B + m_C) / 2;
		return sqrt(p * (p - m_A) * (p - m_B) * (p - m_C));
	}

	float getCircumference()
	{
		return m_A + m_B + m_C;
	}

private:
	float m_A;
	float m_B;
	float m_C;
};

int main()
{
	CTciangle ct;
	ct.setEdge(3, 4, 5);

	cout <<"三角形面积为："<< ct.getArea() << endl;
	cout <<"三角形周长为："<< ct.getCircumference() << endl;

	return 0;
}