/**		Charles Qin		**
  *		7/3/14			**
  *		Project 2		**


  *		This program takes file names and decryption keys from user input, then checks the file name for validity. 	**
  *		If valid, the program reads from the input file by byte. The encryption scheme is very simple - merely		**
  *		add the encryption key to each byte. In this case, subtract the key's value.					**
  *																**
  *		The program will also write the new, decrypted byte to an output file of the extension ".restored" with the	**
  *		same name as the input file.	NOTE: This program is essentially the same as encrypt, it merely subtracts.	**/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>




using namespace std;

ifstream in;
ofstream out;
unsigned int size = 0;		// this will keep track of the size of the input file
int keyvalue = 0;


/**	The decrypt function reads through each byte from the input file, subtracts the encryption key, then writes to the output file. **/

int decrypt(string filename) {

	// open a new ofstream with the same name as the input file but new extension
	istringstream iss(filename);
	string shortname = "";
	std::getline(iss, shortname, '.');
	
	out.open((shortname + ".restored").c_str());

	// set up a byte array to read into
	char * indata = new char[size+1]; 	// add the +1 for the end
	in.read(indata, size);			// do the read
	indata[size] = '\0';			// set the end byte

	// read through the byte array and subtract the encryption key to each byte before writing to the output stream
	for (unsigned int i = 0; i < strlen(indata); i++) {
		// only encrypt the actual bytes, not the '\0' at the end
		if (i == (strlen(indata) - 1)) {
			out << (char) indata[i];
		} else {
			out << (char) (indata[i] - (char)keyvalue);
		}
	}

	out.close();	// close the output stream

	cout << "Done decrypting!" << endl;

	return 0;

}



/**	The main function prompts the user for an input file. It checks for validity - if not, continues to prompt user for file.	**
  *	If the file is valid, then prompt the user for an encryption key of integer type. Checks for valid integer, if not,		**
  *	continue to ask until a valid integer input is given. Then, pass the key to the decrypt function. Let the user know		**
  *	when the process is complete and then reset. An empty line entry from the user will exit the program.				**/

int main () {
	while(true) {
	
		// ask the user to input an input filename
		cout << "Please type the name of the input file you'd like to decrypt. Please include the .encrypted extension. "
				<< "If at any time you'd like to exit the program, press enter with an empty line." << endl;
	
		string filename = "";		// store the filename
	
		// check if the file is valid
		while (!in.is_open()) {
			getline(cin,filename);
			istringstream iss(filename);
			string extension = "";
			std::getline(iss, extension, '.');
			std::getline(iss, extension, '.');

			// check for exit command
			if (filename.empty()) {
				cout << "Exiting..." << endl;
				return 0;
			}

			// check for file type
			if (extension.compare("encrypted") == 0) {
				in.open(filename.c_str(),ios::in|ios::binary);
				if (!in.is_open()) {
					// if not open, tell the user that the file was not correct and retry.
					cout << "Sorry, but that filename was invalid. Make sure that you have used the correct extension and location of the file and try again!" << endl;
				}

			} else {
				cout << "Sorry, but that file was not of the required '.encrypted' type. Please enter a filename of that type." << endl;
			}


		}
	
		// at this point, a valid file has been given. Update the size of the file. Now, ask for an integer value encryption key
		in.seekg(0,ios::end);
		size = in.tellg();
		in.seekg(0,ios::beg);

		cout << "Great! Now please input a positive integer value encryption key." << endl;
		string key = "";
		getline(cin,key);
		
		// if the input is an empty string, exit the program
		if (key.empty()) {
			cout << "Exiting..." << endl;
			return 0;	
		}
	
		char * p;
	
		// check for valid integer
		strtol(key.c_str(), &p, 10);
		// as long as the input is not a valid integer, continue to prompt the user for one
		while (!(*p == 0)) {
			cout << "Sorry, but that key was invalid. Please make sure that your encryption key is an integer value and try again!" << endl;
			getline(cin,key);
			strtol(key.c_str(), &p, 10);
		}

		// at this point, a valid key has been given. set the value of the variable, then call decrypt. Any further messages to the user will be sent from the decrypt function
		keyvalue = atoi(key.c_str());
		decrypt(filename);
		in.close();	// close the input stream

	}

}
