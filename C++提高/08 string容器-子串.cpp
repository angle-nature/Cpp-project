#include<iostream>
using namespace std;

//string ���Ӵ�

void test01()
{
	string str = "hello";

	string substr = str.substr(1, 3); //���±�Ϊ 1 ��λ�ÿ�ʼ��ȡ 3 ���ַ�

	cout << "substr=" << substr << endl;

}

//ʵ�ò���
void test02()
{
	string email = "zhangsan@qq.com";

	//���ʼ��л�ȡ�û�����Ϣ
	int pos = email.find("@");

	string usremail = email.substr(0, pos);
	cout << "usremail=" << usremail << endl;
}

int main()
{
	//test01();
	test02();

	system("pause");

	return 0;
}