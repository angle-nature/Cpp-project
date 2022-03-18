#include<iostream>
#include<cmath>
using namespace std;

void root()
{
	float a, b, c;

	cout << "请输入a,b,c的值" << endl;
	cin >> a >> b >> c;

	if (a == 0)
	{
		if (b == 0 && c == 0)
			cout << "方程有任意解" << endl;
		else if (b == 0 && c != 0)
			cout << "方程无解" << endl;
		else
			cout << "方程有唯一解:" << -(c / b) << endl;
	}
	else
	{
		if (b * b < 4 * a * c)
			cout << "方程无解" << endl;
		else
		{
			float x1 = ((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
			float x2 = ((-b - sqrt(b * b - 4 * a * c)) / (2 * a));

			cout << "方程有两个解，分别为：" << x1 << "、" << x2 << endl;
		}
	}
}

int main()
{
	root();

	system("pause");

	return 0;
}