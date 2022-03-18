#include<iostream>
using namespace std;

//多态
class Animal
{
public:
	
	Animal()
	{
		cout << "Animal构造函数调用" << endl;
	}

	//利用虚析构可以解决父类指针释放子类对象时不干净的问题
	//虚析构函数
	//virtual ~Animal()
	//{
	//	cout << "Animal虚析构函数调用" << endl;
	//}

	//纯虚构函数
	//类内声明  类外一定要写实现
	//有了纯虚析构之后 这个类也属于抽象类 无法实例化
	virtual ~Animal() = 0;

	//虚析构和纯虚析构函数只能有一个  且都需要有具体的实现

	//纯虚函数
	virtual void speak() = 0;
	
};

Animal::~Animal()
{
	cout << "Animal纯虚析构函数调用" << endl;
}

class Cat :public Animal
{
public:

	Cat(string name)
	{
		cout << "Cat构造函数的调用" << endl;
		m_Name = new string(name);
	}

	~Cat()
	{
		cout << *m_Name << "猫析构函数的调用" << endl;
		if (m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}

	void speak()
	{
		cout << "猫在说话" << endl;
	}

	string *m_Name;
};

void test()
{
	Animal* animal = new Cat("Tom");

	animal->speak();

	//父类指针在析构时候 不会调用子类中析构函数 导致子类如果有堆区属性 出现内存泄露
	delete animal;

}



int main()
{
	test();

	system("pause");

	return 0;
}