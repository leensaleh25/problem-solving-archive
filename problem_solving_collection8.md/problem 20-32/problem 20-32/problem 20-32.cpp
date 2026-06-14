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
sDate IcreaseDateByXDays(int x,sDate Date) {

	for (int i = 1; i <= x; i++) {
		Date =IcreaseDateByOneDay(Date);
	}
	return Date;
}
sDate IcreaseDateByOneWeek( sDate Date) {
	
	for (int i = 1; i <= 7; i++) {
		Date = IcreaseDateByOneDay(Date);
	}
	return Date;
}
sDate IcreaseDateByXWeek(int x, sDate Date) {
	for (int i = 1; i <= x; i++) {
		Date = IcreaseDateByOneWeek(Date);
		
	}
	return Date;
}
sDate IcreaseDateByOneMonth( sDate Date) {
	if (Date.Month == 12) {
		Date.Month = 1;
		Date.Year++;
	}
	else {
		Date.Month += 1;
	}
	
	return Date;
	
}
sDate IcreaseDateByXMonth(int x,sDate Date) {
	for (int i = 1; i <= x; i++) {
		Date = IcreaseDateByOneMonth(Date);

	}
	return Date;
}
sDate IcreaseDateByOneYear( sDate Date) {
	Date.Year++;
	return Date;
}
sDate IcreaseDateByXYear(int x, sDate Date) {
	for (int i = 1; i <= x; i++) {
		Date = IcreaseDateByOneYear(Date);

	}
	return Date;
}
sDate IcreaseDateByXYearFaster(int x, sDate Date) {
	Date.Year += x;
	return Date;
}
sDate IcreaseDateByDecode( sDate Date) {
	Date.Year += 10;
	return Date;
}
sDate IcreaseDateByXDecodes(int x,sDate Date) {
	for (int i = 1; i <= x; i++) {
		Date = IcreaseDateByDecode(Date);
	}
	
	return Date;
}
sDate IcreaseDateByXDecodesFaster(int x, sDate Date) {
	Date.Year += 10*x;

	return Date;
}
sDate IcreaseDateByCentury(sDate Date) {
//100 Years
	Date.Year += 100;
	return Date;

}
sDate IcreaseDateByMillennium(sDate Date) {
	//100 Years
	Date.Year += 1000;
	return Date;

}

int main()
{
	short Day, Month, Year;
	sDate Date = ReadFullDate();
	cout << "Data After:\n";
	 Date = IcreaseDateByOneDay(Date);
	cout << "01-Adding one day is: "<<Date.Day<<"/"<<Date.Month << "/"<<Date.Year<<endl;
	 Date = IcreaseDateByXDays(10, Date);
	cout << "02-Adding 10 day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IcreaseDateByOneWeek(Date);
	cout << "03-Adding one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IcreaseDateByXWeek(10,Date);
	cout << "04-Adding 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date= IcreaseDateByOneMonth(Date);
	cout << "05-Adding 1 Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IcreaseDateByXMonth(5,Date);
	cout << "06-Adding 5 Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IcreaseDateByOneYear(Date);
	cout << "07-Adding One Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date= IcreaseDateByXYear(10, Date);
	cout << "08-Adding 10 Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IcreaseDateByXYearFaster(10, Date);
	cout << "09-Adding 10 Year(Faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IcreaseDateByDecode(Date);
	cout << "10-Adding Decode is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IcreaseDateByXDecodes(10,Date);
	cout << "11-Adding 10 Decodes is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date=IcreaseDateByXDecodesFaster(10, Date);   
	cout << "12-Adding 10 Decodes(Faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IcreaseDateByCentury(Date);
	cout << "13-Adding one Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IcreaseDateByMillennium(Date);
	cout << "14-Adding one Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

