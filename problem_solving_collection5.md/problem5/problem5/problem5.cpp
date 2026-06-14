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
void PrintDigits(int Number) {
    int remaider = 0;
    while (Number > 0) {
        remaider = Number % 10;
        Number = Number / 10;
        cout << remaider<<endl;
    }

}

int SumOFDigits(int Number) {
    int remaider = 0;
    int Sum = 0;
    while (Number > 0) {
        remaider = Number % 10;
        Number = Number / 10;
        Sum += remaider;
        
    }
    return Sum;

}

int ReverseNumber(int Number) {
    int remaider = 0;
    int Number2 = 0;
  
    while (Number > 0) {

        remaider = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + remaider;
        
    }
    return Number2;
}
int main()
{
    
   /*PrintDigits(ReadPositiveNumber("Enter Number:"));*/
   cout<<"Reverse is= "<< ReverseNumber(ReadPositiveNumber("Enter Number:"));
  /*cout<< "sum of digits = "<<SumOFDigits(ReadPositiveNumber("Enter Number:"));*/
   
 
}


