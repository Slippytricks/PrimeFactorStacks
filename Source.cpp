/*<><><><><><><><><><><><><><><><><><><><><><><><><>*/
//Program Name: Prime Factor Finder
//Developer: Trevor Murphy
//Date: 12/10/2017
//Description: Finds the prime factor of input number
//main/test file/prog
/*<><><><><><><><><><><><><><><><><><><><><><><><><>*/
#include "linkedStackType.h"
#include "primeFuncs.h"
#include <conio.h>

using namespace std;

int main() {
	linkedStackType<int> pfacs;
	linkedStackType<int> numstk;
	int num;

	while (1) {
		numstk.push(num = inputNum());

		findPrimes(numstk, pfacs);

		if (pfacs.getSz() > 1) {
			cout << "These are the prime factors: " << endl;
			pfacs.reverseStack(numstk);
		}
		else {
			pfacs.print();
			cout << "is a prime number!" << endl;
		}	

		cout << endl << "x to quit, any to continue: ";
		if (_getch() == 'x')
			break;
		else {
			system("cls");
			pfacs.initializeStack();
		}
	}
	return 0;
}
