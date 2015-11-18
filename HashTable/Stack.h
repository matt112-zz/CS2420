#pragma once

template <class T>
class Stack {
public:
	Stack();
	virtual ~Stack();
	bool empty();
	int size();
	T top();
	void push(T data);
	void pop();
private:
	struct Node {
		Node* next;
		T data;
		Node(const T& d) : data(d), next(nullptr) {};
	};

	Node* Top;
	int Size;
};


template <class T>
Stack<T>::Stack() {
	Top = nullptr;
	Size = 0;
}

template <class T>
Stack<T>::~Stack() {
	while(Top != nullptr) {
		Node* temp = Top;
		Top = Top->next;
		delete temp;
	}
}

template <class T>
bool Stack<T>::empty() {
	if(Top == nullptr) return true;
	else return false;
}

template <class T>
int Stack<T>::size() {
	return Size;
}

template <class T>
T Stack<T>::top() {
	return Top->data;
}

template <class T>
void Stack<T>::push(T data) {
	Node* temp = Top;
	Top = new Node(data);
	Top->next = temp;
	Size++;
}

template <class T>
void Stack<T>::pop() {
	Node* temp = Top;
	Top = Top->next;
	delete temp;
	Size--;
}
