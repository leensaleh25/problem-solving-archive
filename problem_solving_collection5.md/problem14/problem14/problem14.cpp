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
void pateern(int Number) {
    for (int i = 64 + Number; i >= 65; i--) {
        for (int j = 1; j <= Number-(64 + Number - i); j++) {
            cout << char(i);
        }
        cout << "\n";
 }
}
void pateern1(int Number) {
    for (int i = 1; i <=Number ; i++) {
        for (int j = 65; j <= i + 64; j++) {
            cout << char(j);
        }
        cout << "\n";
    }
}
void pateern0(int Number) {
    for (int i = 65; i <= 64+Number; i++) {
        for (int j = 1; j <= i -65+1; j++) {
            cout << char(i);
        }
        cout << "\n";
    }
}
int main()
{
    pateern0(ReadPositiveNumber("enter number"));
}
