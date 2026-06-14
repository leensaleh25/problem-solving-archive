#pragma once
#include <iostream>
using namespace std;
namespace mainlib
{
    int ReadPositiveNumber(string Message) {
        int Number = 0;
        do {
            cout << Message << endl;
            cin >> Number;
        } while (Number <= 0);
        return Number;
    }
    /* srand((unsigned)time(NULL));*/
    int RandomNumber(int from, int to) {
        int randNumber = rand() % (to - from + 1) + from;
        return randNumber;
    }
}