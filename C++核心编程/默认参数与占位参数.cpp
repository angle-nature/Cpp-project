#include<iostream>
using  namespace std;

//������Ĭ�ϲ���
//ע������1��  Ĭ�ϲ���һ����  ����Ĭ��ֵ�Ĳ�����ʼ���󣨴������ң�ÿһ��������������Ĭ��ֵ
//ע������2��  ���������ͺ������岻��ͬʱ��Ĭ�ϲ���
int function01(int a, int b = 10, int c = 20)
{
	return a + b + c;
}

//ռλ����  ֻ���������� û�б����� ռλ����Ҳ���Ը�ֵĬ��ֵ
void function02(int a, int)
{

}

int main()
{
	function01(10);
	function02(10, 20);

	system("pause");
	return 0;
}