#include<iostream>
using namespace std;

class Cube
{
public:

	void setL(int length)  { m_L = length; }

	void setW(int width)   { m_W = width; }

	void setH(int high)    { m_H = high; }

	int getL()  { return m_L; }

	int getL()  { return m_L; }

	int getW()  { return m_W; }

	int getH()  { return m_H; }

	int getArea() { return 2 * (m_L * m_W + m_L * m_H + m_W * m_H); }

	int getVolume() { return m_L * m_W * m_H; }

private:

	int m_L;
	int m_W;
	int m_H;
};

int main()
{


	system("pause");
	return 0;
}