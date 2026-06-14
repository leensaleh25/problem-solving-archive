
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
int RandomNumber(int from, int to) {
    int randNumber = rand() % (to - from + 1) + from;
    return randNumber;

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
short  CheckNumber(int arr[100],int Number, int arrLength) {
    cout << "Number you are looking for is:  " << Number;
    for (int i = 0; i <= arrLength - 1; i++) {
        if (arr[i] == Number) {
            return i;
        }
       
        }
      return -1;
    }

bool IsNumberInArray(int arr[100],int Number, int arrLength) {
    return CheckNumber(arr, Number, arrLength) != -1;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int arrLength= ReadPositiveNumber("\nenter a Number\n");
    int arr2[100];
    
    FillArrayWithRandomNumbers(arr, arrLength);
    PrintArray(arr, arrLength);
    int check=ReadPositiveNumber("\nenter a Number to search for?");
    short NumberPosition=CheckNumber(arr, check, arrLength);

    if (!IsNumberInArray(arr, check, arrLength))
        cout << "No ,the number is not found:\n";
    else
        cout << "yes ,it  is  found:\n";
  /*  if (NumberPosition == -1) {
       cout << "\nthe Number is Not Found:(\n";
    }
    else {

    
    cout << "\nthe number Found at posiyion: " << NumberPosition;
    cout << "\nthe Number found its order: " << NumberPosition + 1;}*/
    
}

