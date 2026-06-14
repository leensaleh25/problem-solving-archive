#include <iostream>
#include<cstdlib>
#include <string>
using namespace std;

int ReadPositiveNumber(int& Number) {

	do {
		cout << "enter Number" << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int ReadNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;

}
enum enMenue {
	SmallLetter = 1,
	CapitalLetter = 2,
	SpecialCharacter = 3,
	digit = 4
};

char GetRandomCharacter(enMenue charType) {
	switch (charType)
	{
	case SmallLetter:
		return char(ReadNumber(97, 122));
	case CapitalLetter:
		return char(ReadNumber(65, 90));
	case SpecialCharacter:
		return char(ReadNumber(33, 47));
	case digit:
		return char(ReadNumber(48, 57));

	}
	return '\0';
}

string GenerateWord(enMenue charType, short length) {
	string Word;
	for (int i = 1; i <= length; i++)
	{
		Word = Word + GetRandomCharacter(charType);
	}
	return Word;
}

string GenterateKey() {
	string key = "";
	key = GenerateWord(enMenue::CapitalLetter, 4) + "-";
	key = key + GenerateWord(enMenue::CapitalLetter, 4) + "-";
	key = key + GenerateWord(enMenue::CapitalLetter, 4) + "-";
	key = key + GenerateWord(enMenue::CapitalLetter, 4);
	return key;
}
void FillArray(string Word[100], int arrLength) {
	
	for (int i = 0; i <= arrLength-1; i++) {
		cout << "\nArray [" << i<<"]";
		Word[i] = GenterateKey();
		cout << Word[i];
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int Number;
	string Word[100];
	FillArray(Word, ReadPositiveNumber(Number));
	return 0;
}

