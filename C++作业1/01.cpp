#include<iostream>
#include<cmath>
using namespace std;

void root()
{
	float a, b, c;

	cout << "������a,b,c��ֵ" << endl;
	cin >> a >> b >> c;

	if (a == 0)
	{
		if (b == 0 && c == 0)
			cout << "�����������" << endl;
		else if (b == 0 && c != 0)
			cout << "�����޽�" << endl;
		else
			cout << "������Ψһ��:" << -(c / b) << endl;
	}
	else
	{
		if (b * b < 4 * a * c)
			cout << "�����޽�" << endl;
		else
		{
			float x1 = ((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
			float x2 = ((-b - sqrt(b * b - 4 * a * c)) / (2 * a));

			cout << "�����������⣬�ֱ�Ϊ��" << x1 << "��" << x2 << endl;
		}
	}
}

int main()
{
	root();

	system("pause");

	return 0;
}