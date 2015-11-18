/*
 * Hash.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: matt
 */

#include "Hash.h"



Hash::Hash() {
	loadValue = 0.0;
	size = 0;
}

//~Hash() goes through table one index at a time and deletes all linked lists, if one is there
Hash::~Hash() {
	clear();
}


int Hash::hash(string key) {
	int result = 0;

	for(unsigned int i = 0; i < key.size(); i++) {
		result = result * 31 + int(key[i]);
	}

	return result % this->capacity;
}

void Hash::clear() {
	for(int i = 0; i < capacity; ++i) {
		if(array[i] != nullptr) {
			Node* temp = array[i];
			while(temp != nullptr) {
				Node* deleteNode = temp;
				temp = temp->next;
				deleteNode->next = nullptr;
				delete deleteNode;
				size--;
			}
		}
	}
}

void Hash::insert(string key, double value) {
	int index;

	index = hash(key);

	Node* newNode = new Node(key, value);

	if(array[index] == nullptr) {  //check if that index is empty
		array[index] = newNode;
	}
	else {						//if it's not empty, traverse the link to find the next empty
		Node* temp = array[index];
		while(temp->next != nullptr) { //find an empty space
			temp = temp->next;
		}

		temp->next = newNode;
		collisions++;
	}

	size++;
	updateLoadValue();
}

double Hash::retrieve(string key) {
	int index;

	index = hash(key);
	Node* temp = array[index];
	while(temp->key != key && temp != nullptr) temp = temp->next;
	if(temp == nullptr) {
		return 0;
	}

	return temp->value;
}

void Hash::updateLoadValue() {
	loadValue = double(size) / capacity;
}

double Hash::getLoadValue() {
	return loadValue;
}

double Hash::operator[](string key) {
	int index;

	index = hash(key);
	Node* temp = array[index];
	while(temp->key != key && temp != nullptr) temp = temp->next;
	if(temp == nullptr) {
		return 0;
	}

	return temp->value;
}

int Hash::numOfCollisions() {
	return collisions;
}
