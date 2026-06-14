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

void sumResult(int Array[3][3],short Rows, short Cols) {
    int sum = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            sum += Array[i][j];

        }
    }
       printf ("%05d   ", sum);
}
int main()
{
    srand((unsigned)time(NULL));
    int Array1[3][3];
    cout << "\nmatrix  :\n";
    fillmatrix(Array1, 3, 3);
    PrintFillMatrix(Array1, 3, 3);
    sumResult(Array1, 3, 3);
}

