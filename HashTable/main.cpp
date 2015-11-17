#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Hash.h"

using namespace std;

int main() {
	Hash test;
	ifstream i("PeriodicTableElements.txt");
	ofstream o("array.txt");
	int in;
	string element;
	string str;
	double value;
	int size = 160;
	vector<double> index(size);

	while(i >> in) {
		i >> element >> value;
		int ind = test.hash(element, size);
		o << ind << " " << value << endl;
		index[ind] = value;
	}

	i.close();

	ifstream j("test.txt");

	while(j >> str) {
		cout << index[test.hash(str, size)] << endl;
	}

	return 0;
}
