#include<iostream>
using namespace std;

class MyPrint
{
public:

	//���أ��������  Ҳ�Ʒº���
	void operator()(string text)
	{
		cout << text << endl;
	}
};

void test()
{
	MyPrint myprint;
	myprint.operator()("����������");

	//MyPrint() ��Ϊ��������  ʹ��֮���������ͷ�
	MyPrint()("������������");
}

int main()
{
	test();

	system("pause");

	return 0;
}