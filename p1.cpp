/**    Charles Qin	*

*	Project 1	*

*	6/23/14		*

*	This project takes an input string from cin and translates it into pig-latin. The specification for the translation		*
*	into pig-latin can be found in the description of the translate function. The project uses C_Strings instead of std::string.	*
*	The project will ask the user for sentences to translate until the user sends the exit code, which is an empty sentence.	**/




#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <vector>

using namespace std;

/** 	Translate function, takes a char* input and tokenizes it into words.								*
*	Each word then is translated into pig-latin. Words that begin with vowels simply add "way" at the end.				*
* 	Words that begin with consonants move the beginning consonant to the end of the word and then adds "ay" to the end.		**/

char * translate(char * input) {
	char * word;
	int length = 0;

	// set up the tokenizer
	word = strtok(input, " ,.-!?");
	
	vector<char *> words;

	// loop through the array
	while (word != NULL) {
		// do the translation
		word[0] = tolower(word[0]);

		// create copy of word that will be used to create the translated words
		char * word1 = new char [strlen(word) + 5];
		strcpy(word1,"");

		if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') {	// check for vowel

			// add "way" at the end for vowel starts
			strcat(word1,word);
			strcat(word1,"way");

		} else {											// not a vowel start

			// reorganize the word so that the consonant is at the end of the original word and then "ay" at the end
			char consonant = word[0];		
			word++;
			strcat(word1,word);
			word1[strlen(word)] = consonant;
			word1[strlen(word)+1] = '\0';
			strcat(word1,"ay");

		}
				
		// update length
		length += strlen(word1) + 1;	
	
		// update words
		word = word1;
		words.push_back(word);	


		// move on the next word
		word = strtok (NULL, " ,.-!?");
	}

	char * out = new char[length + 1];
	strcpy(out,"");

	// put the words vector together, with spaces in between
	for (int i = 0; i < words.size(); i++) {
		strcat(out,words[i]);
		strcat(out," ");
		delete words[i];
	}

	// capitalize the first letter of the sentence
	out[0] = toupper(out[0]);
	
	// done translating, return the output value
	return out;
 
}


/** 	Take input strings from the user and call the translate function. Then, print out the result. Continue to prompt the user until		*
*	they send the exit command, which is an empty sentence.											**/

int main(void) {
	const int maxchars = 251;

	// repeat asking the user for sentences to translate until they enter an empty sentence. This serves as an exit command.	
	while (true) {
		cout << "Type a sentence to be converted into pig-latin and press Enter. Maximum " << maxchars - 1 << " characters." << endl;
		cout << "If you want to quit, leave the line empty and press Enter." << endl;
		
		// get the input from the command line, getline requires a character limit.	
		char input[maxchars];
		cin.getline(input, maxchars);
		
		// check for empty string, which means exit command.
		if (strcmp(input,"") == 0) { return 0; }	

		// do the translation
		char * output = translate(input);
	
		// send the translated string to the output stream
		cout << output << endl << endl;
		delete [] output;	
	}

	return 0;
}

