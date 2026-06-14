#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
using namespace std;
struct sDate {
	int Day;
	int Month;
	int Year;
};
string ReadStringDate(string Message) {
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}
vector <string>spliteString(string s1, string Delim) {

	short pos = 0;
	string sWord;
	vector<string>vString;

	while ((pos = s1.find(Delim)) != std::string::npos) {
		sWord = s1.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		s1.erase(0, pos + Delim.length());
	}
	if (s1 != "") {
		vString.push_back(s1);
	}
	return vString;
}
sDate StringToDate(string DateString) {
	sDate Date;
	vector <string>vDate;
	vDate = spliteString(DateString, "/");
	Date.Day = stoi(vDate[0]);
	Date.Month= stoi(vDate[1]);
	Date.Year= stoi(vDate[2]);
	return Date;
}
string DateToString(sDate Date) {
	return to_string(Date.Day) + " / " + to_string(Date.Month) + " / " + to_string(Date.Year);
}
int main()
{
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? \n");
	sDate Date = StringToDate(DateString);
	cout << "\nString to date: " << endl;
	cout << "\nDay:" << Date.Day;
	cout << "\nMonth:" << Date.Month;
	cout << "\nYear:" << Date.Year;
	cout << "\nYou Enterd:" << DateToString(Date);
}

