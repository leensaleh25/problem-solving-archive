#include <iostream>
#include<cstdlib>
#include <string>
using namespace std;

int ReadPositiveNumber(int &Number) {
	
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
	for (int i = 1; i <=length; i++)
	{
		Word =Word+ GetRandomCharacter(charType);
	}
	return Word;
}

string GenterateKey() {
	string key = "";
	key = GenerateWord(enMenue::CapitalLetter, 4) + "-";
	key = key +GenerateWord(enMenue::CapitalLetter, 4) + "-";
	key = key + GenerateWord(enMenue::CapitalLetter, 4) + "-";
	key = key +GenerateWord(enMenue::CapitalLetter, 4) ;
	return key;
}

void GenterateKeys(int Number) {
	for (int i = 1; i <= Number; i++) {
		cout << "key [" << i << "]:";
		cout<<GenterateKey()<<endl;
	}
}

void PrintKeys(int Number) {
	
	for(int i = 1; i <=Number; i++){
		cout << "\n";
	for (int j = 1; j <= 4;j++) {
		cout << "-";
		for (int x= 1; x <= 4; x++) {
			cout << GetRandomCharacter(enMenue::CapitalLetter);
		}
		
	}

}}
int main()
{
	srand((unsigned)time(NULL));
	int Number;
	 GenterateKeys(ReadPositiveNumber(Number));
	 return 0;
}
