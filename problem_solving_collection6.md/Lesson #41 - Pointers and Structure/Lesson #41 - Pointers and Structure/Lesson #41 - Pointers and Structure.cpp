#include <iostream>
using namespace std;
struct stInfo {
    string name;
    float salary;
};
int main()
{
    stInfo employee, * p;

    employee.name = "leen";
    employee.salary = 1226;

    cout << employee.name << endl;
    cout << employee.salary << endl;

    p = &employee;
    cout << p->name << endl;
    cout << p->salary << endl;
}


