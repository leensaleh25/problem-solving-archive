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
void Print(int Number) {
    for (int i = Number; i >=1; i--) {
        cout << "\n";
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
    }
}
/*55555
  4
*/
int main()
{
    Print(ReadPositiveNumber("enter number"));
}
