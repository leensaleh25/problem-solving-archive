 #include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int RandomNumber(int from, int to) {
    int randNumber = rand() % (to - from + 1) + from;
    return randNumber;
}

void  fillmatrix(int Array[3][3],short Rows,short Cols) {
    for (int i=0; i < Rows; i++) {
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
            cout << setw(3) << Array[i][j]<<"       ";
        }
        cout << endl;
    }
}
int main()
{
     srand((unsigned)time(NULL));
     int Array[3][3];
     fillmatrix(Array, 3, 3);
     PrintFillMatrix(Array, 3, 3);
}
