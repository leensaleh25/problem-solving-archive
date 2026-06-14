#include <iostream>
using namespace std;
int main()
{
    int arr[4] = { 1,2,3,4 };
    int* p;
    p = arr;

    cout << "Address:\n";
    cout << p << endl;
    cout << p+1 << endl;
    cout << p+2 << endl;
    cout << p+3 << endl;

    cout << "a value:\n";
    cout << *(p)<< endl;
    cout << *(p+1) << endl;
    cout << *(p + 2) << endl;
    cout << *(p + 3) << endl;
}
