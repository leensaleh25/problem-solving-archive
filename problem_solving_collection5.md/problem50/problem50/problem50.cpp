#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber(float& Number) {
    cout << "please enter Number:";
    cin >> Number;
    return Number;
}
float MySqrt(float Number) {
    return pow(Number, 0.5);
}

int main()
{
    float Number;
    ReadNumber(Number);
    cout << "\nmy sqrt " << MySqrt(Number);
    cout << "\nc++ sqrt " << sqrt(Number);
}

