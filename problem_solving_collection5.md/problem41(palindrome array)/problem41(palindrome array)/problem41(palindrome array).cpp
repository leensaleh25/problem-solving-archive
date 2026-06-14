#include <iostream>
using namespace std;

void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {
	arrLength = 6;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;

}

int PrintArray(int arr[100], int arrLength) {
	for (int i = 0; i <= arrLength - 1; i++) {
		cout << arr[i] << " ";
	}
	return arr[100];
}

bool isPalindermeNumber(int arr[100], int arrLength) {
	for (int i = 0; i <= arrLength - 1; i++) {
		if (arr[i]!=arr[arrLength - i-1]) {
			return false;
		  }
	}
	return true;
}

int main()
{
	int arr[100];
	int arrLength;
	FillArrayWithRandomNumbers( arr,arrLength);
	cout << "Array\n";
	PrintArray(arr, arrLength);
	if (isPalindermeNumber(arr, arrLength)) {
		cout << "Yes, it is a palindrpm number\n";
	}
	else
		cout << "No, it is not a palindrpm number\n";

	
}

