#include<iostream>
#include<algorithm>
using namespace std;
struct node 
{
    int val;//��ֵ
    int weight;//����
    double Ratio;//��ֵ��
}goods[10];
bool cmp(node x, node y) 
{
    return x.Ratio > y.Ratio;//����ֵ�Ƚ���
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
    sort(goods, goods + n, cmp);//�����еĻ���������� ���Ӽ�ֵ�ȴ�С
    int maxVal = 0;
    int rest = m;//ʣ������
    for (int i = 0; i < n; i++) {
        if (rest - goods[i].weight >= 0) //����װ�������������
        {
            rest -= goods[i].weight;
            maxVal += goods[i].val;//��ȫ��װ��  �����ȫ���ļ�ֵ
        }
        else //��ʣ�µ�������*��i�ֻ���ļ��رȣ��ڼ����Ѿ����ػ���ļ�ֵ���õ�����ֵ
        {
            maxVal += goods[i].Ratio * rest;//��ʣ��Ŀ�������*��ֵ�ȣ��õ���ֵ
            break;
        }
    }
    cout << maxVal << endl;
    return 0;
}