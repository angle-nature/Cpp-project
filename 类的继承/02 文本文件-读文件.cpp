#include<iostream>
using namespace std;
#include<fstream>
#include<string>

void test()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	//�ж��ļ��Ƿ�ɹ���
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	//��ȡ����
	//��һ�ַ�ʽ
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//�ڶ��ַ�ʽ
	//char buf[1024] = { 0 };    //buffer:����
	//ifs.getline(buf, sizeof(buf));

	//	cout << buf << endl;
	
	//�����ַ�ʽ
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

	//������
	char c;
	while ((c = ifs.get()) != EOF)  //EOF: end of file
	{
		cout << c;
	}


}

int main()
{
	test();

	system("pause");

	return 0;
}