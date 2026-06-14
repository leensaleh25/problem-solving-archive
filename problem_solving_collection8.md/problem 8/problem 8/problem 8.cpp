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
short DayOfWeekOrder(short Day, short Month, short Year) {
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayShortName(short DayOfWeekOrder) {
	string days[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return  days[DayOfWeekOrder];
}
string MonthShortName(short MonthNumber) {
	string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return Months[MonthNumber - 1];
}
void PrintMonthCalendar(short Month, short Year) {
	int NumberOfDay;
	int Current = DayOfWeekOrder(1, Month, Year);
	NumberOfDay = NumberOfDayeInMonth(Year, Month);

	printf("\n----------------------------%s----------------------------\n\n",MonthShortName(Month).c_str());
	printf("  Sun   Mon   Tue   Wed   Thu   Fri   Sat \n");
	int i;
	for (i = 0; i < Current; i++) {
		printf("      ");
	}
	for (int j = 1; j <= NumberOfDay; j++) {
		printf("%5d", j);
		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	printf("\n-----------------------------------------------------------\n");
		
}
int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	PrintMonthCalendar(Month, Year);
}

