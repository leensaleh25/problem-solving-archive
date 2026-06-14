#pragma once
#include <iostream>

using namespace std;
namespace Mylib
{
	void test() {
		cout << "hi,this is my first function" << endl;
	}

	int SumOf2Numbers(int num1, int num2) {
		return num1 + num2;
	}
}
