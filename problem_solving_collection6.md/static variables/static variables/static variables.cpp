#include <iostream>
using namespace std;
void MyFunc() {
    static int number=1;
    cout << number << endl;
    number++;
}

int main()
{
    MyFunc();
    MyFunc();
    MyFunc();
    MyFunc();
}
