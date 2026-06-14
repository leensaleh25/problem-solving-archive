#include <iostream>
using namespace  std;

void PrintFibonacciUsingLoop(short Number) {
    short Prev1 = 1;
    short Prev2 = 0;
    int Fibonacci = 0;
    cout << "1   ";
    for (int i=2; i <= Number; i++) {
        
        Fibonacci=Prev1 + Prev2;
        cout << Fibonacci << "  ";
        Prev2 = Prev1; 
        Prev1 = Fibonacci;
    }
 


}

int main()
{
    PrintFibonacciUsingLoop(10);
}

