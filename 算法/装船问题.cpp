#include<iostream>
#include<algorithm>
using namespace std;
struct node 
{
    int val;//价值
    int weight;//重量
    double Ratio;//价值比
}goods[10];
bool cmp(node x, node y) 
{
    return x.Ratio > y.Ratio;//按价值比降序
}
int main()
{
    int m, n = 10;
    cin >> m;
    for (int i = 0; i < n; i++) 
    {
        cin >> goods[i].val >> goods[i].weight;
        goods[i].Ratio = goods[i].val / goods[i].weight;
    }
    sort(goods, goods + n, cmp);//将所有的货物进行排序 ，从价值比大到小
    int maxVal = 0;
    int rest = m;//剩余重量
    for (int i = 0; i < n; i++) {
        if (rest - goods[i].weight >= 0) //可以装下这个最大的重量
        {
            rest -= goods[i].weight;
            maxVal += goods[i].val;//能全部装上  则加上全部的价值
        }
        else //用剩下的载重量*第i种货物的价重比，在加上已经载重货物的价值，得到最大价值
        {
            maxVal += goods[i].Ratio * rest;//用剩余的空闲重量*价值比，得到价值
            break;
        }
    }
    cout << maxVal << endl;
    return 0;
}