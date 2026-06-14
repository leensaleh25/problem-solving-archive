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
int MyCeil(float Number) {
    if (abs(GetFraction(Number)) > 0) {
        if (Number > 0)
            return int(Number) + 1;
        else
            return Number;
    }
    return Number;
}

int main()
{
    float Number;
    ReadNumber(Number);
    cout << "\nmy ceil " << MyCeil(Number);
    cout << "\nc++ ceil " << ceil(Number);
}

