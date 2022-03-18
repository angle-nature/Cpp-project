#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

#define N 100005
const int L = -1;
const int R = 1;

struct point
{
    int id;
    double x;
    double y;
};

point points[N], middle[N];

//按横坐标升序排列
bool cmpX(point A, point B)
{
    if (A.x == B.x) return A.y < B.y;
    else return A.x < B.x;
}

//按纵坐标升序排列
bool cmpY(point A, point B)
{
    if (A.y == B.y) return A.x < B.x;
    else return A.y < B.y;
}

//求两点之间的距离
double Dis(point A, point B)
{
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}


double solve(int low, int high)
{
    double dis;
    int sum = high - low;

    //两个数
    if (sum == 1) 
    {
        return Dis(points[low], points[high]);
    }

    //三个数
    if (sum == 2) 
    {
        double d1, d2, d3;
        d1 = Dis(points[low], points[low + 1]);
        d2 = Dis(points[low + 1], points[high]);
        d3 = Dis(points[low], points[high]);
        return min(d1, min(d2, d3));
    }

    double dl, dr, dm;
    int mid = (low + high) / 2; //中间下标
    int p = 0;  //中间带的点的个数

    dl = solve(low, mid);
    dr = solve(mid + 1, high);
    dis = min(dl, dr);

    double ldis = points[mid].x - dis;
    double rdis = points[mid].x + dis;

    for (int i = low; i <= mid; i++)
    {
        if (points[i].x >= ldis)
        {
            middle[p].id = L;//标记为属于左边的部分
            middle[p].x = points[i].x;
            middle[p].y = points[i].y;
            p++;
        }
    }
    for (int i=mid+1; i <= high; i++)
    {
        if (points[i].x <= rdis)
        {
            middle[p].id = R;//标记为右边的点
            middle[p].x = points[i].x;
            middle[p].y = points[i].y;
            p++;
        }
    }

    sort(middle, middle + p, cmpY);  //将中间带按纵坐标升序排列

    //核心算法
    for (int i = 0; i < p; i++)
    {
        for (int j = 1; (j <= 7) && (i + j) < p; j++)
        {
            if (middle[i].id != middle[i + j].id)//最小值可能出现在分界线不同的两边
            {
                dm = Dis(middle[i], middle[i + j]);
                if (dm < dis)
                    dis = dm;
            }
        }
    }
    
    return dis;
}
int main()
{
    int n;
    while (~scanf("%d", &n) && n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            points[i].id = 0;
            scanf("%lf%lf", &points[i].x, &points[i].y);
        }
        sort(points, points + n, cmpX);
        printf("%.2f\n", solve(0, n - 1) / 2);
    }
    return 0;
}