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

//processWeight: works with one string at a time
double processWeight(string formula, Hash& test);

string charToString(char c);

int charToInt(char c);

//create a HashTable from a given fileName
void createHashTable(string fileName, Hash& test);


int main() {
	Hash test;
	string fileName("PeriodicTableElements.txt");
	string line;
	string formula = "";

	double weight;

	createHashTable(fileName, test);

	ifstream formulasFile("formulas.txt");

	while(formulasFile >> formula) {
		weight = processWeight(formula, test);
		cout << formula << " has a weight of " << weight << endl;
	}

	return 0;
}

double processWeight(string formula, Hash& test) {
	double weight = 0;
	string element = "";
	char c;
	stack<char> res;

	stringstream ss(formula);

	//pushing all the chars from the string on the stack
	while(ss.get(c)) {
		res.push(c);
	}

	//finding the result of the formula
	while(!res.empty()) {
		char top = res.top();
		res.pop();
		if(isalpha(top)) {
			if(isupper(top)) {
				//cout << top << " is upper case" << endl;
				string key = charToString(top);
				//cout << key << " after converting from char to string." << endl;
				weight += test[key];
				//cout << weight << endl;
			}
			else if(islower(top)){
				//cout << top << " is lowercase" << endl;
				element = charToString(res.top()) + charToString(top);
				//cout << res.top() << " is the char on top" << endl;
				//cout << "After " << element << endl;
				res.pop();
				//cout << element << endl;
				weight += test[element];
				//cout << weight << endl;
			}
		}
		else if(isdigit(top) && res.top() == ')' ) {
			//cout << top << " is a multiplier of a subformula" << endl;
			int multiplier = charToInt(top);
			res.pop(); // poping ')'
			string subFormula = "";

			while(res.top() != '(') {
				subFormula = charToString(res.top()) + subFormula;
				res.pop();
			}
			//cout << subFormula << " is the subformula" << endl;
			res.pop(); //poping the left parentheses
			//cout << "Weight before adding subformula " << weight << endl;
			weight = (multiplier * processWeight(subFormula, test));  //adding weight of subformula
			//cout << "Weight after adding subformula " << weight << endl;
		}
		else if(isdigit(top)) {
			//cout << top << " is a number" << endl;
			int mult = charToInt(top);

			if(isdigit(res.top())) {
				stringstream number;
				number << charToInt(res.top()) << mult;
				number >> mult;
				//cout << "The multiple is " << mult << endl;
				res.pop();
			}

			while(!isupper(res.top())) {
				element = res.top() + element;
				res.pop();
			}
			element = res.top() + element;
			res.pop();

			//cout << element << endl;

			weight +=  mult * test[element];
			//cout << weight << endl;
			element = "";
		}
		else if(top == ')') {
			//cout << top << " is a right parentheses" << endl;

			string subFormula = "";

			while(res.top() != '(') {
				subFormula = charToString(res.top()) + subFormula;
				res.pop();
			}

			res.pop(); //poping the left parentheses
			//cout << "Weight before adding subformula " << weight << endl;
			weight = weight + processWeight(subFormula, test);//adding weight of subformula
			//cout << "Weight after adding subformula is " << weight << endl;
		}
		else if(top == '\r') cout << "End of line Character" << endl;
	}

	return weight;
}

string charToString(char c) {
	stringstream charToStr;
	string key;
	charToStr << c;
	charToStr >> key;

	return key;
}

int charToInt(char c) {
	int num = c - '0';
	return num;
}

void createHashTable(string fileName, Hash& test) {
	ifstream i(fileName);

	if(i.fail()) {
		cout << "invalid file name" << endl;
		return;
	}

	int num;
	string element;
	double value;

	while(i >> num) {
		i >> element >> value;
		test.insert(element, value);
	}

	i.close();
}
