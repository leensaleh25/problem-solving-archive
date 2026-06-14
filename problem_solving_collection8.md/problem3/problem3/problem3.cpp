#include <iostream>
using namespace std;
bool IsLeapYear(int year) {
	return (year % 100 != 0 && year % 4 == 0) ||( year % 400 == 0);
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
