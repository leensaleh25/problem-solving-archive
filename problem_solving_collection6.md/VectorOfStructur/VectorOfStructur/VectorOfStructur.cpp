#include <iostream>
#include <vector>
using namespace std;
struct stEmployees{
	string FirstName;
	string LastName;
	float salary;
};

void EnterEmployee(vector <stEmployees>& vEmoloyees) {

	stEmployees Emoloyees;
	char UserInput;
	do{
	cout << "enter your first name?" << endl;
	cin >> Emoloyees.FirstName;
	cout << "enter your first name?" << endl;
	cin >> Emoloyees.LastName;
	cout << "enter your salary?" << endl;
	cin >> Emoloyees.salary;
	vEmoloyees.push_back(Emoloyees);
	cout << "do you want add more?" << endl;
	cin >> UserInput;
	} while (UserInput == 'y' || UserInput == 'Y');
}
void PrintResult(vector <stEmployees> &vEmoloyees) {
	for (stEmployees& Employee : vEmoloyees) {
		cout << "First Name=" << Employee.FirstName << endl;
		cout << "Last Name=" << Employee.LastName << endl;
		cout << "salary=" << Employee.salary << endl;
	}
}



int main()
{
	vector <stEmployees> vEmoloyees;
	EnterEmployee(vEmoloyees);
	PrintResult(vEmoloyees);
	//stEmployees Emoloyees;
	//Emoloyees.FirstName = "leen";
	//Emoloyees.LastName = "saleh";
	//Emoloyees.salary = 10000;
	//vEmoloyees.push_back(Emoloyees);

	//Emoloyees.FirstName = "taleen";
	//Emoloyees.LastName = "saleh";
	//Emoloyees.salary = 2000;
	//vEmoloyees.push_back(Emoloyees);

	//Emoloyees.FirstName = "layan";
	//Emoloyees.LastName = "saleh";
	//Emoloyees.salary = 700;
	//vEmoloyees.push_back(Emoloyees);
 //   
	//for (stEmployees& Employee : vEmoloyees) {
	//	cout << "First Name=" << Employee.FirstName<<endl;
	//	cout << "Last Name=" << Employee.LastName<<endl;
	//	cout << "salary=" << Employee.salary<<endl;
	//}

}
