#include <iostream>
#include<string>
#include<iomanip>
using namespace std;





void PrintFillMatrix(int Array[3][3], short Rows, short Cols) {

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("%02d   ", Array[i][j]);
        }
        cout << endl;
    }
}
int CountNumbers(int Array[3][3], int Number, short Rows, short Cols) {
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

bool isSparceountNumbers(int Array[3][3], short Rows, short Cols) {
    short MatrixSize = Rows * Cols;
    return (CountNumbers(Array,0, 3, 3) >= ceil((float)MatrixSize / 2));
}
   
 


int main()
{
    srand((unsigned)time(NULL));
    int Array1[3][3] = { {9,4,6},{10,10,0},{0,0,9} };
    cout << "\nmatrix 1 :\n";
    PrintFillMatrix(Array1, 3, 3);
  
    if (isSparceountNumbers(Array1, 3, 3)) 
        cout << "\nYes: It is Sparse\n";
    else   
        cout << "\nNo: It's NOT Sparse\n";
   
    

}


