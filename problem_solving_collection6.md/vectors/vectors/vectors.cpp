#include<vector>
#include <iostream>
using namespace std;

void EnterNumbers(vector <int>& VNumber)
{
	int Number;
	char UserInput;
	do{
	cout << "enter a number?" << endl;
	cin >> Number;
	VNumber.push_back(Number);
	cout << "do you want add mor numbers?\n";
	cin>> UserInput;
	} while (UserInput == 'Y' || UserInput == 'y');
}

void PrintNumbers(vector <int>& VNumber) {
	for (int Number : VNumber) {
		cout << Number<<" ";
	}
}
int main()
{
	int Number;
	vector <int> vNumber;
	EnterNumbers(vNumber);
	PrintNumbers(vNumber);
	//vector <int> vNumber = { 1,2,3,4,5};
	////ranged loop
	//for (int &number : vNumber) {
	//	cout << number << endl;
	//}

	//vector <int> VNumber;
	//VNumber.push_back(10);
	//VNumber.push_back(20);
	//VNumber.push_back(30);

	//for (int& number : VNumber) {
	//	cout << number << " ";
	//}

}
