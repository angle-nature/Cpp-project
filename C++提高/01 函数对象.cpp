#include<iostream>
using namespace std;

//1������������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test01()
{
	MyAdd myAdd;
	cout<<myAdd(10, 10)<<endl;
}

//2����������������Լ���״̬
class MyPrint
{
public:

	MyPrint()
	{
		count = 0;
	}

	void operator()(string txt)
	{
		cout << txt << endl;
		this->count++;  //ͳ��ʹ�ô���
	}

	int count;  //�ڲ��Լ�״̬
};

void test02()
{
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint���ô�����" << myPrint.count << endl;
}

//3���������������Ϊ��������
void doPrint(MyPrint& mp, string txt)
{
	mp(txt);
}

void test03()
{
	MyPrint myPrint;
	doPrint(myPrint, "hello world");
}

int main()
{
	//test01();
	test02();
	//test03();

	system("pause");

	return 0;
}