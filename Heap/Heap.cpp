#include "Heap.h"

heap::heap()
{
	size = 0;
}

heap::~heap()
{
}

//Inserts an item at the end of the heap, then fixes the heap to maintain the min-heap property.
void heap::insert(int item) {
	A[size + 1] = item;
	size++;
	bubbleUp(size);
}

//removes and returns the first element in the heap.
//maintains the heap property after assigning the last element of the heap to the beginning by calling bubbleDown()
int heap::removeFront() {
    if(size) {
        int temp = A[START];
        swap(START, size);
        size--;
        bubbleDown(START);
        return temp;
    }
    else {
        return 0;
    }
}

//prints out the array that is being used to implement the heap
void heap::print() {
    if(size) {
        cout << "\nHere is the Array representation of the heap:" << endl;
        cout << "[";
        for (int i = 1; i < size; i++) {
            cout << A[i] << ",";
        }
        cout << A[size];
        cout << "]" << endl;
    }
    else {
        cout << "\nThe heap is empty. Nothing to print" << endl;
    }
}

//helper function for printTree(int index, int depth)
void heap::printTree() {
	if(size) {
        printTree(START, 0);
    }
    else {
        cout << "\nThe heap is empty. Nothing to print" << endl;
    }
}

//prints out the heap in an indented tree form. Children are 1 tab away from parent, each element on a new line
void heap::printTree(int index, int depth) {
	if (index <= size) {
		cout << setw(4 * depth) << "";
		cout << A[index];
		if(index * 2 > size) cout << " [Leaf]" << endl;
		else cout << endl;
		printTree(index * 2, depth+1);
		printTree(index * 2 + 1, depth+1);
	}
}

//recursively checks if the item at position "index" needs to be sorted down the heap to maintain the min-heap property
void heap::bubbleDown(int index) {
	int left = index * 2;
	int right = (index * 2) + 1;
	if (hasRChild(index)) {	// if element has right child (if it has right, it also has left due to heap property
		if ((A[left]) < A[right]) { //left child is smaller than right child
			if (A[index] > A[left]) { // is parent bigger than left child
				swap(index, left);		// swap parent with left child, then bubble down again
				bubbleDown(left);
			}
		}
		else {					//right child is smaller than left child
			if (A[index] > A[right]) { // is parent bigger than right child
				swap(index, right);		// swap parent with right child, then bubble down again
				bubbleDown(right);
			}
		}
	}
	else if (hasLChild(index)) {	// if element has a left child
		if (A[index] > A[left]) { // is parent bigger than right child
			swap(index, left);		// swap parent with right child, then bubble down again
		}
	}
	else {							//element is a leaf node. has no children
		return;						// leaves are already sorted heaps
	}
}

bool heap::hasLChild(int i) {
	return (i*2 <= size);
}

bool heap::hasRChild(int i) {
	return (i*2 + 1 <= size);
}
//recursively checks if the item at position "index" needs to be sorted up the heap to maintain the min-heap property
void heap::bubbleUp(int index) {
	if (index!= 1) {
		if (A[index] < A[index / 2]) {
			swap(index, (index / 2));
			bubbleUp(index / 2);
		}
	}
}

//swaps two elements in an array with each other
void heap::swap(int i1, int i2) {
  int temp = A[i1];
	A[i1] = A[i2];
	A[i2] = temp;
}
