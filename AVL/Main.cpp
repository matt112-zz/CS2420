#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "AVL.h"

using namespace std;

int main() {
	srand(time(NULL));
	AVL test;

	const int size = 20;

	for (int i = 0; i < size; i++) {
	      test.insert((rand() % 50) + 1);
	}

	test.print();

	test.preorder();

	return 0;
}
