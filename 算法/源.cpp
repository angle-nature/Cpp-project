#include<iostream>
#include<algorithm>
using namespace std;
int n, Max, sum;//Max代表要求的 最大和，sum为临时求和
int Mydata[22][22];
int datax[22][22], datay[22][22];
int book[22], maxSum[22];

void dfs(int x) {
    if (x >= n)  // x到达n 之后，代表全部标记访问了
    { 
        Max = max(Max, sum); 
        return; 
    }
    int cnt = 0;//需要写 剪枝 函数，不然 超时，剪枝条件 就是 （之前x个一匹配好的sum和之后的x->n个最大值，加起来<=Max，减去）
    for (int i = x; i < n; i++) // 求 x 之后 男生匹配 女生的最大值 和
        cnt += maxSum[i];
    if (sum + cnt < Max) //若从第x组->第n组   当前搜索sum 加上 假设匹配后的最大值cnt，仍然小于Max ，可以剪枝了,Max为已经求得的最大值
        return;
    for (int i = 0; i < n; i++) {
        if (!book[i]) {
            book[i] = 1;
            sum += Mydata[x][i];
            dfs(x + 1);
            book[i] = 0;//回溯
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