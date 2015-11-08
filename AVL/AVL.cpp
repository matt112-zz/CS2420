/*
 * AVL.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: matt
 */

#include "AVL.h"
#include <iostream>
#include <iomanip>

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

	int bal = balance(root); // if negative balance, right subtree is heavy. if positive balance, left subtree is heavy
	if(bal > 1) {  //left heavy
		if(balance(root->left) > 0) {  //double left heavy
			return root = rightrotate(root);
		}
		else{
			root->left = leftrotate(root->left);
			return root = rightrotate(root);
		}
	}
	else if(bal < -1) { //right heavy
		if(balance(root->right) < 0) {  //double right heavy
			return root = leftrotate(root);
		}
		else{
			root->right = rightrotate(root->right);
			return root = leftrotate(root);
		}
	}

	root->height = max(root->left, root->right) + 1;
	return root;
}

void AVL::remove() {

}

AVL::Node* AVL::leftrotate(Node* root) {
	Node* newroot = root->right;
	root->right = newroot->left;
	newroot->left = root;

	root->height = max(root->left,root->right) + 1;
	newroot->height = max(newroot->left, newroot->right) + 1;

	return newroot;
}

AVL::Node* AVL::rightrotate(Node* root) {
	Node* newroot = root->left;
	root->left = newroot->right;
	newroot->right = root;

	root->height = max(root->left,root->right) + 1;
	newroot->height = max(newroot->left, newroot->right) + 1;

	return newroot;
}

bool AVL::search() {

}

void AVL::display() {

}

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
	return height(root->left) - height(root->right);
}


int AVL::height(Node* root) {
	if(root) return root->height;
	else return 0;
}


int AVL::max(Node* left, Node* right) {
	return (height(left) > height(right))? height(left) : height(right);
}

void AVL::print()
{
    if(root)
    {
        print(root, 0);
    }
}
void AVL::print(Node* root, int depth)
{
    cout << setw(4*depth) << "";

    if(root) {

        if(root->left == nullptr && root->right == nullptr)
        {
            cout << root->data << " [leaf]" << endl;
        }
        else
        {
            cout << root->data << endl;
            print(root->left, depth+1);
            print(root->right, depth+1);
        }
    }
    else {
        cout << "[Empty]" << endl;
    }
}
