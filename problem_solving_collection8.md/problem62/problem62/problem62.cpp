#include <iostream>
#include<string>
using namespace std;
struct sDate {
	int Day;
	int Month;
	int Year;
};
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
bool IsLeapYear(int year) {
	return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
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
bool IsValidDate(sDate Date) {
	if (Date.Day < 1 || Date.Day > 31) 
		return false;
	if (Date.Month < 1 || Date.Month>12)
		return false;
	if (Date.Year == 2) {
		if (IsLeapYear(Date.Day)) {
			if (Date.Day > 29)
				return false;
		}
		else {
			if (Date.Day > 28)
				return false;
		}
	}
	
	 if (Date.Day > NumberOfDayeInMonth(Date.Year, Date.Month))
		return false;
	 return true;

}
sDate ReadFullDate() {
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}
int main()
{
	sDate Date = ReadFullDate();
	if (IsValidDate(Date)) {
		cout << "YES, It Is Valid Date";
	}
	else {
		cout << "NO, It Is Not Valid Date";
	}

}
