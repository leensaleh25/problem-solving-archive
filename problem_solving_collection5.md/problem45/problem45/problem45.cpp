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
        arr[i] = RandomNumber(-100, 100);

    }
}

int NegativeCount(int arr[100], int& arrLength) {
    int Count = 0;
    for (int i = 0; i < arrLength; i++) {
        if (arr[i] < 0) {
            Count += 1;
        }
    }
    return Count;
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
    int arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "\nArray:\n";
    PrintArray(arr, arrLength);
    cout << "\nNegative numbers count is: ";
    cout << NegativeCount(arr, arrLength);
}

