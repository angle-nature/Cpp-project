#include<iostream>
using namespace std;

int& function01()
{
	int a = 10;   //局部变量储存在栈区  是局部变量 不能返回局部变量的引用	
	return a;
}

int& function02()
{
	static int b = 20;  //静态变量存储在全局区  可以返回变量的引用
	return b;
}

int main()
{
	int& ref01 = function01();
	int& ref02 = function02();

	cout << "ref= " << ref01 << endl;  //第一次正确是因为编译器做了一次数据的保留
	cout << "ref= " << ref01 << endl;  //再次打印会出现错误，因为a的内存已经释放

	cout << "ref= " << ref02 << endl;  //多次打印不会出现错误
	cout << "ref= " << ref02 << endl;

	function02() = 1000;     //如果函数的返回值是引用，函数的调用可以作为左值

	cout << "ref= " << ref02 << endl;
	cout << "ref= " << ref02 << endl;

	return 0;
}