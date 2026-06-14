#include <iostream>
using namespace std;

int RandomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;

}
void FillArrayWithRandomNumbers(int arr[100], int &arrLength) {
	cout << "\n Enter Number Of Elements:\n";
	cin >> arrLength;
	for (int i = 0; i <= arrLength; i++) {
		arr[i] = RandomNumber(1, 100);

	}
}
void PrintArray(int arr[100], int arrLength) {
	for (int i = 0; i <= arrLength-1; i++) {
		cout << arr[i] << " ";
	}
}
int MaxNumber(int arr[100], int arrLength) {
	int max = 0;
	for (int i = 0; i <= arrLength-1; i++) {
		if (arr[i] > max)
			max = arr[i];
	}return max;
}
int MinNumber(int arr[100], int arrLength) {
	int min = arr[0];
	for (int i = 0; i <= arrLength-1; i++) {
		
		if (arr[i] < min)
			min = arr[i];
	}return min;
}
int SumOfArrays(int arr[100], int arrLength) {
	int sum = 0;
	for (int i = 0; i <= arrLength-1; i++) {
		sum += arr[i];
	}return sum;
}
float AverageOfArrays(int arr[100], int arrLength) {

	return (float)SumOfArrays(arr, arrLength) / arrLength;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100];
	int arrLength;
	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "\nArray elements: ";
	PrintArray(arr, arrLength);
	cout << "\n Max Number is: "<<MaxNumber(arr, arrLength);
	cout << "\n Min Number is: " << MinNumber(arr, arrLength);
	cout << "\n Sum of arrays:" << SumOfArrays(arr, arrLength);
	cout << "\n Average of arrays:" << AverageOfArrays(arr, arrLength);
}

