#include "Simple_Calculator.h"
#include<iostream>
#include<string>
#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
	cout << "-------------Welcome to Calcuator.-------------" << endl;
	cout << "1.This calcuator supports four operations: + - * / ." << endl;
	cout << "2.This calculator supports decimal operations." << endl;
	cout << "3.This calculator supports brackets." << endl;
	cout << "Please enter the calculation equation with out space!" << endl;
	string str;
	while (cin >> str) {
		calculator(str);
		cout << "Please enter the calculation equation with out space!" << endl;
	}

	return 0;

}
