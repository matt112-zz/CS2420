#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <stack>
#include "Hash.h"

using namespace std;

int main() {
	Hash test;
	ifstream i("PeriodicTableElements.txt");
	//ofstream o("array.txt");
	int num;
	string element;
	string line;
	double value;
	double weight;

	while(i >> num) {
		i >> element >> value;
		test.insert(element, value);
		//o << index << " " << value << endl;
	}

	i.close();

//	ifstream j("test.txt");
//
//	while(j >> element) {
//		cout << element << " " << test.retrieve(element) << endl;
//	}


	char c;

	ifstream formulas("formulas.txt");
	stack<char> res;

	while(!formulas.eof()) {\
		element = "";
		num = 0;
		weight = 0;
		getline(formulas, line);
		stringstream ss(line);
		while(ss.get(c)) {
			if(isalpha(c)) {
				res.push(c);
				cout << "Pushed " << c << " on the stack" << endl;
			}
			else if(isdigit(c)) {
				cout << c << " is a number" << endl;
				cout << res.top() << endl;
				while(!res.empty() && !isupper(res.top())) {
					element = res.top() + element;
					res.pop();
				}
				element = res.top() + element;
				res.pop();

				cout << element << endl;

				int d = c - '0';
				weight += d * test[element];
				cout << weight << endl;
				element = "";
			}
			else if(c == '(' || c == ')') {
				cout << c << " is a parentheses" << endl;
			}
			else if(c == '\n') {
				cout << "End of line" << endl;
			}
			else {
				cout << "Whoe knows..." << endl;
			}
		}

		while(!res.empty()) {
			while(!isupper(res.top())) {
				cout << res.top() << " is on top of the stack." << endl;
				element = res.top() + element;
				res.pop();
			}
			element = res.top() + element;
			res.pop();

			cout << element << endl;
			weight += test[element];
			cout << weight << endl;
			element = "";
		}
		cout << "Stack is empty" << endl;
		cout << "Done with that line. Total weight is: " << weight << endl << endl;
	}
	return 0;
}
