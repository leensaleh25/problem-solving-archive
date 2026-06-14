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
bool IScalarMarix(int Array1[3][3], short Rows, short Cols) {
    int Scalr = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
           Scalr=Array1[0][0];
            if (i == j && Array1[i][j] != Scalr) {
                return false;
            }
            else if (i != j && Array1[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    srand((unsigned)time(NULL));
    int Array1[3][3] = { {9,0,0},{0,10,0},{0,0,9} };
    cout << "\nmatrix 1 :\n";

    PrintFillMatrix(Array1, 3, 3);
    if (IScalarMarix(Array1, 3, 3))
        cout << "\nYES: Matrix is Scalar.";
    else
        cout << "\nNo: Matrix is NOT Scalar.";


}


