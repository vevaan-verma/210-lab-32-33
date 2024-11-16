// COMSC-210 | Lab 32, 33 | Vevaan Verma
using namespace std;
#include <iostream>
#include <array>
#include <deque>
#include "Car.h"

/* FUNCTION PROTOTYPES */
void outputQueue(deque<Car>& queue);

/* CONSTANTS */
const int INITIAL_CARS = 2;
const int TIME_PERIODS = 20;
const int PAY_TOLL = 46;
const int JOIN_LANE = 39;
const int CHANGE_LANE = 15;

// main() is the entry point of the program and drives the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	srand(time(0)); // seed the random number generator

	array<deque<Car>, 4> queues; // create a deque of cars

	// initialize each queue with a random number of cars between 1 and 3
	for (int i = 0; i < 4; i++) {

		// generate a random number of cars between 1 and 3
		int numCars = rand() % 3 + 1;

		// add the cars to the queue
		for (int j = 0; j < numCars; j++)
			queues[i].push_back(Car());

	}

	cout << "Initial Queues:" << endl; // add "Initial" as a prefix to the output
	outputQueue(queues); // output initial queue

	for (int i = 1; i <= TIME_PERIODS; i++) { // run through all time periods

		// probabilities
		// 46% chance that the front car pays the toll
		// 39% chance that a new car joins the lane
		// 15% chance that a car changes lanes

		int percentage = rand() % 100 + 1; // generate random percentage

		cout << "Time: " << i << endl; // output time header

		for (int j = 0; j < queues.size(); j++) { // iterate through each lane

			deque<Car>& lane = queues[j]; // get the reference to current lane (so we can modify it)

			if (percentage <= PAY_TOLL) { // 46% chance (in this case) that front car pays toll and is removed from the queue

				Car car = lane.front(); // get the front car
				lane.pop_front(); // remove the front car
				cout << "Lane " << j + 1 << " | Car paid toll: "; // output operation prefix
				car.print(); // output the car that paid the toll

			}
		}

		outputQueue(queues); // output the queues

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