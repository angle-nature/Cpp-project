#include<iostream>
using namespace std;
#include<list>

//vector容器的数据存取操作
void test()
{
	list<int>L1;

	//尾插
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//L[0]; 不可以用[]访问list容器中的元素
	//L1.at(0);  不可以用at方式访问list容器中的元素
	//原因是list本质上是链表，不是一个连续性空间存储数据

	cout << "第一个元素为：" << L1.front() << endl;
	cout << "最后一个元素为：" << L1.back() << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}