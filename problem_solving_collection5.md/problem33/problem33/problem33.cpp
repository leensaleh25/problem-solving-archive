#include <iostream>
#include<string>
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
int PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i <= arrLength - 1; i++) {
        cout << arr[i] << " ";
    }
    return arr[100];
}
void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength) {

    for (int i = 0; i <= arrLength; i++) {
        arrDestination[i] = arrSource[arrLength-1-i];
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int arrLength;
    int arr2[100];
    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "\nBefore:";
    PrintArray(arr, arrLength);
    cout << "\nAfter:";
    CopyArrayInReverseOrder(arr, arr2, arrLength);
    PrintArray(arr2, arrLength);
}

