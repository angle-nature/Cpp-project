#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

struct point
{
	int id=0;
	double x;
	double y;
	point(double x, double y) :x(x), y(y) {}
	point() { return; }
};

//��������x��������
bool compareX(const point &A, const point &B)
{
	if (A.x == B.x) return A.y < B.y;
	else return A.x < B.x;
}

//����������������
bool compareY(const point &A, const point &B)
{
	if (A.y == B.y) return A.x < B.x;
	else return A.y < B.y;
}

//����֮��ľ���
double distance(const point &A, const point &B)
{
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

//���������߼��ϵ��������
double merge(vector<point> &points, double dis, int mid)
{
	vector<point> middle;

	//�Ѽ����߷��������ĵ�����µļ���
	for (int i = 0; i < points.size(); i++)
	{
		if (points[mid].x - points[i].x >= 0 && points[mid].x - points[i].x <= dis)
		{
			points[i].id = -1;
			middle.push_back(points[i]);
		}

		else if (points[i].x - points[mid].x >= 0 && points[i].x - points[mid].x <= dis)
		{
			points[i].id = 1;
			middle.push_back(points[i]);
		}
	
	}

	sort(middle.begin(), middle.end(), compareY);  //���м伯�ϰ���������������

	//�����㷨
	for (int i = 0; i < middle.size(); i++)
	{
		for (int j = 1; j <= 7 && (i + j) < middle.size(); j++)
		{
			if(middle[i].id!=middle[i+j].id)
				if (distance(middle[i], middle[i + j]) < dis)
					dis = distance(middle[i], middle[i + j]);
		}
	}

	return dis;
}

double closestDis(vector<point> &points)
{
	if (points.size() == 2)
		return distance(points[0], points[1]);
	if (points.size() == 3)
		return min(distance(points[0], points[1]), min(distance(points[0], points[2]), distance(points[1], points[2])));

	int mid = (points.size() / 2) - 1;
	double dl, dr, d;

	vector<point> left(mid + 1), right(points.size()-mid-1);

	copy(points.begin(), points.begin() + mid + 1, left.begin());  // �������㼯��
	copy(points.begin() + mid + 1, points.end(), right.begin());  // �ұ�����㼯��

	dl = closestDis(left);
	dr = closestDis(right);
	d = min(dl, dr);

	return merge(points, d, mid);
}

int main()
{
	int count;
	//cin >> count;
	vector<point> points;
	double x, y;

	while (~scanf_s("%d", &count) && count != 0)
	{
		for (int i = 0; i < count; i++)
		{
			cin >> x >> y;
			point p(x, y);
			points.push_back(p);
		}
		sort(points.begin(), points.end(), compareX);
		cout << setiosflags(ios::fixed) << setprecision(2) << closestDis(points) / 2.0 << endl;
	}

	return 0;
}