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
        arr[i] = RandomNumber(1, 100);

    }
}
int PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i <= arrLength - 1; i++) {
        cout << arr[i] << " ";
    }
    return arr[100];
}
void Sumarr(int arr1[100], int arr2[100], int arrLength) {
    int Sum=0;
    for (int i = 0; i <= arrLength - 1; i++) {
        
        Sum = arr1[i] + arr2[i];
        cout << Sum<<" ";
        
    }
  
}
int main()
{
    srand((unsigned)time(NULL));
     int arrLength;
    int arr[100];
    int Sum[100];
    int arr2[100];
    arrLength = ReadPositiveNumber("enter Number:\n");
    FillArrayWithRandomNumbers(arr, arrLength);
    PrintArray(arr,  arrLength);
    cout << "\n";
    FillArrayWithRandomNumbers(arr2, arrLength);
    PrintArray(arr2, arrLength);
    cout << "\nSum Array elements: ";
   Sumarr(arr, arr2, arrLength);
  

   
}

