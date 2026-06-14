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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);



}
bool IsLastDayInMonth(sDate Date) {

	return Date.Day == NumberOfDayeInMonth(Date.Year, Date.Month);


}
bool IsLastDayInYear(sDate Date) {
	return Date.Month == 12;
}
sDate IncreaseDateByOneDay(sDate Date) {
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
bool IsWeekEnd(sDate Date)
{
	//Weekends are Fri and Sat
	short DayIndex = DayOfWeekOrder(Date.Day, Date.Month,
		Date.Year);
	return (DayIndex == 5 || DayIndex == 6);
}
bool IsBusinessDay(sDate Date)
{

	return !IsWeekEnd(Date);
}
short CalculateVacationDays(sDate DateFrom, sDate DateTo)
{
	int DaysCount = 0;
	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (!IsWeekEnd(DateFrom))
			DaysCount++;
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}
	return  DaysCount;
}
sDate VacationReturn(sDate Date,int Days) {
	short WeekEndCounter = 0;
	while (IsWeekEnd(Date)) {
		Date = IncreaseDateByOneDay(Date);
	}
	for (int i = 1; i <= Days+ WeekEndCounter; i++) {
		if (IsWeekEnd(Date)) {
			WeekEndCounter++;
		}
		Date = IncreaseDateByOneDay(Date);
	}
	while (IsWeekEnd(Date)) {
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

int main()
{
	cout << "Vacation Starts:\n";
	sDate Date = ReadFullDate();
	cout << "Vacation From: " << DayShortName(DayOfWeekOrder(Date)) << " " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	int Days;
	cout << "How Many Days?" << endl;
	cin >> Days;
	sDate VactionDate = VacationReturn(Date, Days);
	cout << "Vacation Date: " << VactionDate.Day << "/" << VactionDate.Month << "/" << VactionDate.Year << endl;



	return 0;
}
