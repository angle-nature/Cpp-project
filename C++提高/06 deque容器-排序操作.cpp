#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

ostream& operator<<(ostream& cout, deque<int>& d)
{
	for (deque<int>::iterator it = d.begin(); it < d.end(); it++)
	{
		cout << *it << " ";
	}
	return cout;
}

//deuqe容器排序
void test()
{ 
	deque<int>d1;

	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	cout << "排序前：" << endl;
	cout << d1 << endl;

	//排序 默认排序规则 从大到小 升序
	//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
	//vector容器也可以利用sort排序

	sort(d1.begin(), d1.end());
	cout << "排序后：" << endl;
	cout << d1 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}