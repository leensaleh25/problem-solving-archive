#include <iostream>
using namespace std;

void PrintNumber(int n, int m) {

	if (n <= m) {
		cout << n << endl;
		PrintNumber(n + 1, m);
	}

}

void PrintDownNumber(int n, int m) {//10,1
	if (n >= m) {
		cout << n << endl;
		PrintDownNumber(n - 1, m);
	}
}
int  Power(int n, int m) {//2,4 
	
	if (m == 0) {
		return 1;
	}
	else {
		return (n * Power(n, m - 1));
	}
	
}
int main()
{
	/*PrintNumber(1, 4);*/
	//PrintDownNumber(10, 1);
	cout<<Power(2, 4);
}

