#include <iostream>
#include <iomanip>
#include<string>
using namespace std;
struct sDate {
	int Day;
	int Month;
	int Year;
};
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
	int TotalNumberOfDay = 0;
	for (short i = 1; i <= Month - 1; i++) {
		TotalNumberOfDay += NumberOfDayeInMonth(Year, i);
	}
	TotalNumberOfDay += Day;
	return  TotalNumberOfDay;
}
sDate DateOfYear(int NumberOfDayes, int year) {
	int Days = 1;
	int Month = 1;
	for (int i = 1; i < NumberOfDayes; i++) {
		if (Days != NumberOfDayeInMonth(year, Month)) {
			Days += 1;
		}
		else {
			Month += 1;
			Days = 1;
		}

	}
	sDate d;
	d.Day = Days;
	d.Month = Month;
	d.Year = year;
	return d;

}
int  NumberOfDay() {
	int Number;
	cout << "Number To Add?\n";
	cin >> Number;
	return Number;
}

sDate DateAfterAdding(sDate Dates, int NumberOfDateTAdd, int year) {
	
	for (int i = 1; i <=NumberOfDateTAdd; i++) {
		if (Dates.Day != NumberOfDayeInMonth(year, Dates.Month)) {
			Dates.Day += 1;
			if (Dates.Month > 12) {
				Dates.Year += 1;
				Dates.Month = 1;
				
			}
		}
		else {
			Dates.Month += 1;
			Dates.Day = 1;
		}
        
	}

	
	return Dates;
	
}
int main(){

	short Day = ReadDay();
	short Month = ReadMonth();
	int Year = ReadYear();
	int NumberOfDaysToAdd = NumberOfDay();
	int NumberOfDayes = NumberOfDayesFromBeginingOfTheYear(Day, Month, Year);
	cout << "Number Of Dayes From Begining Of The Year is " << NumberOfDayes;
	sDate result = DateOfYear(NumberOfDayes, Year);
	cout << "\nDate of " << "[" << NumberOfDayes << "]" << "is " << result.Day << "/" << result.Month << "/" << result.Year<<endl;
	sDate sd =DateAfterAdding(result,NumberOfDaysToAdd, Year);
	cout << "Date After Adding" << sd.Day << "/" << sd.Month << "/" << sd.Year<<endl;
	system("pause>0");
	return 0;

}

