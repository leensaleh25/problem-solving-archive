#include <iostream>
#include<string>
using namespace std;

int ReadPositiveNumber(string Message ) {
	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
string arrLoop(int Number,int checkNumber) {
    int Count = 0;
	int ElemntNumber;
	string OriginalNumber = "";
	for (int i = 1; i <= Number; i++) {
		cout << "enter array Elements:\n";
		cout << "Element [" << i << "]: ";
		cin >> ElemntNumber;
		OriginalNumber +=to_string( ElemntNumber);
		if (checkNumber == ElemntNumber) 
			Count++;
	
	}

	cout << checkNumber << "is repeated " << Count << "Times(S)"<<endl;
	cout << "Original array:";
	return OriginalNumber;


}
int main()
{
	
	cout << arrLoop( ReadPositiveNumber("Enter Number"), ReadPositiveNumber("enter check Number:"));
	
}
