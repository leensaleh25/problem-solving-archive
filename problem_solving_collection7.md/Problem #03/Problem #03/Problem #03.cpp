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
int SumRows(int Array[3][3], short RowNumber, short Cols) {
    int sum = 0;
    for (int j = 0; j < Cols; j++) {
        sum += Array[RowNumber][j];
    }
    cout << endl;
    return sum;
}


void PrintsumMatrix(int Array[3][3], short Rows, short Cols) {
    cout << "\nsum Rows:\n";
    for (int i = 0; i < Rows; i++) {
        cout << "sum Row" << i + 1 << "=" << SumRows(Array, i, 3) << endl;
    }
}
void SumArrayRows(int Array[3][3],int sumArray[3], short  Rows, short Cols) {
    
    for (int i = 0; i < Rows; i++) {
        sumArray [i] = SumRows(Array, i, 3);
       
    }
    
}
void PrintArraysumMatrix(int array[3],int Rows) {
    cout << "\nsum Array Rows:\n";
    for (int i = 0; i <Rows; i++) {
        
        cout << "sum Array Row" << i + 1 << "=" << array[i] << endl;
    }
}

    int main()
    {
        srand((unsigned)time(NULL));
        int Array[3][3];
        
        fillmatrix(Array, 3, 3);
        PrintFillMatrix(Array, 3, 3);
        int sumArray[3];
       
        /* PrintsumMatrix(Array, 3, 3);*/
         SumArrayRows(Array, sumArray, 3, 3);
         PrintArraysumMatrix(sumArray,3);
    };
    