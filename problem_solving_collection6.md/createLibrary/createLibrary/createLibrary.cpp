#include <iostream>
#include "Mylib.h"
#include "MyInputLib.h"
#include "mainlib.h"
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	/*Mylib::test();
	cout<<Mylib::SumOf2Numbers(2,3);*/
	cout << "\n";
	int number = mainlib::RandomNumber(1, 100);
	cout << number;
	cout<<mainlib::ReadPositiveNumber("\nenter number?\n");
	return 0;
}

