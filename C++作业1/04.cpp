#include<iostream>
#include<iomanip>
using namespace std;

void problem()
{
	//使用8个字节类型变量，采用十进制存储手机号码
	char c0 = 78, c1 = 56;
	char c2 = 34, c3 = 12;
	char c4 = 39, c5 = 1;
	cout << dec << setw(1) << (int)c5 << setw(2) << (int)c4 << (int)c3 << (int)c2 << (int)c1 << (int)c0 << endl;

	//使用8个字节类型变量，采用十六进制存储手机号码
	c0 = 0x78;
	c1 = 0x56;
	c2 = 0x34;
	c3 = 0x12;
	c4 = 0x39;
	c5 = 0x1;
	cout << hex << setw(1) << (int)c5 << setw(2) << (int)c4 << (int)c3 << (int)c2 << (int)c1 << (int)c0 << endl;

	//使用4个双字节无符号变量，采用十进制存储号码
	unsigned short s0 = 5678;
	unsigned short s1 = 1234;
	unsigned short s2 = 139;
	cout << dec << setw(3) << s2 << setw(4) << s1 << s0 << endl;

	//使用4个双字节无符号变量，采用十六进制存储号码
	s0 = 0x5678;
	s1 = 0x1234;
	s2 = 0x139;
	cout << hex << setw(3) << s2 << setw(4) << s1 << s0 << endl;
}

int main()
{
	problem();

	system("pause");
	return 0;
}