#pragma once
#include <iostream>
using namespace std;

namespace MyInputLib
{
	int ReadNumber(string message) {
		int Number;
		cout<< message<<endl;
		cin >> Number;
		return Number;
	}
}

