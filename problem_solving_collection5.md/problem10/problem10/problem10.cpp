
#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
int ReverseNumber(int Number) {//1234
    int remaider = 0;
    int Number2 = 0;

    while (Number > 0) {

        remaider = Number % 10;//4
        Number = Number / 10;
        Number2 = Number2 * 10 + remaider;

    }
    return Number2;
}
void PrintDigits(int Number) {//1234
    int remaider = 0;
    while (Number > 0) {
        remaider = Number % 10;
        Number = Number / 10;
        cout << remaider << endl;//4321
    }

}
int main()
{
    PrintDigits(ReverseNumber(ReadPositiveNumber("Enter Number:")));
}

