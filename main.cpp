// COMSC-210 | Lab 32 | Vevaan Verma
using namespace std;
#include <iostream>
#include <deque>
//#include "Car.h" (the file for Car.h isn't accessible currently, so I created a temporary struct below)

struct Car {

	string manufacturer;
	int transponder;
	int year;

	Car() {

		manufacturer = "Toyota";
		transponder = 1001;
		year = 2000;

	}
};

/* CONSTANTS */
const int INITIAL_CARS = 2;

// main() is the entry point of the program and drives the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	deque<Car> queue = deque<Car>(INITIAL_CARS);

	int time = 1; // initialize time to 0

	while (!queue.empty()) { // loop while the queue is not empty

		// generate random percentage
		int percentage = rand() % 100 + 1;

		time++;

	}

	return 0;

}