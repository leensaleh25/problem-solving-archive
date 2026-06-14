#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {//12321
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
int ReverseNumber(int Number) { //123,4
    int remaider = 0;
    int Number2 = 0;

    while (Number > 0) {   

        remaider = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + remaider; 

    }
    return Number2;
}
void check(int Number) {
  
        if ( Number== ReverseNumber(Number))
            cout << "Yes, it is a palindrpm number\n";
        else
            cout << "Yes, it is not a palindrpm number\n";
    }

//Abo hadhoud solution

bool isPalindermeNumber(int Number) {
    return  Number == ReverseNumber(Number);
}
int main()
{
    if (isPalindermeNumber(ReadPositiveNumber("Enter number:")))
        cout << "Yes, it is a palindrpm number\n";
    else
        cout << "Yes, it is not a palindrpm number\n";


    /*check( ReadPositiveNumber("Enter number:"));*/
}
