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
bool IsIdentityMarix(int Array1[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (i==j && Array1[i][j]!=1) {
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
    int Array1[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    cout << "\nmatrix 1 :\n";
  
    PrintFillMatrix(Array1, 3, 3);
    if ( IsIdentityMarix(Array1, 3, 3))
        cout << "\nYES: Matrix is identity.";
    else
        cout << "\nNo: Matrix is NOT identity.";


}


