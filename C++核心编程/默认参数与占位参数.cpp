#include<iostream>
using  namespace std;

//函数的默认参数
//注意事项1：  默认参数一旦有  从有默认值的参数开始往后（从左往右）每一个参数都必须有默认值
//注意事项2：  函数声明和函数定义不能同时有默认参数
int function01(int a, int b = 10, int c = 20)
{
	return a + b + c;
}

//占位参数  只有数据类型 没有变量名 占位参数也可以赋值默认值
void function02(int a, int)
{

}

int main()
{
	function01(10);
	function02(10, 20);

	system("pause");
	return 0;
}