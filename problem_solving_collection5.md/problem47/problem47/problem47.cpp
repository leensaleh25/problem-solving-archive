#include <iostream>
using namespace std;

float ReadNumber(float& Number) {
    cout << "please enter Number:";
    cin >> Number;
    return Number;
}
float GetFraction(float Number) {
    return Number - int(Number);
}
float MyRound(float Number) {
    int inpart;
    inpart = int(Number);
    float FractionsPart = GetFraction(Number);
    if (abs(FractionsPart) >= 0.5) {
        if (Number > 0) 
            return ++inpart;
        else 
           return  --inpart;
        
    }
    else{
        return inpart;
}}
int main()
{
    float Number;
    ReadNumber(Number);
    cout << "\nmy round" << MyRound(Number);
    cout << "\nc++ abs" << round(Number);
}

