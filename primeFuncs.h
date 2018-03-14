/*<><><><><><><><><><><><><><><><><><><><><><><><><>*/
//Program Name: Prime Factor Finder
//Developer: Trevor Murphy
//Date: 12/10/2017
//Description: Finds the prime factor of input number
//main/test file/prog functions for input and finding
//prime factors
/*<><><><><><><><><><><><><><><><><><><><><><><><><>*/
#pragma once
#include <iostream>

using namespace std;

int inputNum() {
	int num = 0;
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			system("cls");
		}
		cout << "Enter a non-negative number to retrieve prime factors of: ";
		cin >> num;
	} while (cin.fail() || num < 0);
	cout << endl;
	return num;
}

void factor(linkedStackType<int>& numstk, linkedStackType<int>& pfacs, int fac) {
	int num = numstk.top();
	numstk.pop();
	pfacs.push(fac);
	if (num != fac)
		numstk.push(num / fac);
}

void findPrimes(linkedStackType<int>& numstk, linkedStackType<int>& pfacs){
	while (!numstk.isEmptyStack())
		if (numstk.top() % 2 == 0)
			factor(numstk, pfacs, 2);
		else if (numstk.top() % 3 == 0)
			factor(numstk, pfacs, 3);
		else if (numstk.top() % 5 == 0)
			factor(numstk, pfacs, 5);
		else {
			pfacs.push(numstk.top());
			numstk.pop();
		}
}
