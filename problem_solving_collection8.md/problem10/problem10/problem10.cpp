#include <iostream>
#include <iomanip>
#include<string>
using namespace std;
bool IsLeapYear(int year) {
	return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}
short ReadYear() {
	short Year;
	cout << "\nPlease enter a Year? ";
	cin >> Year;
	return Year;
}
short ReadMonth() {
	short Month;
	cout << "\nPlease enter a Month? ";
	cin >> Month;
	return Month;
}
short ReadDay() {
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}
int NumberOfDayeInMonth(int year, int month) {
	if (month > 12 || month < 1)
		return 0;
	if (month == 2) {
		return IsLeapYear(year) ? 29 : 28;
	}
	int arr31Days[7] = { 1,3,5,7,8,10,12 };
	for (int i = 1; i <= 7; i++) {
		if (arr31Days[i - 1] == month)
			return 31;
	}
	return 30;

}
int NumberOfDayesFromBeginingOfTheYear(short Day, short Month, short Year) {
	int TotalNumberOfDay=0;
	for (short i = 1; i <= Month-1; i++) {
		TotalNumberOfDay+= NumberOfDayeInMonth(Year, i);
	}
	TotalNumberOfDay += Day;
	return  TotalNumberOfDay;
}
int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	cout<<"Number Of Dayes From Begining Of The Year is "<< NumberOfDayesFromBeginingOfTheYear(Day, Month, Year);
	system("pause>0");
	return 0;

}



