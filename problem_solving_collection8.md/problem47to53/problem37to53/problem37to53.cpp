#include <iostream>
#include<string>
#pragma warning(disable : 4996);
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
sDate ReadFullDate() {
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}
bool IsLeapYear(int year) {
	return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
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
short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
		/ 12)) % 7;
}
short DayOfWeekOrder(sDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}
string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = {
	"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];
}
short IsEndOfWeek(sDate Date) {
	return DayOfWeekOrder(Date)==6;	
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
bool IsLastDayInMonth(sDate Date) {

	return Date.Day == NumberOfDayeInMonth(Date.Year, Date.Month);


}
bool IsLastDayInYear(sDate Date) {
	return Date.Month == 12;
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
bool IsWeekEnd(sDate Date) {
	short  DayIndex = DayOfWeekOrder(Date.Day, Date.Year, Date.Month);
	return(DayIndex == 7|| DayIndex == 6);

}
bool IsBusinessDay(sDate Date) {
	return(!IsWeekEnd(Date));
}
int DayesUntilTheEndOfWeek(sDate Date) {
	return 6- DayOfWeekOrder(Date);

}
int DayesUntilTheEndOfMonth(sDate Date1) {
	sDate EndOfMonth;
	EndOfMonth.Day = NumberOfDayeInMonth(Date1.Year,Date1.Month);
	EndOfMonth.Month = Date1.Month;
	EndOfMonth.Year = Date1.Year;
	return GetDifferanceInDay(Date1, EndOfMonth, true);
	
}
int DayesUntilTheEndOfYear(sDate Date1) {
	sDate EndOfYear;
	EndOfYear.Day = 31;
	EndOfYear.Month = 12;
	EndOfYear.Year = Date1.Year;
	return GetDifferanceInDay(Date1, EndOfYear, true);

}
int main()
{
	sDate Date1 = GetSystemDate();
	string Todayis = DayShortName(DayOfWeekOrder(Date1));
	
	cout << "Today is "<< Todayis <<" " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	cout << "-------------------------------\n";
	cout << "Is it End of Week?" << endl;
	if (IsEndOfWeek(Date1))
		cout << "YES it is Saturday,it`s end of Week." << endl;
	else
		cout << "NO it`s Not end of Week." << endl;

	cout << "-------------------------------\n";
	if(IsWeekEnd(Date1))
		cout << "YES it is Week end." << endl;
	else
		cout << "NO Today is " << Todayis <<" it`s Not Week end."<< endl;
	cout << "-------------------------------\n";
	if (IsBusinessDay(Date1))
		cout << "Yes,it is a Business Day" << endl;
	else
		cout << "No,it is Not a Business Day" << endl;
	cout << "-------------------------------\n";
	cout << "Dayes Until The End Of Week:" << DayesUntilTheEndOfWeek(Date1)<<endl;
	cout << "-------------------------------\n";
	cout << "Dayes Until The End Of Month:" << DayesUntilTheEndOfMonth(Date1)<<endl;
	cout << "-------------------------------\n";
	cout << "Dayes Until The End Of year:" << DayesUntilTheEndOfYear(Date1) << endl;
}

