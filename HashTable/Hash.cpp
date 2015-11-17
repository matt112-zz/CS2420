/*
 * Hash.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: matt
 */

#include "Hash.h"



Hash::Hash() {
	// TODO Auto-generated constructor stub

}

Hash::~Hash() {
	// TODO Auto-generated destructor stub
}


int Hash::hash(string str, int tableSize) {
	int result = 0;

	for(int i = 0; i < str.size(); i++) {
		result = result * 31 + int(str[i]);
	}

	return result % tableSize;
}

//int numOfCollisions(vector<int> v) {
//	int result = 0;
//
//	for(int i = 0; i < v.size() - 1; ++i) {
//		if(v[i] == v[i+1]) result++;
//	}
//
//	return result;
//}
