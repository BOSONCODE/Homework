#ifndef BOSON
#define BOSON
#include "BST.h"
#include <iostream>

void BST::CreateBBST(int a[], int n) {
	BuildTree(root, a, 0, n-1);

}

void BST::BuildTree(node *&root, int a[], int low, int high){
	if (low > high)	return ;
	root = new node;
	root->value = a[(low + high) / 2];
    BuildTree(root->LeftChild, a, low, (low + high) / 2 - 1);
	BuildTree(root->RightChild, a, (low + high) / 2 + 1, high);
}


node* BST::Search(int key, int &CmpTime) {
	node *rt = root;
	while (rt != NULL) {
		++CmpTime;
		if (rt->value > key) rt = rt->LeftChild;
		else if (rt->value < key) rt = rt->RightChild;
		else return rt;
	}
	return NULL;
}

void BST::InOrder(node *root) {
	if (root == NULL) { return; }
	InOrder(root->LeftChild);
	cout << root->value << endl;
	InOrder(root->RightChild);
}
#endif