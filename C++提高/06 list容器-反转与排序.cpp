#include<iostream>
using namespace std;
#include<list>
#include<algorithm>

ostream& operator<<(ostream& cout, list<int>& L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	return cout;
}

//bool comparePeson(Person& p1, Person& p2)
//{
//	//按年龄升序
//	if (p1.m_Age == p2.m_Age)
//	{
//		//年龄相同 按身高降序
//		return p1.m_H > p1.p2m_H;
//	}
//	else
//	{
//		return p1.m_Age < p2.m_Age;
//	}
//}

bool myCompare(int val1, int val2)
{
	//降序 就让第一个数大于第二个数
	return val1 > val2;
}

//vector容器的插入和删除操作
void test()
{
	list<int>L1;

	//尾插
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(30);
	L1.push_back(50);
	L1.push_back(40);

	cout << "反转前：" << endl;
	cout << L1 << endl;

	L1.reverse();
	cout << "反转后：" << endl;
	cout << L1 << endl;

	//所有不支持随机访问迭代器的容器，不可以用标准算法
	//不支持随机访问迭代器的容器，内部会提供一些算法
	
	//sort(L1.begin(), L1.end());  //报错

	L1.sort();
	cout << "排序后：" << endl; //默认规则 从小到大 升序
	cout << L1 << endl;

	L1.sort(myCompare); //降序
	cout << L1 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}