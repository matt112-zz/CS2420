#include <iostream>
#include "AVL.h"

using namespace std;

int main() {
	AVL test;

	test.insert(10);
	test.insert(15);
	test.insert(20);
	test.insert(25);
	test.insert(30);

	test.preorder();

	return 0;
}
