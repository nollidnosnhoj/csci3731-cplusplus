// header file
#include "factorial.h"

// returns the factorial of an integer
int addFact (int x) {
	if (x == 1) {
		return 1;
	}
	int total = 1;
	for (int i = x; i > 1; i--) {
		total *= i;
	}
	return total;
}