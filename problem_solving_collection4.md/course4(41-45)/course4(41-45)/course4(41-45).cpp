#include <iostream>
using namespace std;
enum enDayWeek{sat=1,sun=2,mon=3,tue=4,wed=5,thu=6,fri=7};

int ReadNumberInRange(string Message, int From, int To) {
	int Number;
	do {
	cout << Message << endl;
	cin >> Number;
	return Number;
	} while (Number<From || Number>To);
	return Number;
}
enDayWeek ReadDayOfWeek() {
	return (enDayWeek)ReadNumberInRange("Enter day Number:\n",1,7);

}
string GetDayOfWeek(enDayWeek Day) {
	switch (Day)
	{
	case enDayWeek::sat:
		return "saturday";
	case enDayWeek::sun:
		return "sunday";
	case enDayWeek::mon:
		return "monday";
	case enDayWeek::tue:
		return "tuesday";
	case enDayWeek::wed:
		return "wednesday";
	case enDayWeek::thu:
		return "thursday";
	case enDayWeek::fri:
		return "friday";
	default:
		return "not avalid day:(";
	}
}
int main()
{
	cout<<GetDayOfWeek(ReadDayOfWeek())<<endl;
	return 0;
}

