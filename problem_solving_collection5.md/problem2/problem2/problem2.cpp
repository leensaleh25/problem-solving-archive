//print All Prime Number 1 to N
#include <iostream>
#include<string>
using namespace std;

enum enPrime { prime = 1,notPrime = 2 };
int ReadNumber(string Message) {
    int Number = 0;
    do {
    cout << Message << endl;
    cin >> Number;
    } while (Number <= 0);
    return Number;
}
enPrime CheckPrime(int Number) {
    int  m = round(Number / 2);
    for (int i = 2; i <= m; i++) {
        if (Number % i == 0)
            return enPrime::notPrime;
    }
        return enPrime::prime;
}
void PrintResult(int Number) {
    cout << "\n";
    cout << "Prime Numbers form " << 1 << " to " << Number;
    cout << " are: " << endl;
    for (int i = 1; i <= Number; i++) {

    if (CheckPrime(i)==enPrime::prime)
        cout << i<<endl ;
    
}}
int main()
{
    
    PrintResult(ReadNumber("Enter Number:\n"));
}

