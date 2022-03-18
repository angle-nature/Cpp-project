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
    for (int i = 0; i < n - 1; i += 2) {  //N/2次循环  每一次循环进行3次比较  共3N/2次比较
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
    //若数组长度为奇数，还需要和最后一个数作比较 
    if (flag) {
        if (a[n] < min)
            min = a[n];
        if (a[n] > max)
            max = a[n];
    }
    cout << "The max value of the array is: " << max << endl;
    cout << "The min value of the array is: " << min << endl;
}