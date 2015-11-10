/*
 * AVL.h
 *
 *  Created on: Nov 7, 2015
 *      Author: matt
 */

#ifndef AVL_H_
#define AVL_H_

class AVL {
private:
	struct Node{
		int data;
		Node* left;
		Node* right;
		int height;

		Node(int d): data(d), left(nullptr), right(nullptr), height(1){};
	};

	int size;
	Node* root;

	void destroy(Node* root);
	Node* insert(Node* &root, int data);
	Node* remove(Node* &root, int data);
	Node* leftrotate(Node* root);
	Node* rightrotate(Node* root);
	bool search(Node* root, int data);
	void preorder(Node* root);
	void inorder(Node* root);
	void postorder(Node* root);
	void rebalance(Node* &root);
	int balance(Node* root);
	int height(Node* root);
	int max(Node* left, Node* right);
	void print(Node* root, int depth);
	Node* findMin(Node* root);
public:
	AVL();
	virtual ~AVL();
	void insert(int data);
	void remove(int data);
	bool search(int data);
	void preorder();
	void inorder();
	void postorder();
	int getsize();
	void print();
};

#endif /* AVL_H_ */
