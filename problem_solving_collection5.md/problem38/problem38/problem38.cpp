#include <iostream>
using namespace std;
int RandomNumber(int from, int to) {
    int randNumber = rand() % (to - from + 1) + from;
    return randNumber;

}
void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {
    cout << "\n Enter Number Of Elements:\n";
    cin >> arrLength;
    for (int i = 0; i <= arrLength; i++) {
        arr[i] = RandomNumber(1, 100);

    }
}
void AddArrayElement(int Number, int arr[100], int& arrLength) {
    arrLength++;
    arr[arrLength - 1] = Number;
}


void copyOddNumberArray(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength) {

    for (int i = 0; i < arrLength; i++) {
        if (arrSource[i] % 2 != 0) {
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
    }
}
void PrintArray(int arr[100], int& arrLength) {
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";

    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int arrLength = 0;
    int arr2Length = 0;
    FillArrayWithRandomNumbers(arr, arrLength);
    int arr2[100];
    copyOddNumberArray(arr, arr2, arrLength, arr2Length);

    cout << "\nArray elements: ";
    PrintArray(arr, arrLength);
    cout << "\ncopy Array elements: ";
    PrintArray(arr2, arr2Length);
    return 0;
}
