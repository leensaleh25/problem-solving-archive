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


void InterSectedNumber(int Array1[3][3], int Array2[3][3], short Rows, short Cols) {
    int  Number;
    cout << "Intersected Numbers are :" << endl;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
              Number = Array1[i][j];
              if( FoundNumbers(Array2, Number, 3, 3)) {
                 cout<< setw(2)<<Number<<" ";
              }
        }
    }
   

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

    InterSectedNumber(Array1, Array2, 3, 3);
 



}

