#include <iostream>
using namespace std;

float ReadNumber(int &Number) {
    cout << "please enter Number:";
    cin >> Number;
    return Number;
}
int Myabs(int Number) {

    if (Number < 0) {
        return Number * -1;
    }
    else {
        return Number;
    }

}
int main()
{
    int Number;
    ReadNumber(Number);
   cout<<"\nmy abs" << Myabs(Number);
   cout<<"\nc++ abs"<< abs(Number);
}

