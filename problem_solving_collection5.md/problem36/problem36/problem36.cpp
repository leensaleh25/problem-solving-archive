#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

void AddArrayElement(int Number, int arr[100], int& arrLength) {
    arrLength++;
    arr[arrLength - 1] = Number;  
}
void InputUserNumberInArray(int arr[100], int& arrLength) {
    bool AddMore = true;
    do {
        AddArrayElement(ReadPositiveNumber("Please enter Number!"), arr, arrLength);
        cout << "\n Do you want to add more Numbers? [0]:No,[1]:yes?";
        cin >> AddMore;
    } while (AddMore);
}
void PrintArray(int arr[100], int& arrLength) {
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";

    }
}
 int main()
{
     int arr[100];
     int arrLength=0;
     InputUserNumberInArray(arr, arrLength);
     cout << "\n Array length: " << arrLength<<endl;
     cout << "Array elements: ";
    PrintArray(arr, arrLength);
    return 0;
}
