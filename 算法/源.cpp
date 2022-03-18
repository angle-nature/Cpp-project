#include<iostream>
#include<algorithm>
using namespace std;
int n, Max, sum;//Max����Ҫ��� ���ͣ�sumΪ��ʱ���
int Mydata[22][22];
int datax[22][22], datay[22][22];
int book[22], maxSum[22];

void dfs(int x) {
    if (x >= n)  // x����n ֮�󣬴���ȫ����Ƿ�����
    { 
        Max = max(Max, sum); 
        return; 
    }
    int cnt = 0;//��Ҫд ��֦ ��������Ȼ ��ʱ����֦���� ���� ��֮ǰx��һƥ��õ�sum��֮���x->n�����ֵ��������<=Max����ȥ��
    for (int i = x; i < n; i++) // �� x ֮�� ����ƥ�� Ů�������ֵ ��
        cnt += maxSum[i];
    if (sum + cnt < Max) //���ӵ�x��->��n��   ��ǰ����sum ���� ����ƥ�������ֵcnt����ȻС��Max �����Լ�֦��,MaxΪ�Ѿ���õ����ֵ
        return;
    for (int i = 0; i < n; i++) {
        if (!book[i]) {
            book[i] = 1;
            sum += Mydata[x][i];
            dfs(x + 1);
            book[i] = 0;//����
            sum -= Mydata[x][i];
        }
    }
}
void input(int data[22][22]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> data[i][j];
}
int main()
{
    cin >> n;
    input(datax);
    input(datay);
    Max = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Mydata[i][j] = datax[i][j] * datay[j][i];
            maxSum[i] = max(maxSum[i], Mydata[i][j]);
        }
        book[i] = 0;
    }
    dfs(0);
    cout << Max << endl;
    return 0;
}