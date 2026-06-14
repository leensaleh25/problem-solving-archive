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
void AddArrayElement(int Number, int arr[100], int& arrLength) {
    arrLength++;
    arr[arrLength - 1] = Number;
}
int PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i <= arrLength - 1; i++) {
        cout << arr[i] << " ";
    }
    return arr[100];
}
enum enPrime { prime = 1, notPrime = 2 };

enPrime CheckPrime(int checkarr) {

    int  m = round(checkarr / 2);
    for (int i = 2; i <= m; i++) {
        if (checkarr % i == 0)
            return enPrime::notPrime;
    }
    return enPrime::prime;
}

void CopyOnlyPimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length) {

    int Counter = 0;
    for (int i = 0; i <= arrLength; i++) {
        if (CheckPrime(arrSource[i]) == enPrime::prime) {
            AddArrayElement( arrSource[i], arrDestination, arr2Length);
            Counter++;
        }
    }
    arr2Length = Counter;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int arrLength;
    int arrDestination[100];
    FillArrayWithRandomNumbers(arr, arrLength);
    int arr2[100];
    cout << "\nArray elements: ";
    PrintArray(arr, arrLength);
    int arr2Length=0;
    CopyOnlyPimeNumbers(arr, arr2, arrLength, arr2Length);
    cout << "\nPrime Numbers are :";
    PrintArray(arr2, arr2Length);
}

