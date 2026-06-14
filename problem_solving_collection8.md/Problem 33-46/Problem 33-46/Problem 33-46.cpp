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
bool IsFirstDayInMonth(sDate Date) {

	return Date.Day == 1;


}
bool IsFirstDayInYear(sDate Date) {
	return Date.Month == 1;
}
sDate ReadFullDate() {
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}
sDate  DecreaseDateByOneDay(sDate Date) {
	if (IsFirstDayInMonth(Date)) {
		if (IsFirstDayInYear(Date)) {

			Date.Month = 12;
			Date.Day = 31;
			Date.Year -= 1;
		}
		else {
			Date.Month--;
			Date.Day = NumberOfDayeInMonth(Date.Year, Date.Month);
					
		}
	}
	else {
		Date.Day -= 1;
	}
	return Date;

}
sDate DecreaseDateByXDays(int x, sDate Date) {

	for (int i = 1; i <= x; i++) {
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}
sDate DecreaseDateByOneWeek(sDate Date) {

	for (int i = 1; i <= 7; i++) {
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}
sDate DecreaseDateByXWeek(int x, sDate Date) {
	for (int i = 1; i <= x; i++) {
		Date = DecreaseDateByOneWeek(Date);

	}
	return Date;
}
sDate DecreaseDateByOneMonth(sDate Date) {
	if (Date.Month == 1) {
		Date.Month = 12;
		Date.Year--;
	}
	else {
		Date.Month -= 1;
	}

	return Date;

}
sDate DecreaseDateByXMonth(int x, sDate Date) {
	for (int i = 1; i <= x; i++) {
		Date = DecreaseDateByOneMonth(Date);

	}
	return Date;
}
sDate DecreaseDateByOneYear(sDate Date) {
	Date.Year--;
	return Date;
}
sDate DecreaseDateByXYear(int x, sDate Date) {
	for (int i = 1; i <= x; i++) {
		Date = DecreaseDateByOneYear(Date);

	}
	return Date;
}
sDate DecreaseDateByXYearFaster(int x, sDate Date) {
	Date.Year -= x;
	return Date;
}
sDate DecreaseDateByDecode(sDate Date) {
	Date.Year -= 10;
	return Date;
}
sDate DecreaseDateByXDecodes(int x, sDate Date) {
	for (int i = 1; i <= x; i++) {
		Date = DecreaseDateByDecode(Date);
	}

	return Date;
}
sDate DecreaseDateByXDecodesFaster(int x, sDate Date) {
	Date.Year -= 10 * x;

	return Date;
}
sDate DecreaseDateByCentury(sDate Date) {
	//100 Years
	Date.Year -= 100;
	return Date;

}
sDate DecreaseDateByMillennium(sDate Date) {
	//100 Years
	Date.Year -= 1000;
	return Date;

}

int main()
{
	short Day, Month, Year;
	sDate Date = ReadFullDate();
	cout << "Data After:\n";
	Date = DecreaseDateByOneDay(Date);
	cout << "01-Subtracting one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXDays(10, Date);
	cout << "02-Subtracting 10 day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneWeek(Date);
	cout << "03-Subtracting one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXWeek(10, Date);
	cout << "04-Subtracting 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneMonth(Date);
	cout << "05-Subtracting 1 Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXMonth(5, Date);
	cout << "06-Subtracting 5 Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneYear(Date);
	cout << "07-Subtracting One Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXYear(10, Date);
	cout << "08-Subtracting 10 Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXYearFaster(10, Date);
	cout << "09-Subtracting 10 Year(Faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByDecode(Date);
	cout << "10-Subtracting Decode is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXDecodes(10, Date);
	cout << "11-Subtracting 10 Decodes is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXDecodesFaster(10, Date);
	cout << "12-Subtracting 10 Decodes(Faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByCentury(Date);
	cout << "13-Subtracting one Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByMillennium(Date);
	cout << "14-Subtracting one Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

