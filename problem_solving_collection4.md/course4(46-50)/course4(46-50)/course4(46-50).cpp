#include <iostream>
using namespace std;
void PrintLrttersFromAToZ() {
    for (int i = 65; i <= 90; i++) {
        cout << char(i) << endl;
    }
}
float ReadPositiveNumberEdit(string message) {
	float Number;
	do {
		cout << message;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
float TotalMonth(float LoanAmount, float MonthlyInstallment) {
	return LoanAmount / MonthlyInstallment;
}
string ReadPinCode() {
	string pinCode = "1234";
     cout << "Enter your pin code?";
	 cin >> pinCode;
	 return pinCode;
}
bool Login() {
	string pinCode;
	int counter=3;
	do {
		counter--;
		pinCode = ReadPinCode();
		if (pinCode == "1234") 
		{
	 	return 1;
	    }
	  else {
		
		system("color 4F");
		cout << "wrong!\n"<<counter <<"more tries";
	}
	} while (counter>=1 && pinCode != "1234");
	return 0;
}


int main()
{
	
	if (Login()) {
		system("color 2F");
		cout << "\n YourAccount Balance is:" << 7500 << endl;
	}
	else {
		cout << "your code blocked call the bank for help!";
	}
	/*float LoanAmount = ReadPositiveNumberEdit("Please Enter Loan Amount? ");
	float MonthlyInstallment= ReadPositiveNumberEdit("Please Enter Monthly Installment? ");
	cout << "\n Tptal Month to pay =" << TotalMonth(LoanAmount, MonthlyInstallment);*/
    /*PrintLrttersFromAToZ();*/
    return 0;
}
