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

double processWeight(string formula, Hash& test) {
	double weight = 0;
	string element = "";
	char c;
	stack<char> res;

	stringstream ss(formula);

	while(ss.get(c)) {
		res.push(c);
	}

	while(!res.empty()) {
		char top = res.top();
		res.pop();
		if(isalpha(top)) {
			if(isupper(top)) {
				weight += test[top];
				cout << weight << endl;
			}
			else {
				element = res.top() + top;
				res.pop();
				cout << element << endl;
				weight += test[element];
				cout << weight << endl;
			}
		}
		else if(isdigit(top)) {
			cout << top << " is a number" << endl;
			while(!isupper(res.top())) {
				element = res.top() + element;
				res.pop();
			}
			element = res.top() + element;
			res.pop();

			cout << element << endl;

			int d = top - '0';
			weight += d * test[element];
			cout << weight << endl;
			element = "";
		}
		else if(top == '(' || top == ')') {
			cout << top << " is a parentheses" << endl;

		}
		else cout << "End of line Character" << endl;
	}

	return weight;
}




int main() {
	Hash test;
	ifstream i("PeriodicTableElements.txt");
	int num;
	string element;
	string line;
	double value;
	double weight;

	while(i >> num) {
		i >> element >> value;
		test.insert(element, value);
	}

	i.close();

	char c;

	ifstream formulas("formulas.txt");
	stack<char> res;

	while(!formulas.eof()) {
		element = "";
		num = 0;
		weight = 0;
		getline(formulas, line);
		stringstream ss(line);

		while(ss.get(c)) {
			res.push(c);
		}

		while(!res.empty()) {
			char top = res.top();
			res.pop();
			if(isalpha(top)) {
				if(isupper(top)) {
					weight += test[top];
					cout << weight << endl;
				}
				else {
					element = res.top() + top;
					res.pop();
					cout << element << endl;
					weight += test[element];
					cout << weight << endl;
				}
			}
			else if(isdigit(top)) {
				cout << top << " is a number" << endl;
				while(!isupper(res.top())) {
					element = res.top() + element;
					res.pop();
				}
				element = res.top() + element;
				res.pop();

				cout << element << endl;

				int d = top - '0';
				weight += d * test[element];
				cout << weight << endl;
				element = "";
			}
			else if(top == '(' || top == ')') {
				cout << top << " is a parentheses" << endl;

			}
			else cout << "End of line Character" << endl;
		}
	}
	return 0;
}
