/*
 * Hash.h
 *
 *  Created on: Nov 15, 2015
 *      Author: matt
 */

#ifndef HASH_H_
#define HASH_H_

#include <string>
//#include <vector>
#include <iostream>

using namespace std;

class Hash {
public:
	Hash();
	virtual ~Hash();
	void insert(string key, double value);
	double retrieve(string key);
	int hash(string key);
	void clear();

	void updateLoadValue();
	double getLoadValue();
	int numOfCollisions();

	double operator[](string key);

private:
	struct Node{
		string key;
		double value;
		Node* next;

		Node(string k, double i) : key(k), value(i), next(nullptr) {};
	};

	double loadValue;
	int size;
	int capacity = 160;
	int collisions = 0;
	Node* array[160] = {nullptr};
};

#endif /* HASH_H_ */
