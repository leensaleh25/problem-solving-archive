#include <iostream>
using namespace std;
int main()
{
 /*   int* ptrx;
    float* ptry;

    ptrx = new int;
    ptry = new float;

    *ptrx = 25;
    *ptry = 14;

    cout << *ptrx << endl;
    cout << *ptry << endl;
    delete ptrx;
    delete ptry;*/

    int num;
    cout << "enter how many students?\n";
    cin >> num;
    float* ptr;
    ptr = new float[num];
    cout << "enter grades:";

    for (int i = 0; i < num; i++) {
        cout << "student: " << i + 1 << endl;
        cin>> *(ptr + i);
    }
    cout << "display the grades:\n";
    for (int i = 0; i < num; i++) {
        cout << "student: " << i + 1<<"    ";
        cout<<  *(ptr + i);
    }


    delete[] ptr;
}

