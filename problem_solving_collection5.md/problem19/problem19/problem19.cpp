#include <iostream>
#include<cstdlib>
using namespace std;

int ReadNumber(int from,int to) {
	int randNumber= rand() % (to - from + 1) + from;
	return randNumber;

}
int main()
{
	srand((unsigned)time(NULL));
	cout<<ReadNumber(1, 10);
	cout << ReadNumber(1, 10);
	cout << ReadNumber(1, 10);


}

