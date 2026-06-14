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
string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo) {
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos) {
		S1.replace(pos, StringToReplace.length(), sRepalceTo);
		pos = S1.find(StringToReplace);
	}
	return S1;
}
sDate StringToDate(string DateString) {
	sDate Date;
	vector <string>vDate;
	vDate = spliteString(DateString, "/");
	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);
	return Date;
}
string DateToString(sDate Date) {
	return to_string(Date.Day) + " / " + to_string(Date.Month) + " / " + to_string(Date.Year);
}
string ReadStringDate(string Message) {
	string DateString;
	cout << Message;
	getline(cin >> ws, DateString);
	return DateString;
}
string FromateDate(sDate Date, string DateFormate = "dd/mm/yyyy") {
	string FormateDateString = "";
	FormateDateString = ReplaceWordInStringUsingBuiltInFunction(DateFormate, "dd", to_string(Date.Day));
	FormateDateString = ReplaceWordInStringUsingBuiltInFunction(FormateDateString, "mm", to_string(Date.Month));
	FormateDateString = ReplaceWordInStringUsingBuiltInFunction(FormateDateString, "yyyy", to_string(Date.Year));
	return  FormateDateString;

}
int main()
{
	string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? \n");
	sDate Date = StringToDate(DateString);
	cout << "\n" << FromateDate(Date)<<endl;
	cout << "\n" << FromateDate( Date, "yyyy/dd/mm") << endl;
	cout << "\n" << FromateDate(Date, "yyyy-dd-mm") << endl;


}

