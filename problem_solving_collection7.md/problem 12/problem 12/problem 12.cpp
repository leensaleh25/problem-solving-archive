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
bool isequals(int Array1[3][3], int Array2[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (Array1[i][j] != Array2[i][j]) {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    srand((unsigned)time(NULL));
    int Array1[3][3];
    int Array2[3][3];;
    cout << "\nmatrix 1 :\n";
    fillmatrix(Array1, 3, 3);
    PrintFillMatrix(Array1, 3, 3);
    cout << "\nmatrix 2 :\n";
    fillmatrix(Array2, 3, 3);
    PrintFillMatrix(Array2, 3, 3);
    if (isequals(Array1, Array2,3,3)) 
        cout << "\nis  equal!" << endl;
    else
        cout << "\nis not equal!" << endl;
    

}

