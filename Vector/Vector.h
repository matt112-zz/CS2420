#pragma once

#include <iostream>

template <class T>
class Vector {
public:
	Vector();
	virtual ~Vector();
	bool empty();
	int size();
	void push_back(T data);
	void pop_back();
	void clear();
	T operator[](int index);
private:
	int Size = 0;
	int Capacity;
	T *array;
};

template <class T>
Vector<T>::Vector() {
	Capacity = 1;
	array = new T[Capacity];
}

template <class T>
Vector<T>::~Vector() {
	clear();
	delete [] array;
}

template <class T>
bool Vector<T>::empty() {
	if(size) return false;
	else return true;
}

template <class T>
int Vector<T>::size() {
	return size;
}

template <class T>
void Vector<T>::push_back(T data) {

	Size++;
}
