#include<iostream>
using namespace std;

//��ģ����̳�

template<class T>
class Base
{
public:
	T m;
};

//class Son1:public Base //���󣬱���Ҫ֪�������е�T���ͣ����ܼ̳и�����
class Son1 :public Base<int>
{

};

//��������ָ�������е�T���ͣ�����Ҳ����ģ��
template<class T1,class T2>
class Son2 :public Base<T2>
{
public:

	Son2()
	{
		cout << "T1������Ϊ��" << typeid(T1).name() << endl;
		cout << "T2������Ϊ��" << typeid(T2).name() << endl;
	}

	T1 m_A;
};

void test()
{
	Son2<int,char>s;
}

int main()
{
	test();

	system("pause");
	return 0;
}