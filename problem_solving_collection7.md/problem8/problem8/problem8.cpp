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
void muliArrayes(int Array[3][3], int array2[3][3], int newMatrix[3][3] , short Rows, short Cols) {
    
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            newMatrix[i][j] = Array[i][j] * array2[i][j];
        }
        cout << endl;
    }
  
}
int main()
{
    srand((unsigned)time(NULL));
    int Array1[3][3];
    int Array2[3][3];
    int arr[3];
    int newMatrix[3][3];
    cout << "\nmatrix 1 :\n";
    fillmatrix(Array1, 3, 3);
    PrintFillMatrix(Array1, 3, 3);
    cout << "\nmatrix 2:\n";
    fillmatrix(Array2, 3, 3);
    PrintFillMatrix(Array2, 3, 3);
    muliArrayes(Array1, Array2, newMatrix, 3, 3);
    PrintFillMatrix(newMatrix, 3, 3);
}