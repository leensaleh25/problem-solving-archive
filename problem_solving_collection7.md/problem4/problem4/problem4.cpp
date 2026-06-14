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
            Array[i][j] = RandomNumber(1, 100);
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
int SumCols(int Array[3][3], short Rows,short ColsNumber) {
    int sum = 0;
    for (int i = 0; i < Rows; i++) {
        sum += Array[i][ColsNumber];
    }
    cout << endl;
    return sum;
}

void PrintsumCols(int Array[3][3], short Rows, short Cols) {
    cout << "\nsum cols:\n";
    for (int i = 0; i < Cols; i++) {
        cout << "sum Cols" << i + 1 << "=" << SumCols(Array, 3, i) << endl;
    }
}
void SumColsArray(int Array[3][3], short Rows,int arr[3], short ColsNumber) {
    for (int i = 0; i < Rows; i++) {
        arr[i] = SumCols(Array, 3, i);
    }
}
void PrintArray(int arr[3], short Cols) {
    for (int j = 0; j< Cols; j++) {
        cout << "sum Array Cols" << j + 1 << "=" << arr[j] << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int Array[3][3];
    int arr[3];
    fillmatrix(Array, 3, 3);
    PrintFillMatrix(Array, 3, 3);
    PrintsumCols(Array, 3, 3);
    SumColsArray(Array, 3,arr, 3);
    PrintArray(arr, 3);
}

