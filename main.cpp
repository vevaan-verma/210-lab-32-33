// COMSC-210 | Lab 32 | Vevaan Verma
using namespace std;
#include <iostream>
#include <deque>
#include "Car.h"

/* FUNCTION PROTOTYPES */
void outputQueue(deque<Car>& queue);

/* CONSTANTS */
const int INITIAL_CARS = 2;
const int PAYS_TOLL_PROBABILITY = 55;

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

		if (percentage <= PAYS_TOLL_PROBABILITY) { // 55% chance that front car pays toll and is removed from the queue

			Car car = queue.front(); // get the front car
			queue.pop_front();
			cout << "Car paid toll: ";
			car.print(); // output the car that paid the toll

		} else { // 45% chance of a new car being added to the back of the queue

			Car newCar = Car(); // create a new car
			queue.push_back(newCar); // add a new car to the back of the queue
			cout << "Car joined lane: ";
			newCar.print(); // output the new car

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

	if (queue.empty()) { // if the queue is empty, output "Empty" and return

		cout << "  Empty" << endl << endl;
		return;

	}

	for (Car car : queue) {

		cout << "  "; // output indentation for formatting purposes
		car.print(); // print each car in the queue

	}

	cout << endl; // output blank line for formatting purposes

}