#include<iostream>
using namespace std;
#include<queue>

//栈容器的常用接口

void test()
{
	//创建栈容器 栈容器必须符合先进后出
	queue<int> q;

	//向队列中添加元素 入队操作
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	//队列不提供迭代器 更不支持随机访问
	while (!q.empty())
	{
		//输出队头元素
		cout << "队头元素为：" << q.front() << endl;

		//输出队尾元素
		cout << "队尾元素为：" << q.back() << endl;
		cout << endl;

		//弹出队头元素
		q.pop();
	}

	cout << "队列的大小为：" << q.size() << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}