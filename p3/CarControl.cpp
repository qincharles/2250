#include "car.h"

#include <iostream>
#include <string>

/**	Charles Qin	**
  *	7/9/14		**
  *	Project 3	**/


/**	This file uses the car class defined in car.h and car.cpp to allow the user to create a car and then take it for one ride.	**
  *	The program will prompt the user for a year and then a make that they want their car to be, and then they can accelerate	**
  *	and brake as they like. The program will ask the user if they would like to stop the ride and create a new car if the car	**
  *	is at a speed of 0.														**/



/**	This function takes a string input and checks if it is an empty string. If so, return true, otherwise return false. **/
bool checkExitCommand(string in) {

	// if the input is an empty string, exit the program
	if (in.empty()) {
        	cout << "Exiting..." << endl;
                return true;
        }

	return false;


}


/**	This function gives the user controls for how to accelerate and apply brakes on his car, so that the user can drive it.		**
  *	For ease of use, the user can stop driving at any point, even though in reality they would have to stop before they could exit.	**/

void drive(Car car) {
	cout << "Congratulations! You have created your new car, a " << car.getYear() << " " << car.getMake() << "!" << endl;
	cout << "Go ahead and drive it! To accelerate, input 'a'. To brake, input 'b'. If you want to exit the vehicle, input an empty line." << endl;

	// loop through, taking user input until the user inputs the exit command
	while (true) {
		string input = "";
		getline(cin,input);

		// check for the user's input
		if (input.empty()) {
			cout << "You have exited the vehicle. Now you can create a new vehicle back at the shop." << endl;
			return;
		} else if (input.compare("a") == 0) {
			car.accelerate();
		} else if (input.compare("s") == 0) {
			car.brake();
		} else {
			cout << "That input was not a valid command. Try again! Remember, 'a' to accelerate, 's' to brake, and an empty line to exit." << endl;
		}
		
		// let the user know the current vehicle speed
		cout << "You're currently driving at " << car.getSpeed() << "mph!" << endl;
	}

}

/**	The main function asks the user for car information and then creates the car, before sending the car data to the drive function. **/
int main() {
	// loop forever until the user inputs the exit command
	while (true) {
		cout << "Hello there! Here you can create the car of your dreams and drive it." << endl;
		cout << "Please enter the make of the car that you'd like. If at any point you'd like to leave, press Enter with an empty input line." << endl;
		string inmake = "";
		getline(cin,inmake);

		// check for exit command
		if (checkExitCommand(inmake)) {
			return 0;
		}
		
		cout << "Now, please enter the year of your new car." << endl;
		int inyear;
		string in = "";
                getline(cin,in);

		// check for exit command 
		if (checkExitCommand(in)) {
			return 0;
		}
 
                char * p;
 
                 // check for valid integer
                 strtol(in.c_str(), &p, 10);
                 // as long as the input is not a valid integer, continue to prompt the user for one
                 while (!(*p == 0)) {
                         cout << "Sorry, but that year was invalid. Please make sure that you enter an integer value!" << endl;
                         getline(cin,in);
                         strtol(in.c_str(), &p, 10);
                 }
 
                 // at this point, a valid year has been given. 
                 inyear = atoi(in.c_str());

		// now the user has given the data needed to create the car. do so
		Car car = Car(inyear, inmake);

		// let the user drive the car
		drive(car);

	}

}
