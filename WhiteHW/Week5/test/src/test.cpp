//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	int a = 0;
	try {
		a = stoi ("1aaa");
	}
	catch (exception &a) {
		cout << a.what() << "===";
	}
	cout << a;
	return 0;
}
