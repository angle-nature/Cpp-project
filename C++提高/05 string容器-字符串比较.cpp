#include<iostream>
using namespace std;

//×Ö·û´®±È½Ï

void test()
{
	string str1 = "hello";
	string str2 = "hello";

	if (str1.compare(str2) == 0)
	{
		cout << "str1=str2" << endl;
	}

	str2 = "jello";

	if (str1.compare(str2) == -1)
	{
		cout << "str1>str2" << endl;
	}

	str2 = "eello";

	if (str1.compare(str2) == 1)
	{
		cout << "str1<str2" << endl;
	}

}

int main()
{
	test();

	system("pause");

	return 0;
}