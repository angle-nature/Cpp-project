#include<iostream>
using namespace std;
#include<functional>

//�ڽ��������� �����º���

void test()
{
	negate<int> n; //һԪ�º��� ȡ���º���
	cout<<n(51)<<endl;

	plus<int> p;  //��Ԫ�º��� �ӷ�
	cout << p(10, 29) << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}