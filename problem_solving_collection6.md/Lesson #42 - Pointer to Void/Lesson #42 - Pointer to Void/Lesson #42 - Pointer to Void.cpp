

#include <iostream>
using namespace std;
int main()
{
    void *p;
    float x=50;
    int d = 99;

    p = &x;
    
    cout << *(static_cast< float*>(p))<< endl;

    p = &d;

    p = &d;
    cout << *(static_cast<int*>(p));
}

