#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

/**	Charles Qin	**
  *	7/9/14		**
  *	Project 3	**/



/**	This class defines the data and member functions of a car class. The car will contain information about its year and make, as well as its speed.	**
  *	The class also defines member functions accelerate and brake, which increase and decrease the speed of the car by 5, respectively.			**/

class Car {

private:

int yearModel;
string make;
int speed;

Car () {}	// default constructor


public:

Car(int year, string mke); 	// constructor

int getYear() { return yearModel; }			// getter for the year of the car
string getMake() { return make; }			// getter for the make of the car
int getSpeed() { return speed; }			// getter for the speed of the car

void accelerate(); 			// increase the speed of the car by 5
void brake();				// decrease the speed of the car by 5


};




#endif
