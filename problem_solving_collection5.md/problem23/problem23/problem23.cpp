#include <iostream>
using namespace std;

int ReadPositiveNumber(int& Number) {

	do {
		cout << "enter Number" << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
int RandomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;

}
void Arrays(int arr[100],int length) {
	int from,  to;
	cout << "Araay:";
	for (int i = 0; i <= length-1; i++) {
	   cout<<RandomNumber( 1, 100)<<" ";
	}
	
}

int main()
{
	srand((unsigned)time(NULL));
	int Number;
	int arr[100];
	Arrays(arr, ReadPositiveNumber(Number));
}
