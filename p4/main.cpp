#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"

using namespace std;

/**	This program uses the dynamic Stack defined in Stack.h to test a text file for matching blocks.	**
  *	These blocks are defined by delimiters {}, (), and []. The text file will pass the test if	**
  *	the opening and closing delimiters create blocks that are entirely separate from other blocks	**
  *	or are entirely nested. For example, {I am [silly]} would pass because one block is nested	**
  * 	in the other. However, {I am [silly}] would fail because they are interlocked.			**
  *													**
  *	This was not specified in the assignment description, but it will not fail any text file that	**
  *	has any character that are not inside of blocks (e.g. l[ook] is fine, (l[ook]) is fine).	**/

fstream infile;

// this function tests the input file for proper delimitization
void test() {
	Stack * stack = new Stack();	// create stack that will hold the characters
	char c;				// create char that will hold characters read in from the file
	int cnum = 1;			// create int that holds the character number of the current character
	int lnum = 1;			// create int that holds the line number of the current character
	while (infile >> noskipws >> c) {
		// go through the characters in the file, skipping whitespace. if a fail condition is met, print out appropriate message and exit.
		
		// check for new line
		if (c == '\n') {
			lnum++;
			cnum = 0;
		}

		// check for an opening delimiter. if it is one, push onto the stack
		if ((c == '[') || (c == '{') || (c == '(')) {
			stack->push(c);
		//check for a closing delimiter. If it is one, check the top of the stack. It must be the opening of the same type. Then pop the top off.
		} else if (c == ']') {
			char c1;
			stack->pop(c1);
			if (c1 != '[') {
				// error found!
				cout << "Mismatched delimiter found at line: " << lnum << ", character: " << cnum << ", of delimiter type: '" << c << "'. Test failed." << endl;
				delete stack;
				return;
			}
		} else if (c == '}') {
			char c1;
			stack->pop(c1);
			if (c1 != '{') {
				// error found!
				cout << "Mismatched delimiter found at line: " << lnum << ", character: " << cnum << ", of delimiter type: '" << c << "'. Test failed." << endl;
				delete stack;
				return;
			}
		} else if (c == ')') {
			char c1;
			stack->pop(c1);
			if (c1 != '(') {
				// error found!
				cout << "Mismatched delimiter found at line: " << lnum << ", character: " << cnum << ", of delimiter type: '" << c << "'. Test failed." << endl;
				delete stack;
				return;
			}
		}
		cnum++;
	}

	// if this point is reached, then no errors were found! Hooray! let the user know and return to main
	cout << "No errors found!" << endl;
	delete stack;
	return;
				
}

int main() {
	while (true) {
		cout << "Hello! Please enter the name of the file that you would like to test.";
		cout << " It must be a .txt file. Do not include the extension, it will be automatically added." << endl;
		cout << "If you would ever like to exit the program, enter an empty line." << endl;
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
			
		cout << "Testing..." << endl;
		test();
		infile.close();	
	}

}
