#include<iostream>
using namespace std;

//��̬
class Animal
{
public:
	
	Animal()
	{
		cout << "Animal���캯������" << endl;
	}

	//�������������Խ������ָ���ͷ��������ʱ���ɾ�������
	//����������
	//virtual ~Animal()
	//{
	//	cout << "Animal��������������" << endl;
	//}

	//���鹹����
	//��������  ����һ��Ҫдʵ��
	//���˴�������֮�� �����Ҳ���ڳ����� �޷�ʵ����
	virtual ~Animal() = 0;

	//�������ʹ�����������ֻ����һ��  �Ҷ���Ҫ�о����ʵ��

	//���麯��
	virtual void speak() = 0;
	
};

Animal::~Animal()
{
	cout << "Animal����������������" << endl;
}

class Cat :public Animal
{
public:

	Cat(string name)
	{
		cout << "Cat���캯���ĵ���" << endl;
		m_Name = new string(name);
	}

	~Cat()
	{
		cout << *m_Name << "è���������ĵ���" << endl;
		if (m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}

	void speak()
	{
		cout << "è��˵��" << endl;
	}

	string *m_Name;
};

void test()
{
	Animal* animal = new Cat("Tom");

	animal->speak();

	//����ָ��������ʱ�� ��������������������� ������������ж������� �����ڴ�й¶
	delete animal;

}



int main()
{
	test();

	system("pause");

	return 0;
}