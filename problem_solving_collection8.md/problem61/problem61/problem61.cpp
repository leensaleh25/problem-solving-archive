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
bool IsOverLapPeriod(sPeriod Period1, sPeriod Period2) {
	if (DateCompare(Period2.EndDate, Period1.StartDate) == EnDateCompare::Before || DateCompare(Period2.StartDate, Period1.EndDate) == EnDateCompare::After)
		return false;
	else
		return true;
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
int PeriodLengthInDays(sPeriod Period, bool IncludeEndDay = false) {
	return  GetDifferanceInDay(Period.StartDate, Period.EndDate, IncludeEndDay);
}
bool IsDateInPeriod(sDate Date, sPeriod Period) {
	return!(DateCompare(Date, Period.StartDate) == EnDateCompare::Before || DateCompare(Date, Period.EndDate) == EnDateCompare::After);

}
int CountOverLapDays(sPeriod Period1, sPeriod Period2) {
	int Period1Length = PeriodLengthInDays(Period1,true);
	int Period2Length = PeriodLengthInDays(Period2, true);
	int Counter = 0;
	if (!IsOverLapPeriod(Period1, Period2)) {
		return 0;
	}
	if (Period1Length < Period2Length) {
		while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate)) {
			if (IsDateInPeriod(Period1.StartDate, Period2))
				Counter++;
			Period1.StartDate = IcreaseDateByOneDay(Period1.StartDate);
			}
			}
		
	else {
		while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate)) {
			if (IsDateInPeriod(Period2.StartDate, Period1)) 
				Counter++;
			Period2.StartDate = IcreaseDateByOneDay(Period2.StartDate);
			
		}
	}
	return Counter;

}
int main()
{
	cout << "Enter Period 1:" << endl;
	sPeriod Period1 = ReadPeriod();
	cout << "Enter Period 2:" << endl;
	sPeriod Period2 = ReadPeriod();
	cout << " OverLap Days Count Is: " << CountOverLapDays( Period1,  Period2);
	system("pause>0");
	return 0;
}
