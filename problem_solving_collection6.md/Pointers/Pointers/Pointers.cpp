#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
int main()
{
   /* int a = 10;
    cout << "a value= " << a << endl;
    cout << " an address" << &a << endl;

    int * p = &a;
    cout<<"a pointer ="<<p<<endl;
    cout << " a value of the address =" << *p << endl;

    cout << " *****************************************************"<<endl;

    *p = 20;
    a = 30;
    cout << "a pointer =" << p << endl;
    cout << " a value of the address =" << *p << endl;*/
     
    int a=10 , b=20;

    cout << "before swap a=" << a << endl;
    cout << "before swap b=" << b << endl;
    swap(&a, &b);
    cout << "After swap a=" << a << endl;
    cout << " After b=" << b << endl;

}
