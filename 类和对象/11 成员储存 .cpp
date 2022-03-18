#include<iostream>
using namespace std;

class Person
{
public:

	int m_A;                //非静态成员变量  属于类的对象上

	static int m_B;         //静态成员变量  不属于类的对象上

	void func01() {}        //非静态成员函数  不属于类的对象上

	static void func02(){}  //静态成员函数  不属于类的对象上
};

void test01()
{
	Person p1;
	//空对象占用内存为： 1
	//C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
	cout << "size of Person= " << sizeof(p1) << endl;
}

int main()
{
	test01();

	system("pause");

	return 0;
}