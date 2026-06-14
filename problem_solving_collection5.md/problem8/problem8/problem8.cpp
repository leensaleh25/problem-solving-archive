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
int CountDigitFrquency(int Number1,short DigitToCheck) {
    int remaider = 0;
    int FreqCount = 0;
    while (Number1 > 0) {
        remaider = Number1 % 10;
        Number1 = Number1 / 10;
        if (remaider == DigitToCheck)
            FreqCount += 1;
    }
    return FreqCount;
}

void PrintAllCountDigitFrquency(int Number1) {
    int DigitFerq = 0;
    for (int i = 1; i < 10; i++) {
        DigitFerq= CountDigitFrquency(Number1, i);
      
  
    if (DigitFerq > 0) {
        cout <<i<<"Frequency is" << DigitFerq << endl;
     }  }

}
int main()
{
   
    
    PrintAllCountDigitFrquency(ReadPositiveNumber("Please Enter Number:"));
   /* int Number1 = ReadPositiveNumber("Please Enter Number:");
     short DigitToCheck = ReadPositiveNumber("Please Enter Number:");
    cout <<"Digit " << DigitToCheck << " Frequency is " << CountDigitFrquency(Number1, DigitToCheck);*/

}
