#include<iostream>
using namespace std;

//��̬
class Animal
{
public:
	//speak���������麯��
	//����ǰ�����virtual�ؼ��� ����麯�� ��ô�����������ʱ��Ͳ�ȷ������������
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "è��˵��" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "����˵��" << endl;
	}
};

//����ϣ������ʲô���� ��ô�͵���ʲô����ĺ���
//���������ַ�ڱ���׶ξ���ȷ�� ��ô���Ǿ�̬����
//���������ַ�����н׶ξ���ȷ�� ��ô���Ƕ�̬����
void doSpeak(Animal& animal)  //Animal &animal=cat;
{
	animal.speak();
}

//ִ��˵���ĺ���
//��ַ��� �ڱ���׶�ȷ��������ַ
//�����ִ��è˵�� ��ô���������ַ�Ͳ�����ǰ�� ��Ҫ�����н׶ν��а� ��ַ���

//��̬��������
//1���м̳й�ϵ
//2��������д�����е��麯��  ����������ֵ��ͬ ��������ͬ ������ͬ��
//��̬ʹ��
//����ָ�������ָ���������

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
	cout << "size of animal=" << sizeof(animal) << endl;  //Ϊ 4     4���ֽ�Ϊָ����ڴ� ��ָ��Ϊvfptr
}

int main()
{
	test();

	system("pause");

	return 0;
}