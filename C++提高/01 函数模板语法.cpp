#include<iostream>
using namespace std;

//����ģ��
template<typename T> //����һ��ģ�壬���߱�������������н����ŵ�T��Ҫ����T��һ��ͨ����������
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;

	//���ú���ģ��������
	//1���Զ������Ƶ�
	//mySwap(a, b);

	//2����ʾָ������
	mySwap<int>(a, b);

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	system("pause");

	return 0;
}