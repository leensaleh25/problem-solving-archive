#include <iostream>
using namespace std;
bool IsLeapYear(int year) {
	if (year % 400 == 0)
		return true;
	else if (year % 4 == 0)
		return true;
	else if (year % 100 != 0)
		return false;
	else
		return false;
}
int ReadNumber() {
	int Number;
	cout << "Enter Number!" << endl;
	cin >> Number;
	return Number;
}
int main()
{
	int Year = ReadNumber();
	if (IsLeapYear(Year)) {
		cout << "\nYes, Year [" << Year << "] is a leap year.\n";
	}
	else {
		cout << "\nNo, Year [" << Year << "] is Not a leap year.\n";
	}
	system("pause>0");
	return 0;

}
