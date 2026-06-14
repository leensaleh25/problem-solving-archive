#include <iostream>
using namespace std;
void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {
	arrLength = 10;
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 70;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;
}
short CheckDistinct(int Number,int arr[100], int& arrLength) {

	for (int i = 0; i < arrLength; i++) {
		if (arr[i] == Number) 
			return i;	
	}
	return -1;
}
bool IsNumberInArray(int arr[100], int Number, int arrLength) {
	return  CheckDistinct(Number, arr, arrLength) != -1;
}
void AddArrayElement(int Number, int arr[100], int& arrLength) {
	arrLength++;
	arr[arrLength - 1] = Number;
}
void copyArray(int arrSource[100], int arrDestination[100], int arrLength,int& arr2Length) {

	for (int i = 0; i < arrLength; i++) {
		if (!IsNumberInArray(arrDestination, arrSource[i], arr2Length)) {
			AddArrayElement(arrSource[i],arrDestination, arr2Length);
		}
	}
}
int PrintArray(int arr[100], int arrLength) {
	for (int i = 0; i <= arrLength - 1; i++) {
		cout << arr[i] << " ";
	}
	return arr[100];
}
int main()
{

	int arrLength=0;
	int arr2Length=0;
	int arrSource[100];
	int arrDestination[100];
	
	FillArrayWithRandomNumbers(arrSource, arrLength);
	cout << "Array\n";
	PrintArray(arrSource, arrLength);
	cout << "\nDistinct Array\n";
	copyArray(arrSource, arrDestination, arrLength, arr2Length);
	PrintArray(arrDestination, arr2Length);

}

