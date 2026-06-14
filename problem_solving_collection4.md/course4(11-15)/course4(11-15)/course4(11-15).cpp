#include <iostream>
using namespace std;
void ReadNumber(int &num1, int &num2, int &num3) {
    cout << "Enter number 1:\n";
    cin >> num1;
    cout << "Enter number 2:\n";
    cin >> num2;
    cout << "Enter number 3:\n";
    cin >> num3;
}
int CheckNumber(int num1, int num2,int num3) {
    if (num1 > num2)//1 2 4
        if (num1 > num3)
            return num1;
        else
            return num3;
    else
        if (num2 > num3)
            return num2;
        else
            return num3;
}
void PrintResult(int max) {
    cout << "\n the max number is :" <<max<< endl;
}
void ReadNumber0(int& num1, int& num2) {
    cout << "Enter number 1:\n";
    cin >> num1;
    cout << "Enter number 2:\n";
    cin >> num2;
   
}
int Swap(int &a,int &b){
    int temp;//1 2
    temp = a;//2
    a= b;//1
    b = temp;
    return a, b;
}
void Print(int num1, int num2) {
    cout << "swap result " << "\n number 1= " << num1 << "\n number 2=" << num2 << endl;
}

int main()
{
    int num1;
    int num2;
    int a, b;
    ReadNumber0(num1, num2);
    Print(num1, num2);
    Swap(num1, num2);
    Print(num1, num2);
    /*nt num1;
    int num2;
    int num3;
    ReadNumber(num1, num2,num3);
    PrintResult(CheckNumber(num1, num2,num3));*/
    
}


