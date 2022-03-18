#include<iostream>
using namespace std;
//#include"Person.h"  //有错误 因为类模板成员函数只有在编译阶段才会创建

//类模板分文件编写问题及解决方法

//1、第一种解决方式，直接包含源文件
//#include"Person.cpp"

//2、第二种解决方法，将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件
#include"Person.hpp"

int main()
{
	Person<string, int>p("张三", 18);
	p.showPerson();

	system("pause");

	return 0;
}