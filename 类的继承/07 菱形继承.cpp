#include<iostream>
using namespace std;

//动物类
class Animal
{
public:

	int m_Age;
};

//利用虚继承 可以解决菱形继承的问题
//在继承之前 加上关键字 virtual
//Animal 类称为 虚基类
//羊类
class Sheep :virtual public Animal{};

//驼类
class Tuo:virtual public Animal{};

//羊驼类
class SheepTuo :public Sheep, public Tuo{};

void test()
{
	SheepTuo st;

	st.Sheep::m_Age=18;
	st.Tuo::m_Age = 28;

	//当出现菱形继承 两个父类中拥有相同成员 需要加以作用域区分
	cout << "st.Sheep::m_Age=" << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;

	//这份数据告诉我们 只有有一份就可以了 菱形继承导致数据有两份 导致了资源浪费
	//变为虚继承之后
	st.m_Age = 30;
	cout << "st.m_Age = " << st.m_Age << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}