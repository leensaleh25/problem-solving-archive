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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
	if (Date1.Year < Date2.Year) {
		return true;
	}
	else if(Date1.Year == Date2.Year) {
		if (Date1.Month < Date2.Month) {
			return true;
		}
		else if(Date1.Month == Date2.Month) {
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
sDate ReadFullDate( ) {
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
	if (IsDate1BeforeDate2(Date1, Date2)) {
		cout << "YES,Date1 is less than Date2"<<endl;
	}
	else {
		cout << "NO,Date1 is Not less than Date2" << endl;
	}
	return 0;
}