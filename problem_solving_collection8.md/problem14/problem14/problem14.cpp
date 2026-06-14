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
bool IsDate1EqualDate2(sDate Date1, sDate Date2) {
	return(Date1.Year == Date2.Year) ?  ((Date1.Month == Date2.Month) ?  ((Date1.Day == Date2.Day) ? true : false):false):false;
}
sDate ReadFullDate() {
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

int main() {
	short Day, Month, Year;
	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();
	if (IsDate1EqualDate2(Date1, Date2)) {
		cout << "YES,Date1 is Equal Date2" << endl;
	}
	else {
		cout << "NO,Date1 is Not Equal than Date2" << endl;
	}
	system("pause>0");
	return 0;
}