/** 	Charles Qin	**
  *	8/7/14		**
  *	Project 6	**/

/**			This class defines a binary search tree, which holds strings of up to length 3, in alphabetical order.			**/

#ifndef TREE_H
#define TREE_H

#include <string>

using namespace std;

class BinaryTree {

private:

	// struct for treenodes. holds the string value and count as well as pointers to left and right nodes
	struct TreeNode  {
		string substring;
		int count;
		TreeNode * left;
		TreeNode * right;
	};

	TreeNode * root;	// points to the root node
	
	void destructHelper(TreeNode *);
	void insertHelp(string, TreeNode *);
	void printHelper(TreeNode *);
public:
	BinaryTree() {
		root = NULL;
	}

	~BinaryTree();

	/** insert first converts the input string to all caps.															**
	  * it then checks if a substring already exists in the tree. if so, increment the count of that node. if not, add a new node in the right location (alphabetical)	**/
	void insert(string);
	
	void printTree();

};

#endif
	

