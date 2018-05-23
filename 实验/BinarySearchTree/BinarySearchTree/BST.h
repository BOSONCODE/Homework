#pragma once
#include <iostream>
using namespace std;

struct node {
	node *LeftChild, *RightChild;
	int value;
	node() {
		LeftChild = RightChild = NULL;
	}
};

class BST {
private:
	node *root;
public:
	BST() { root = NULL; }
	void CreateBBST(int a[], int n);
	node* Search(int key, int &CmpTime);
	void BuildTree(node *&root, int a[], int low, int high);
	void InOrder(node *root);
	void OutputData() { InOrder(root); }
};


