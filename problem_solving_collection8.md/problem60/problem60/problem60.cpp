#include <iostream>
#include<string>
using namespace std;
struct sDate {
	int Day;
	int Month;
	int Year;
};
struct sPeriod {
	sDate StartDate;
	sDate EndDate;
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
enum EnDateCompare { Before = -1, Equal = 0, After = 1 };

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsDate1EqualDate2(sDate Date1, sDate Date2) {
	return(Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}
bool IsDate1AfterDate2(sDate Date1, sDate Date2) {
	return(!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}
EnDateCompare DateCompare(sDate Date1, sDate Date2) {
	if (IsDate1BeforeDate2(Date1, Date2)) {
		return  EnDateCompare::Before;
	}
	else if (IsDate1EqualDate2(Date1, Date2)) {
		return  EnDateCompare::Equal;
	}
	else {
		return  EnDateCompare::After;
	}
}
sPeriod ReadPeriod() {
	sPeriod Period;
	cout << "Enter Start Date:\n";
	Period.StartDate = ReadFullDate();
	cout << "Enter End Date:\n";
	Period.EndDate = ReadFullDate();
	return Period;
}
bool IsDateInPeriod(sDate Date, sPeriod Period) {
	return!(DateCompare(Date, Period.StartDate) == EnDateCompare::Before || DateCompare(Date, Period.EndDate) == EnDateCompare::After);
	
}
int main()
{
	cout << "Enter Period 1:" << endl;
	sPeriod Period = ReadPeriod();
	cout << "Enter Date:";
	sDate Date = ReadFullDate();
	if (IsDateInPeriod(Date, Period))
		cout << "Yes , Date in the Period .\n";
	else
		cout << "No , Do Not in the Period .\n";

	system("pause>0");
	return 0;
}
