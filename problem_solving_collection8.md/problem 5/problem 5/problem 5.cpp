#include <iostream>
using namespace std;
bool IsLeapYear(int year) {
	return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}
int Days(int year,int month) {
	if (month > 12 || month < 1) 
		return 0;
	if (month == 2) {
		return IsLeapYear(year) ? 29 : 28;
	}
	int arr31Days[7] = { 1,3,5,7,8,10,12 };
	for (int i = 1; i <= 7; i++) {
		if (arr31Days[i-1] == month)
			return 31;		
	}
		return 30;
	
}
int Houes(int year, int month) {
	
	return Days(year,month) * 24;
}
int Min(int year, int month) {
	return Houes(year, month) * 60;
}
int Second(int year, int month) {
	return Min(year, month) * 60;
}
int ReadNumber(string message) {
	int Number;
	cout << message;

	cin >> Number;
	return Number;
}
int main()
{
	int year = ReadNumber("Year!");
	int month = ReadNumber("month!");
	cout << "\nNumber of Days    in Year [" << month << "] is " << Days(year,month);
	cout << "\nNumber of Hours   in Year [" << month << "] is " << Houes(year, month);
	cout << "\nNumber of Minutes in Year [" << month << "] is " << Min(year, month);
	cout << "\nNumber of Seconds in Year [" << month << "] is " << Second(year, month);
	system("pause>0");
	return 0;

}
