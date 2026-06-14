#include <iostream>
#include<string>
using namespace std;

int RandomNumber(int from, int to) {
    int randNumber = rand() % (to - from + 1) + from;
    return randNumber;

}
int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {
    for (int i = 0; i <= arrLength; i++) {
        arr[i] = i + 1;

    }
}


void Swap(int& A, int& B) {
    int Temp;
    Temp = A;
    A = B;
    B = Temp;
}

void ShelfArray(int arr[100], int arrLength) {

    for (int i = 0; i < arrLength; i++) {
        int index1 = RandomNumber(1, arrLength)-1;
        int index2 = RandomNumber(1, arrLength)-1;
        Swap(arr[index1], arr[index2]);
    }
}
int PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i <= arrLength - 1; i++) {
        cout << arr[i] << " ";
    }
    return arr[100];
}
int main()
{
    int arr[100];
    int arrLength = ReadPositiveNumber("enter Number: ");
    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "\nArray before shelf:";
    PrintArray(arr, arrLength);
    cout << "\nArray After shelf:";
    ShelfArray(arr, arrLength);
    PrintArray(arr, arrLength);
}
