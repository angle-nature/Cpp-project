#include<iostream>
using namespace std;

//������Ʒ��
class AbstractDrinking
{
public:

	//��ˮ
	virtual void Boil() = 0;

	//����
	virtual void Brew() = 0;

	//���뱭��
	virtual void PourinCup() = 0;

	//���븨��
	virtual void Putsomething() = 0;

	void makeDrink()
	{
		Boil();
		Brew();
		PourinCup();
		Putsomething();
	}
};

//��������
class Coffee :public AbstractDrinking
{
public:

	//��ˮ
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	}

	//����
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}

	//���뱭��
	virtual void PourinCup()
	{
		cout << "���뿧�ȱ���" << endl;
	}

	//���븨��
	virtual void Putsomething()
	{
		cout << "�����Ǻ�ţ��" << endl;
	}
};

//������Ҷ
class Tea :public AbstractDrinking
{
public:

	//��ˮ
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	}

	//����
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}

	//���뱭��
	virtual void PourinCup()
	{
		cout << "����豭��" << endl;
	}

	//���븨��
	virtual void Putsomething()
	{
		cout << "�������" << endl;
	}
};

void doWork(AbstractDrinking* abd)  //AbstractDrinking* abd=new Coffee
{
	abd->makeDrink();
	delete abd;
}

void test()
{
	doWork(new Coffee);
	//doWork(new Tea);
}

int main()
{
	test();

	system("pause");

	return 0;
}