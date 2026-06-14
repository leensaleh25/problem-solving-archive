#include <iostream>
using namespace std;
bool IsLeapYear(int year) {
	return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}
short NumberOfDaysInAMonth(short Month, short Year){

	if (Month > 12 || Month < 1)
		return 0;
	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month-1];
}

int ReadNumber(string message) {
	int Number;
	cout << message;
	cin >> Number;
	return Number;
}
int main()
{
	 short year = ReadNumber("Year!");
	 short month = ReadNumber("month!");
     cout << "\nNumber of Days in Month [" << month << "] is " << NumberOfDaysInAMonth(month, year);
	system("pause>0");
	return 0;

}
