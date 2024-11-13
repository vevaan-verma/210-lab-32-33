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

/* FUNCTION PROTOTYPES */
void outputQueue(deque<Car>& queue);

/* CONSTANTS */
const int INITIAL_CARS = 2;

// main() is the entry point of the program and drives the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	srand(time(0)); // seed the random number generator

	deque<Car> queue(INITIAL_CARS); // createa a deque of cars with 2 initial cars

	cout << "Initial "; // add "Initial" as a prefix to the output
	outputQueue(queue); // output initial queue

	int time = 1; // initialize time to 0

	while (!queue.empty()) { // loop while the queue is not empty

		// generate random percentage
		int percentage = rand() % 100 + 1;

		cout << "Time: " << time << " | Operation: "; // output time and operation prefix

		if (percentage <= 55) { // 55% chance that front car pays toll and is removed from the queue

			Car car = queue.front(); // get the front car
			queue.pop_front();

		} else { // 45% chance of a new car being added to the back of the queue

			Car newCar = Car(); // create a new car
			queue.push_back(newCar); // add a new car to the back of the queue

		}

		outputQueue(queue); // output the queue
		time++;

	}

	return 0;

}

// outputQueue() outputs the contents of the queue
// arguments: deque<Car>& - the queue to output
// returns: void
void outputQueue(deque<Car>& queue) {

	cout << "Queue:" << endl; // output queue header

	for (Car car : queue)
		cout << "  [" << car.year << " " << car.manufacturer << " (" << car.transponder << ")]" << endl;

	cout << endl; // output blank line for formatting purposes

}