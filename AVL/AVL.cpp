/*
 * AVL.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: matt
 */

#include "AVL.h"
#include <iostream>

using namespace std;


AVL::AVL() {
	root = nullptr;
	size = 0;
}

AVL::~AVL() {
	destroy(root);
}

void AVL::destroy(Node* root) {
	if(root) {
			destroy(root->left);
			destroy(root->right);
			cout <<  "Destroying " << root->data << endl;
			delete root;
			root = nullptr;
		}
}
void AVL::insert(int data) {
	insert(root, data);
}

AVL::Node* AVL::insert(Node* &root, int data) {
	if(root) {
		if(data < root->data) {
			root->left = insert(root->left, data);
		}
		else if(data > root->data){
			root->right = insert(root->right, data);
		}
		else {
			cout << "Duplicate data is not allowed" << endl;
		}
	}
	else {
		root = new Node(data);
	}

	return root;
}

/*void AVL::remove() {

}

AVL::Node* AVL::leftRotate() {

}

AVL::Node* AVL::rightRotate() {

}

bool AVL::search() {

}

void AVL::display() {

}*/

void AVL::preorder() {
	preorder(root);
}
void AVL::preorder(Node* &root) {
	if(root) {
		cout << root->data << endl;
		preorder(root->left);
		preorder(root->right);
	}
}

int AVL::balance(Node* root) {
	return root->left->data - root->right->data;
}

