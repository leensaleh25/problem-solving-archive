#include <iostream>
#include <string>
using namespace std;

enum enOperationType{add='+',subterct='-',Muliply='*',divide='/' };

float ReadNumber(string Message) {
	float Number=0;	
	cout << Message << endl;
	cin >> Number;
	return Number;
}
enOperationType ReadOpretions(string Message) {
	char ot = '+';
	cout << Message<< endl;
	cin>>ot;
	return (enOperationType)ot;
}
float Calculate(float Number1,float Number2, enOperationType optype) {
	switch (optype)
	{
	case enOperationType::add:
		return Number1 + Number2;
	case  enOperationType::subterct:
		return Number1 - Number2;
	case  enOperationType::Muliply:
		return Number1 *Number2;
	case  enOperationType::divide:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}
float SumNumbers() {
	int number = 0; int Counter = 1; int sum = 0;
	do {
		number = ReadNumber("Enter Number: " + to_string(Counter));
		if (number ==-99)
			break;
		Counter++;
		sum += number;
	} while (number !=-99);
	return sum;
}

enum enPrimNotPrime { Prime = 1,NotPrime = 2};

float ReadPositiveNumber(int &Number) {
	
	do {
      cout << "Enter a positive number :\n";
	  cin >> Number;
	} while (Number <= 0);
	return Number;
}
enPrimNotPrime CheckPrimeNumber(int Number) {
	int m = round(Number % 2);
	for (int Counter = 2; Counter <= m; Counter++) {
		if (Number % Counter == 0)
			return enPrimNotPrime::NotPrime;
	}
	return enPrimNotPrime::Prime;
}
void PrintNumberType(int Number) {
	if (enPrimNotPrime::NotPrime)
		cout << Number << "  is not a Prime Number." << endl;
	else
		cout << Number << "  is a Prime Number." << endl;
}

float ReadPositiveNumberEdit(string message) {
	float Number;
	do {
		cout << message;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
float CalculateRemainder(float  TotalBill, float TotalCashPaid) {
	return TotalCashPaid - TotalBill ;
}  
int main()
{

	float TotalBill = ReadPositiveNumberEdit("Please Enter Total Bill?\n");
	float TotalCashPaid = ReadPositiveNumberEdit("Please Enter Total Cash Paid?\n");
	cout << "********************************************************\n";
	cout << " TotalBill =  " << TotalBill << endl;
	cout << " TotalCashPaid = " << TotalCashPaid << endl;
	cout << "********************************************************\n";
	cout << "Remainder = " << CalculateRemainder(TotalBill, TotalCashPaid) << endl;
	return 0;
	/*int Number;
	ReadPositiveNumber(Number);
	PrintNumberType(CheckPrimeNumber(Number));*/
	
	/*cout << "\nResult=  " << SumNumbers();*/
	
	/*float Number1 = ReadNumber("Please enter the first Number:\n");
	float Number2=ReadNumber("Please enter the second Number:\n");

	enOperationType optype =ReadOpretions("Enter operation:\n");
	cout<<Calculate(Number1, Number2, optype);*/

}
