#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

int RandomNumber(int from, int to) {
    int randNumber = rand() % (to - from + 1) + from;
    return randNumber;
}
void  fillmatrix(int Array[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            Array[i][j] = RandomNumber(1, 10);
        }
        cout << endl;
    }
}
void PrintFillMatrix(int Array[3][3], short Rows, short Cols) {

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("%02d   ", Array[i][j]);
        }
        cout << endl;
    }
}
int FoundNumbers(int Array[3][3], int Number, short Rows, short Cols) {
    int Count = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (Array[i][j] == Number) {
                Count += 1;
            }
        }
    }
    return Count;
}

bool isFoundNumber(int Array[3][3], int Number,short Rows, short Cols) {
    if (FoundNumbers(Array, Number, 3, 3)>0) {
        return true;
    }
    else
        return false;
}




int main()
{
    srand((unsigned)time(NULL));
    int Array1[3][3];
    cout << "\nmatrix 1 :\n";
    fillmatrix(Array1, 3, 3);
    PrintFillMatrix(Array1, 3, 3);
    int Number;
    cout << "enter a number";
    cin >> Number;
    if (isFoundNumber(Array1,Number, 3, 3))
        cout << "\nYes: Found it \n";
    else
        cout << "\nNo: NOT found it\n";



}


