#include <iostream>
#include<string>
#include <ctime> 
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
bool IsLastDayInMonth(sDate Date) {

	return Date.Day == NumberOfDayeInMonth(Date.Year, Date.Month);


}
bool IsLastDayInYear(sDate Date) {
	return Date.Month == 12;
}
sDate ReadFullDate() {
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
	if (Date1.Year < Date2.Year) {
		return true;
	}
	else if (Date1.Year == Date2.Year) {
		if (Date1.Month < Date2.Month) {
			return true;
		}
		else if (Date1.Month == Date2.Month) {
			if (Date1.Day < Date2.Day) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;

}
sDate IcreaseDateByOneDay(sDate Date) {
	if (IsLastDayInMonth(Date)) {
		if (IsLastDayInYear(Date)) {

			Date.Month = 1;
			Date.Day = 1;
			Date.Year += 1;
		}
		else {
			Date.Day = 1;
			Date.Month += 1;
		}
	}
	else {
		Date.Day += 1;
	}
	return Date;

}
int GetDifferanceInDay(sDate Date1, sDate Date2, bool IncludeEndDay = false) {
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2)) {
		Days++;
		Date1 = IcreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days : Days;
}
sDate GetSystemDate() {
	sDate Date;
	time_t t = time(0);
	tm now;
	localtime_s(&now, &t); 

	Date.Year = now.tm_year + 1900;
	Date.Month = now.tm_mon + 1;
	Date.Day = now.tm_mday;
	return Date;
}
int main() {
	cout << "Please Enter Your Date Of Birth:\n";
	sDate Date1 = ReadFullDate();
	sDate Date2 = GetSystemDate();
	cout << "\n Your Age is: " << GetDifferanceInDay(Date1, Date2, true) << " Day(S).";
	system("pause>0");
	return 0;
}
