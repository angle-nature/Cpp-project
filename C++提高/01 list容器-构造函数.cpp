#include<iostream>
using namespace std;
#include<list>

//输出
void printlist(list<int>& l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//list容器构造
void test()
{
	//创建list容器
	list<int>l1; //默认构造 无参构造

	for (int i = 0; i < 10; i++)
	{
		l1.push_back(i);
	}

	//遍历容器
	printlist(l1);

	//通过区间方式进行构造
	list<int> l2(l1.begin(), l1.end());

	printlist(l2);

	//n个elem方式构造
	list<int> l3(10, 17);  //输入 10 个 17 
	printlist(l3);

	//拷贝构造
	list<int> l4(l3);
	printlist(l4);
}

int main()
{
	test();

	system("pause");

	return 0;
}