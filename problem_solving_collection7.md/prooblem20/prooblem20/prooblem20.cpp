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

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("%02d   ", Array[i][j]);
        }
        cout << endl;
    }
}
int FoundMinNumbers(int Array[3][3], short Rows, short Cols) {
    int Min = Array[0][0];
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            
            if (Array[i][j] < Min) {
                Min = Array[i][j] ;
            }
        }
    }
    return Min;
}

int FoundMaxNumbers(int Array[3][3], short Rows, short Cols) {
    int Max = Array[0][0];
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            
            if (Array[i][j] > Max) {
                Max = Array[i][j];
            }
        }
    }
    return Max;
}


int main()
{
    srand((unsigned)time(NULL));
    int Array1[3][3];
    cout << "\nmatrix 1 :\n";
    fillmatrix(Array1, 3, 3);
    PrintFillMatrix(Array1, 3, 3);
    cout << "\nmin Number" << endl;
    cout<<FoundMinNumbers(Array1, 3, 3);
    cout << "\nmax Number" << endl;
    cout << FoundMaxNumbers(Array1, 3, 3);


}


