
#include <iostream>
using namespace std;

class clsPerson {
public:
	string Firstname;
	string Lastname;
	string fullName() {
		return Firstname + " " + Lastname;
	}
};
int main()
{
	clsPerson person1;
	person1.Firstname = "Leen";
	person1.Lastname = "Saleh";
	cout << person1.fullName()<<endl;
}

