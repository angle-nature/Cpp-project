#include<iostream>
using namespace std;

class GaoSi
{
private:
	float a[3][4];
	double x=0, y=0, z=0;
public:
	GaoSi(float a[3][4])
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 4; j++)
				this->a[i][j] = a[i][j];
	}
private:

	void printArray()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
				cout << a[i][j] << " ";

			cout << endl;
		}


		cout << "===========" << endl;
	}

	void swap(int i1, int i2) //��������Ԫ��
	{
		for (int j = 0; j < 4; j++)
		{
			int temp = a[i1][j];
			a[i1][j] = a[i2][j];
			a[i2][j] = temp;
		}
	}

	void changeToOne(int i, int j) //����i+1�еȼ۱任ʹ��a[i][j] = 1
	{
		float temp = a[i][j];
		for (int col = j; col < 4; col++)
			a[i][col] = a[i][col] / temp;
	}

	void changeToZero(int i, int j) //�ȼ۱任��i+1��ʹϵ��a[i][j]=0
	{
		int row;
		float temp = a[i][j];
		if (a[i - 1][j] == 1)
			row = i - 1;
		else
			row = i - 2;
		for (int col = j; col < 4; col++)
			a[i][col] += a[row][col] * (-temp);
	}

	bool isZero(float num)
	{
		return num - 0.0 < 1.0e-12;
	}
public:
	void solve()
	{
		for (int i = 2; i > 0; i--) //ʹA11�ڵ�1�������
		{
			if (a[i][0] > a[i - 1][0])
				swap(i, i - 1);
		}

		if (!isZero(a[0][0]))
		{
			changeToOne(0, 0);

			if (a[1][1] < a[2][1])
				swap(1, 2);

			changeToZero(1, 0);
			changeToZero(2, 0);
			if (!isZero(a[1][1]))
			{
				changeToOne(1, 1);
				changeToZero(2, 1);
				if (!isZero(a[2][2]))
				{
					changeToOne(2, 2);

					z = a[2][3];
					y = a[1][3] - a[1][2] * z;
					x = a[0][3] - a[0][2] * z - a[0][1] * y;

					cout << "x=" << x << endl;
					cout << " y=" << y << endl;
					cout << " z=" << z << endl;
				}
				else
				{
					if (!isZero(a[2][3]))
						cout << "�˷����޽⣡" << endl;
					else
					{
						cout << "x=" << a[0][3] - a[0][1] * a[1][3] << "+(" << a[0][1] * a[1][2] - a[0][2] << ")k" << endl;
						cout << "y=" << a[1][3] << "+("<<-a[1][2] << ")k" << endl;
						cout << "z=k" << endl;
						cout << "kΪ����ʵ��" << endl;
					}
				}
			}
			else
			{
				if (a[1][2] < a[2][2])
					swap(1, 2);

				if (!isZero(a[1][2]))
				{
					changeToOne(1, 2);
					changeToZero(2, 2);
					if (!isZero(a[2][3]))
						cout << "�˷����޽⣡" << endl;
					else
					{
						cout << "x=" << a[0][3] - a[0][2] * a[1][3] << "+(" << -a[0][1] << ")k" << endl;
						cout << "y=k" << endl;
						cout << "z=" << a[1][3] << endl;
						cout << "kΪ����ʵ��" << endl;
					}
				}
				else
				{
					if (!isZero(a[1][3]))
						cout << "�˷����޽⣡";
					else
					{
						cout << "x=" << a[0][3] << "+(" << -a[0][1] << ")k1+(" << -a[0][2] << ")k2" << endl;
						cout << "y=k1" << endl;
						cout << "z=k2" << endl;
						cout << "k1��k2��Ϊ����ʵ��" << endl;
					}
				}
			}
		}
		else
		{
			for (int i = 2; i > 0; i--) 
			{
				if (a[i][1] > a[i - 1][1])
					swap(i, i - 1);
			}

			if (!isZero(a[0][1]))
			{
				changeToOne(0, 1);
				if (a[1][2] < a[2][2])
					swap(1, 2);
				changeToZero(1, 1);
				changeToZero(2, 1);

				if (!isZero(a[1][2]))
				{
					changeToOne(1, 2);
					changeToZero(2, 2);
					if (!isZero(a[2][3]))
						cout << "�˷����޽⣡" << endl;
					else
					{
						z = a[1][3] / a[2][3];
						y = a[0][3] - a[0][2] * z;

						cout << "xΪ����ʵ�� " << endl;
						cout << " y=" << y << endl;
						cout << " z=" << z << endl;
					}
				}
				else
				{
					if(!isZero(a[1][3]))
						cout << "�˷����޽⣡" << endl;
					else
					{
						cout << "xΪ����ʵ��" << endl;
						cout << "y=" << a[0][3] << "+(" << -a[0][2] << ")k" << endl;
						cout << "z=k" << endl;
						cout << "kΪ����ʵ��" << endl;
					}
				}
			}
			else
			{
				for (int i = 2; i > 0; i--) 
				{
					if (a[i][2] > a[i - 1][2])
						swap(i, i - 1);
				}

				if (!isZero(a[0][2]))
				{
					changeToOne(0, 2);
					cout << "x��yΪ����ʵ��" << endl;
					cout << "z=" << a[0][3] << endl;
				}
				else
				{
					if (!isZero(a[0][3]))
						cout << "�˷����޽⣡";
					else
						cout << "x��y��z��Ϊ����ʵ��" << endl;
				}
			}
			
		}
	}

};

int main()
{
	float a[3][4] =
	{
		{2,4,5,55},
		{-2,5,-2,20},
		{5,5,-1,81}
	};

	GaoSi gaosi(a);

	gaosi.solve();

	return 0;
}