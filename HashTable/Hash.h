/*
 * Hash.h
 *
 *  Created on: Nov 15, 2015
 *      Author: matt
 */

#ifndef HASH_H_
#define HASH_H_

#include <string>
#include <vector>

using namespace std;

class Hash {
public:
	Hash();
	virtual ~Hash();
	void clear();
	void insert();
	double retrieve(int index);
	int hash(string str, int tableSize);

	Hash operator[](int index);

private:
	struct Node{
		double value;
		Node* next;

		Node(double i) : value(i), next(nullptr) {};
	};

	int size = 160;
	vector<Node*> v;
};

#endif /* HASH_H_ */
