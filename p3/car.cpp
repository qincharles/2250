#include "car.h"




/**	Charles Qin	**
  *	7/9/14		**
  *	Project 3	**/



/**	This file is the source file for the car class. As defined in the header file, the car contains data about the year, make and speed of the car.	**
  *	This source file defines the constructor for the car, which will take the year and make of the car as input, and set the speed to 0.		**
  *	It also defines the accelerate and brake member functions, which add and subtract 5 from the speed of the car, respectively.			**/

// constructor
Car::Car(int year, string mke) {
	yearModel = year;
	make = mke;
	speed = 0;
	return;
}


// accelerate
void Car::accelerate() {
	speed += 5;
	return;
}

// brake
void Car::brake() {
	if (speed > 5) {
		speed -= 5;
	} else {
		speed = 0;
	}
	return;
}



