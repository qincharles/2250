/**		Charles Qin		**
  *		Project 5		**
  *		7/23/14			**/


#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <stack>

using namespace std;


/**		This program runs an algorithm that takes polish notation arithmetic expressions and calculates the result, using a stack.		**
  *		This works by reading through the given string from right to left, adding any numbers to the stack. Whenever an operator		**
  *		is encountered, pop the top two numbers from the stack and perform the operation, then push the result back on top.			**
  *		If there is ever less than two numbers on the stack, then that means that the expression is not a valid polish expression.		**/



// This function checks if a string is entirely numeric
bool digitsOnly(const string &s) {
	return s.find_first_not_of("0123456789") == string::npos;
}

// This function does the calculation given a string from the main function
void calculate(string expression) {
	// create stack for later use
	std::stack<int>	numbers;

	// split the expression into tokens by single space into a vector
	istringstream iss(expression);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(),back_inserter<vector<string> >(tokens));
	
	// go through the vector from right to left
	for (int i = tokens.size()-1; i >= 0; i--) {
		// check if the token is entirely numeric
		if (digitsOnly(tokens[i])) {
			numbers.push(atoi(tokens[i].c_str()));
		} else {
			// if it is not a number, then it must be one of the operators
			if (tokens[i].compare("+") == 0) {
				// if it is a plus, add the top two numbers in the stack
				if (numbers.size() < 2) {
					cout << "This is not a valid polish expression." << endl;
					return;
				}
				int n1 = numbers.top();
				numbers.pop();
				int n2 = numbers.top();
				numbers.pop();
				int result = n1 + n2;
				numbers.push(result);
				cout << n1 << " + " << n2 << " = " << result << endl;

			} else if (tokens[i].compare("-") == 0) {
				// if it is a minus, subtract the top two numbers in the stack
				if (numbers.size() < 2) {
					cout << "This is not a valid polish expression." << endl;
					return;
				}
				int n1 = numbers.top();
				numbers.pop();
				int n2 = numbers.top();
				numbers.pop();
				int result = n1 - n2;
				numbers.push(result);
				cout << n1 << " - " << n2 << " = " << result << endl;
			
			} else if (tokens[i].compare("*") == 0) {
				// if it is a *, multiply the top two numbers in the stack
				if (numbers.size() < 2) {
					cout << "This is not a valid polish expression." << endl;
					return;
				}
				int n1 = numbers.top();
				numbers.pop();
				int n2 = numbers.top();
				numbers.pop();
				int result = n1 * n2;
				numbers.push(result);
				cout << n1 << " * " << n2 << " = " << result << endl;
			
			} else if (tokens[i].compare("/") == 0) {
				// if it is a plus, add the top two numbers in the stack
				if (numbers.size() < 2) {
					cout << "This is not a valid polish expression." << endl;
					return;
				}
				int n1 = numbers.top();
				numbers.pop();
				int n2 = numbers.top();
				numbers.pop();
				if (n2 == 0) { 
					cout << "You cannot divide by 0." << endl;
					return;
				}
				int result = n1 / n2;
				numbers.push(result);
				cout << n1 << " / " << n2 << " = " << result << endl;
		
			} else {
				cout << "There is an invalid operator or number." << endl;
				return;
			}
		}
	}	

	cout << "The result of this expression is: " << numbers.top() << endl;

}


// The main function prompts the user for a polish arithmetic expression
int main() {
	while (true) {
		cout << endl;
		cout << "Hello! Please enter a polish expression for me to calculate." << endl;
		cout << "If you're not familiar with polish expressions, here are the rules: " << endl;
		cout << "The operator goes on the left of the numbers that it should operate on. Only the operators '+-*/' are allowed. Division results will be truncated." << endl;
		cout << "For example, to do (5 - 4) * 3, the polish expression would be * - 5 4 3. Remember to put spaces in between." << endl << endl;

		cout << "If you would like to exit the program, enter an empty line." << endl;

		string expression;
		getline(cin,expression);

		// check for exit command
		if (expression.compare("") == 0) { 
			cout << "Exiting..." << endl;
			return 0; 
		}

		// do the calculation - the calculate function will check if the given expression is valid or not
		cout << "Calculating..." << endl;
		calculate(expression);

	}

}
		





