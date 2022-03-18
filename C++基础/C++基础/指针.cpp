#include<iostream>
using namespace std;

int main()
{
	//定义指针并且初始化
	int* p = NULL;  //空指针  指向0

	//内存编号为0~255为系统占用内存，不允许用户访问
	// int *p=100 错误

	//野指针
	int* p1 = (int*)0X1100;
	//cout << *p << endl;    //会引发错误

	return 0;
}