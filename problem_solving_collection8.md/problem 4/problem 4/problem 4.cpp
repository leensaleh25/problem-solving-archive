#include <iostream>
using namespace std;
bool IsLeapYear(int year) {
	return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}

int Days(int year) {
	
	return IsLeapYear(year) ? 366 : 365;
	
}
int Houes(int year) {
	
	return Days(year) * 24;
}
int Min(int year) {
	return Houes(year) * 60;
}
int Second(int year) {
	return Min(year) * 60;
}
int ReadNumber() {
	int Number;
	cout << "Enter Number!" << endl;
	cin >> Number;
	return Number;
}
int main()
{
	int Year = ReadNumber();
	cout << "\nNumber of Days    in Year [" << Year << "] is " << Days(Year);    
	cout << "\nNumber of Hours   in Year [" << Year << "] is " <<Houes(Year);
	cout << "\nNumber of Minutes in Year [" << Year << "] is " <<Min(Year);
	cout << "\nNumber of Seconds in Year [" << Year << "] is " <<Second(Year);
	system("pause>0");
	return 0;

}
