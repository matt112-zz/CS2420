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
	cout << "Inserting " << data << " into the AVL Tree" << endl;
	insert(root, data);
}

AVL::Node* AVL::insert(Node* &root, int data) {
	if(root == nullptr) {
		return root = new Node(data);
	}
	if(data < root->data) {
		root->left = insert(root->left, data);
	}
	else if(data > root->data){
		root->right = insert(root->right, data);
	}
	else {
		cout << "Duplicate data is not allowed" << endl;
	}

	int balance = height(root->left) - height(root->right); // if negative balance, right subtree is heavy. if positive balance, left subtree is heavy
	if(balance > 1) {  //left heavy
		if(height(root->left->left) > height(root->left->right)) {  //double left heavy
			return root = rightrotate(root);
		}
		else{
			root->left = leftrotate(root->left);
			return root = rightrotate(root);
		}
	}
	else if(balance < -1) { //right heavy
		if(height(root->right->right) > height(root->right->left)) {  //double right heavy
			return root = leftrotate(root);
		}
		else{
			root->right = rightrotate(root->right);
			return root = leftrotate(root);
		}
	}
	else {
		cout << "Node with element " << root->data << " is balanced" << endl;
	}
	root->height = max(root->left, root->right) + 1;
	return root;
}

void AVL::remove() {

}

AVL::Node* AVL::leftrotate(Node* root) {
	Node* temp = root;
	root = root->right;
	root->left = temp;

	temp->height = max(root->left,root->right) + 1;
	root->height = max(root->left, root->right) + 1;

	return root;
}

AVL::Node* AVL::rightrotate(Node* root) {
	Node* temp = root;
	root = root->left;
	root->right = temp;

	temp->height = max(root->left,root->right) + 1;
	root->height = max(root->left, root->right) + 1;

	return root;
}

bool AVL::search() {

}

void AVL::display() {

}

void AVL::preorder() {
	pre
	order(root);
}
void AVL::preorder(Node* &root) {
	if(root) {
		cout << root->data << endl;
		preorder(root->left);
		preorder(root->right);
	}
}

int AVL::balance(Node* root) {
	return height(root->left) - height(root->right);
}


int AVL::height(Node* root) {
	if(root) return root->height;
	else return 0;
}


int AVL::max(Node* left, Node* right) {
	return (height(left) > height(right))? height(left) : height(right);
}
