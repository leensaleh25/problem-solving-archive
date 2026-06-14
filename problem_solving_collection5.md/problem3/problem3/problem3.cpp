#include <iostream>
using namespace std;
enum enPerfectNumber{Perfect=1,NotPerfect=2};
int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

enPerfectNumber CheckPerfectNumbers(int Number) {
    int Sum = 0;
    for (int i = 1; i < 28; i++) {
        if (Number % i == 0) {
            Sum += i;
        } }
        if (Sum == Number)
            return enPerfectNumber::Perfect;

        else
            return  enPerfectNumber::NotPerfect;
   
}
void PrintResult(int Number) {
    if (CheckPerfectNumbers(Number)==enPerfectNumber::Perfect)
        cout << Number << "  is a perfect Number.\n";
    else
        cout << Number << "  is Not a perfect Number.\n";
}
// Abo-hadhoud solution
bool IsPerfectNumber(int Number) {
    int Sum = 0;
    for (int i = 1; i < Number; i++) {
        if (Number % i == 0) {
            Sum += i;
        }
    }
    return Number == Sum;
}
bool AllPerfectNumber(int Number) {
    int Sum = 0;
    for (int i = 1; i < Number; i++) {
        if (Number % i == 0) {
            Sum += i;
        }
    }
    return Number == Sum;
}
void  PrintAllPerfectNumber(int Number) {
    for (int i = 1; i <= Number; i++) {
        if (AllPerfectNumber(i)) {
            cout << i << endl;
        }
    }
}
void PrintResultA(int Number) {
    if (IsPerfectNumber(Number)) 
        cout << Number << "  is a perfect Number.\n";
    else
        cout << Number << "  is Not a perfect Number.\n";
}

int main()
{
    PrintAllPerfectNumber(ReadPositiveNumber("Enter Number:"));
    //PrintResult(ReadPositiveNumber("Please Enter Number?\n"));
    /*PrintResultA(ReadPositiveNumber("Please Enter Number?\n"));*/
    return 0;
}

