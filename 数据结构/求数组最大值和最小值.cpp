#include <iostream>
using namespace std;

int main() {
    int a[] = { 9, 6, 7, 5, 13, 6, 2 };
    int n = sizeof(a)/sizeof(a[0]);
    int max = a[0];
    int min = a[0];
    bool flag = false;
    if (n % 2) {
        n--;
        flag = true;
    }
    for (int i = 0; i < n - 1; i += 2) {  //N/2��ѭ��  ÿһ��ѭ������3�αȽ�  ��3N/2�αȽ�
        if (a[i] <= a[i + 1]) {
            if (a[i] < min)
                min = a[i];
            if (a[i + 1] > max)
                max = a[i + 1];
        }
        else {
            if (a[i] > max)
                max = a[i];
            if (a[i + 1] < min)
                min = a[i + 1];
        }
    }
    //�����鳤��Ϊ����������Ҫ�����һ�������Ƚ� 
    if (flag) {
        if (a[n] < min)
            min = a[n];
        if (a[n] > max)
            max = a[n];
    }
    cout << "The max value of the array is: " << max << endl;
    cout << "The min value of the array is: " << min << endl;
}