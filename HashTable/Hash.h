#pragma once

#include <string>
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
	double operator[](string key);

	void updateLoadValue();
	double getLoadValue();
	int numOfCollisions();
private:
	struct Node{
		string key;
		double value;
		Node* next;

		Node(string k, double i) : key(k), value(i), next(nullptr) {};
	};

	double loadValue;
	int size;
	int capacity = 139;
	int collisions = 0;
	Node* array[139] = {nullptr};
};

