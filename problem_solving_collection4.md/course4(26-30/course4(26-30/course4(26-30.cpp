#include <iostream>
#include<string>
using namespace std;
int ReadNumber() {
    int Number;
    cout << "Enter number:\n";
    cin >> Number;
    return Number;
}
void PrintRangeFrom1toN_UsingWhile(int N) {
    int Counter=0;
    cout<< "Range printed using while statment:\n";

    while (Counter < N)
    {
       Counter++;
       cout << Counter<<endl;
    }  
}
void PrintRangeFrom1T0N_UsingDoWhile(int N) {
    int Counter = 0;
    cout << "Range printed using while statment:\n";
    do {
        Counter++;
        cout << Counter << endl;
    } while (Counter < N);
}
void PrintRangeFrom1toN_UsingFor(int N) {
    
    cout << "Range printed using while statment:\n";
    for (int Counter=1; Counter <=N; Counter++) {
        cout << Counter << endl;
    }
}


void Print1To10For(int N) {
    cout << "Range printed using For statment:\n";
    for (int i = N;  i>= 1; i--) {
        cout << i << endl;
    }
}
void Print1To10While(int N) {
    cout << "Range printed using while statment:\n";
    int Counter = N;
    while (Counter>= 1) {
        cout << Counter << endl;
        Counter--;
    }     
}
void Print1To10DoWhile(int N) {
    cout << "Range printed using do while statment:\n";
    int Counter = N;
    do {
        cout << Counter << endl;
        Counter--;
    } while (Counter >= 1);
}


enum enOddOrEven{odd=1,even=2};
enOddOrEven CheckOddOrEven(int Number) {
    if (Number % 2 != 0)
        return enOddOrEven::odd;
    else
        return enOddOrEven::even;
}
int SumOddNumbersFor(int N) {
    
    int sum=0;
    for (int Counter = 1; N >= Counter; Counter++) {
        if (CheckOddOrEven(Counter) == enOddOrEven::even)
             sum += Counter;
        
    }
    return sum;
}
int SumOddNumbersWhile(int N) {
    int Counter = 0;
    int sum = 0;
    while (Counter <= N) {
        
        if (CheckOddOrEven(Counter) == enOddOrEven::even) {
            sum += Counter;
        }
     Counter++;
    }
    return sum;
}
int SumOddNumbersDo(int N) {
    int Counter = 0;
    int sum = 0;
    do {
        if (CheckOddOrEven(Counter) == enOddOrEven::even) {
            sum += Counter;
        }
        Counter++;
    } while (Counter <= N);
    return sum;
}

int ReadPositiveNumber(string Message) {
    int Number;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);
    return Number;
}
int Factorial(int N) {
    int Counter = 1;
    for (int i = N; i >= 1; i--) {
        Counter *= i;
    }
    return Counter;
}
int main()
{
    string Message;
  cout<< Factorial(ReadPositiveNumber("enter n:"));
   /* int Number;
    int N= ReadNumber();
   cout<< SumOddNumbersFor(N)<<endl;
   cout << SumOddNumbersWhile(N)<<endl;
   cout << SumOddNumbersDo(N) << endl;*/
   /* Print1To10For(N);
    Print1To10While(N);
    Print1To10DoWhile(N);*/
  
    /*PrintRangeFrom1toN_UsingWhile(N);
    PrintRangeFrom1T0N_UsingDoWhile(N);
    PrintRangeFrom1toN_UsingFor(N);*/
    return 0;
}
