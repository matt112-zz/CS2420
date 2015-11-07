#pragma once

#include <iostream>
#include <iomanip>

#define START 1  //Referencing the beginning of the array

using namespace std;

class heap
{
public:
	heap();
	~heap();
	void insert(int item);
	int removeFront();
	void print();
	void printTree();
	void printTree(int index, int depth);
	void bubbleDown(int index);
	bool hasLChild(int i);
	bool hasRChild(int i);
	void bubbleUp(int index);
	void swap(int i1, int i2);
private:
	int A[21];	//The heap only stores 20 ints, but index 0 isn't being used
	int size;	//keeps track of how many values have been entered in the heap.
};
