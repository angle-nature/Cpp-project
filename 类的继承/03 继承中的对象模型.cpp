#include<iostream>
using namespace std;

class Base1
{

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;  //私有成员只是被隐藏了  但还是会被继承下去

};

//公共继承方式
class Son1 :public Base1
{
public:
	
	int m_D;
};

//利用开发人员提示命令工具（Developer Command Prompt for VS 2019）查看对象模型
//跳转盘符 E：
//跳转文件路径 cd E:\C项目\类的继承
//查看命令：  cl /d1 reportSingleClassLayout类名 文件名

void test()
{
	//父类中所有非静态成员都会被继承下去父类中的私有成员 是被编译器隐藏了 因此访问不到 但是被继承下去了
	cout << "size of Son =" << sizeof(Son1) << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}