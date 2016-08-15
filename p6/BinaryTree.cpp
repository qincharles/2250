#include <iostream>
#include "BinaryTree.h"

using namespace std;

/**		This class implements the definition of a binary search tree that sorts strings by alphabetical order		**/


// helper for the destructor
void BinaryTree::destructHelper(TreeNode * rt) {
	if (rt->left != NULL) { destructHelper(rt->left); }
	if (rt->right != NULL) { destructHelper(rt->right); }
	delete rt;
}

// Destructor that deletes every item in the tree
BinaryTree::~BinaryTree() {
	if (root == NULL) { 
		delete root;
		return;
	 }
	destructHelper(root);
}


// helper for the insert function
void BinaryTree::insertHelp(string input, TreeNode * rt) {
	int equality = input.compare(rt->substring);	// get the comparison value - 0 means equal, <0 means input is lower, >0 means input is higher
	// check for equality first
	if (equality == 0) { 	// increment count and return
		rt->count++;
		return;
	}
	if (equality < 0) {	// recurse to the left side of root if it exists. if it doesn't exist, add a new node with count = 1
		if (rt->left != NULL) {	// recurse
			insertHelp(input,rt->left);
			return;
		}
		TreeNode * newnode = new TreeNode();
		newnode->count = 1;
		newnode->substring = input;
		newnode->left = NULL;
		newnode->right = NULL;
		rt->left = newnode;	// set the new node as this node's left
		return;
	}
	if (equality > 0) {	// recurse to the right side of root if it exists. if it doesn't exist add a new node with count = 1
		if (rt->right != NULL) {	// recurse
			insertHelp(input,rt->right);
			return;
		}
		TreeNode * newnode = new TreeNode();
		newnode->count = 1;
		newnode->substring = input;
		newnode->left = NULL;
		newnode->right = NULL;
		rt->right = newnode;	// set the new node as this node's right
		return;
	}
}

// function that first converts the input string to all caps, then checks if the string exists in the tree. if so, increment the node's count. if not, add a new node.
void BinaryTree::insert(string input) {
	string uppercase;
	for (unsigned int i = 0; i < input.size(); i++) {
		uppercase += toupper(input[i]);
	}
	if (root == NULL) {	// if root is empty, make root the first node
		root = new TreeNode();
		root->substring = uppercase;
		root->count = 1;
		return;
	}
	insertHelp(uppercase, root);


}

// helper for printTree
void BinaryTree::printHelper(TreeNode * rt) {
	if (rt->left != NULL) { printHelper(rt->left); }	// print left side first if it has one
	cout << rt->substring << ":" << rt->count << endl;	// print the root next
	if (rt->right != NULL) { printHelper(rt->right); }	// print the right side last
}


// function that traverses the tree in order, printing the substring and the count of each node with the format "A:1"
void BinaryTree::printTree() {
	if (root == NULL) {	// nothing in the tree
		cout << "Nothing in the tree." << endl;
		return;
	}
	printHelper(root);
}
