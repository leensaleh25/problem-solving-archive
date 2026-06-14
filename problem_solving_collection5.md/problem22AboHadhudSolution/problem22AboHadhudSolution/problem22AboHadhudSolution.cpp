#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {
	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

void ReadArray(int arr[100], int& arrlength) {
	cout << "\n Enter number of elements:\n ";
	cin >> arrlength;
	cout << "\n Enter array elements:\n ";
	for (int i = 0; i < arrlength; i++) {
		
		cout << "Element [" << i+1 << "]: ";
		cin >> arr[i];
	}
	cout << endl;
}
void PrintArray(int arr[100], int arrlength) {
	for (int i = 0; i < arrlength; i++) {

		cout << arr[i] << " ";
	}
	cout << "\n";
}
int TimeRepeated(int Number,int arr[100], int arrlength) {
	int Count = 0;
	for (int i = 0; i < arrlength -1; i++) {
		if (Number == arr[i]) {
			Count++;
		}
	}
	return Count;
}
int main()
{
	int arr[100], arrlength, NumberToCheck;
	ReadArray(arr, arrlength);
	NumberToCheck = ReadPositiveNumber("enter the number you want to check:");
	cout << "Original array: ";
	PrintArray(arr, arrlength);
	cout << "\nNumber " << NumberToCheck;
	cout << " is repeated ";
	cout << TimeRepeated(NumberToCheck, arr, arrlength) << " time(s)\n";
	return 0;
}

