#include<iostream>
using namespace std;

//1������
void test01()
{
	string s1 = "abcdefghdek";

	int pos = s1.find("de"); //find()��������ֵΪ�ַ����ַ����е��±�  δ���ҵ�����-1

	if (pos == -1)
	{
		cout << "δ���ҵ�" << endl;
	}
	else
	{
		cout <<"�ҵ��ַ�����pos="<< pos << endl;
	}

	//rfind �� find ������
	//rfind �����������  find �������Ҳ���  ��������±궼�Ǵ������Ҽ���
	pos = s1.rfind("de");

	if (pos == -1)
	{
		cout << "δ���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ַ�����pos=" << pos << endl;
	}

}

void test02()
{
	string s = "abcdefg";

	s.replace(1, 3, "1111"); //�ӵ� 1 ���ַ���ʼ�滻 3 �� �滻�� ��1111��

	cout << s << endl;
}

int main()
{
	test01();
	test02();

	system("pause");

	return 0;
}