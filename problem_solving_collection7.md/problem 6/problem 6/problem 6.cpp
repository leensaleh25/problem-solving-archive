#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
void  fillmatrix(int Array[3][3], short Rows, short Cols) {
    short counter = 0;
    for (int i = 0; i < Rows; i++) {

        for (int j = 0; j < Cols; j++) {
            counter++;
            Array[i][j] = counter;           
        }
        cout << endl;
    }
}
void PrintFillMatrix(int Array[3][3], short Rows, short Cols) {
    cout << "\nmatrix :\n";
    for (int i = 0; i < Rows; i++) {

        for (int j = 0; j < Cols; j++) {
            cout << setw(3) << Array[i][j] << "       ";
        }
        cout << endl;
    }
}
int main()
{
    int Array[3][3];
    fillmatrix(Array, 3, 3);
    PrintFillMatrix(Array, 3, 3);
}

