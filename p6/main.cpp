#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BinaryTree.h"



using namespace std;

/**	This program uses the Binary Tree defined in BinaryTree.h to count substrings of up to size 3 from an input file given by the user.	**
  *	It will generate a binary tree while reading from the source file. Once finished, it will traverse the tree to print out all of 	**
  *	the substrings as well as the number of times that they appear in the source file.							**/

fstream infile;

void fillTree() {
	BinaryTree * tree = new BinaryTree();	// create tree to be filled

	char c;			// char used to create char array of all a-zA-Z chars in the file
	vector<char> charray;		// array of all a-zA-Z chars in the file

	// grab all of the a-zA-Z chars in the file and put them into a vector
	while (infile.good()) {
		c = infile.get();
		if (infile.good()) {
			if (isalpha(c)) {
				charray.push_back(c);
			}
		}
	}
	// go through all the substrings of length 1-3 and insert them into the tree
	for (unsigned int i = 0; i < charray.size(); i++) {
		unsigned int j = 1;
		string s = "";	// used to hold the substrings
		s.push_back(charray[i]);

		// make sure not to go past the end of the array
		while (j < 4 && ((j + i) < charray.size())) {
			tree->insert(s);
			s.push_back(charray[i+j]);
			j++;

		}
		
	}

	cout << endl;

	tree->printTree();

	tree->~BinaryTree();

}


int main() {
	while (true) {
		cout << "Hello! Please enter the name of the file that you would like to run the program on.";
		cout << " It must be a .txt file. Do not include the extension, it will be automatically added." << endl;
		cout << "If you would ever like to exit the program, simply enter an empty line." << endl;

		string filename = "";

		// continue to prompt the user for a valid filename until they are successful.
		while (!infile.is_open()) {
			if (filename.compare("") != 0) {
				cout << "That filename couldn't be opened.";
				cout << " Please check to make sure that the file name is correct, and that you did not include the .txt extension." << endl;
			}
			// get filename from cin
			getline(cin, filename);

			// check for empty line, if so exit
			if (filename.compare("") == 0) {
				cout << "Exiting..." << endl;
				return 0;
			}
			filename += ".txt";

			infile.open(filename.c_str(), fstream::in);
		}

		// use other function here
		fillTree();

		cout << endl << endl;
		filename = "";
		infile.close();
	}
}

