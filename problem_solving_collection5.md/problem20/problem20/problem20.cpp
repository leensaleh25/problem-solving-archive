#include <iostream>
#include<cstdlib>
using namespace std;

int ReadNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;

}
enum enMenue {SmallLetter=1,
	CapitalLetter=2,
	SpecialCharacter=3,
	digit=4};

char GetRandomCharacter(enMenue charType) {
	switch (charType)
	{
	case SmallLetter:
		return char(ReadNumber(97,122));
	case CapitalLetter:
		return char(ReadNumber(65, 90));
	case SpecialCharacter:
		return char(ReadNumber(33, 47));
	case digit:
		return char(ReadNumber(48, 57));
	
	}  
	return '\0';
}//
int main()
{
	srand((unsigned)time(NULL));
	cout<<GetRandomCharacter(enMenue::SmallLetter)<<endl;
	cout << GetRandomCharacter(enMenue::CapitalLetter)<<endl;
	cout << GetRandomCharacter(enMenue::SpecialCharacter)<<endl;
	cout << GetRandomCharacter(enMenue::digit)<<endl;

}



