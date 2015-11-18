//Matthew Castro
//Section 1
//
//Disclaimer:
//
//I Matthew Castro have not used any code other than my own (or that in the textbook) for this project. I also
//
//have not used any function or data-structure from the Standard-Template Library. I understand that any
//
//violation of this disclaimer will result in a 0 for the project.

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include "Hash.h"
#include "Stack.h"

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
	Stack<char> res;

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
				string key = charToString(top);
				weight += test[key];
			}
			else if(islower(top)){
				element = charToString(res.top()) + charToString(top);
				res.pop();
				weight += test[element];
			}
		}
		else if(isdigit(top) && res.top() == ')' ) {
			int multiplier = charToInt(top);
			res.pop(); // pop ')'
			string subFormula = "";

			while(res.top() != '(') {
				subFormula = charToString(res.top()) + subFormula;
				res.pop();
			}
			res.pop(); //pop the left parentheses
			weight = (multiplier * processWeight(subFormula, test));  //adding weight of subformula
		}
		else if(isdigit(top)) {
			int multiple = charToInt(top);

			if(isdigit(res.top())) {
				stringstream number;
				number << charToInt(res.top()) << multiple;
				number >> multiple;
				res.pop();
			}

			while(!isupper(res.top())) {
				element = res.top() + element;
				res.pop();
			}
			element = res.top() + element;
			res.pop();


			weight +=  multiple * test[element];
			element = "";
		}
		else if(top == ')') {
			string subFormula = "";

			while(res.top() != '(') {
				subFormula = charToString(res.top()) + subFormula;
				res.pop();
			}

			res.pop(); //pop the left parentheses
			weight = weight + processWeight(subFormula, test);//adding weight of subformula
		}
		else cout << "End of line Character" << endl;
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
	stringstream ss;
	int index;
	ss << c;
	ss >> index;

	return index;
}

void createHashTable(string fileName, Hash& test) {
	ifstream ifs(fileName);

	if(ifs.fail()) {
		cout << "invalid file name" << endl;
		return;
	}

	int num;
	string element;
	double value;

	while(ifs >> num) {
		ifs >> element >> value;
		test.insert(element, value);
	}

	ifs.close();
}
