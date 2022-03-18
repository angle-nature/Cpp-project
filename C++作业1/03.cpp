#include<iostream>
using namespace std;

void countCharacters()
{
	char ch ;
	int numLetters = 0, numSpace = 0, numDigit = 0, numOther = 0;

	while ((ch = cin.get()) != '\n')
	{
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
			numLetters++;
		else if (ch == ' ')
			numSpace++;
		else if (ch >= '0' && ch <= '9')
			numDigit++;
		else
			numOther++;
	}

	cout << "num of letter = " << numLetters << endl;
	cout << "num of space = " << numSpace << endl;
	cout << "num of digit = " << numDigit << endl;
	cout << "num of other = " << numOther << endl;

}

int main()
{
	countCharacters();

	system("pause");
	return 0;
}