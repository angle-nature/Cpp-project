#include<iostream>
using namespace std;
//#include"Person.h"  //�д��� ��Ϊ��ģ���Ա����ֻ���ڱ���׶βŻᴴ��

//��ģ����ļ���д���⼰�������

//1����һ�ֽ����ʽ��ֱ�Ӱ���Դ�ļ�
//#include"Person.cpp"

//2���ڶ��ֽ����������.h��.cpp�е�����д��һ�𣬽���׺����Ϊ.hpp�ļ�
#include"Person.hpp"

int main()
{
	Person<string, int>p("����", 18);
	p.showPerson();

	system("pause");

	return 0;
}