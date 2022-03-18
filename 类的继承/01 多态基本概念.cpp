#include<iostream>
using namespace std;

//多态
class Animal
{
public:
	//speak函数就是虚函数
	//函数前面加上virtual关键字 变成虚函数 那么编译器编译的时候就不确定函数调用了
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "狗在说话" << endl;
	}
};

//我们希望传入什么对象 那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定 那么就是静态联编
//如果函数地址在运行阶段就能确定 那么就是动态联编
void doSpeak(Animal& animal)  //Animal &animal=cat;
{
	animal.speak();
}

//执行说话的函数
//地址早绑定 在编译阶段确定函数地址
//如果想执行猫说话 那么这个函数地址就不能提前绑定 需要在运行阶段进行绑定 地址晚绑定

//多态满足条件
//1、有继承关系
//2、子类重写父类中的虚函数  （函数返回值相同 函数名相同 参数相同）
//多态使用
//父类指针或引用指向子类对象

void test()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

void test01()
{
	Animal animal;
	cout << "size of animal=" << sizeof(animal) << endl;  //为 4     4个字节为指针的内存 此指针为vfptr
}

int main()
{
	test();

	system("pause");

	return 0;
}