// COMSC-210 | Lab 32, 33 | Vevaan Verma
using namespace std;
#include <iostream>
#include <array>
#include <deque>
#include "Car.h"

/* FUNCTION PROTOTYPES */
void outputQueues(array<deque<Car>, 4>& queue);

/* CONSTANTS */
const int TIME_PERIODS = 20;
const int PAY_TOLL = 46;
const int JOIN_LANE = 39;
const int CHANGE_LANE = 15;
const int EMPTY_LANE_ENTER = 50;

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
	outputQueues(queues); // output initial queue

	for (int i = 1; i <= TIME_PERIODS; i++) { // run through all time periods

		// probabilities
		// 46% chance that the front car pays the toll
		// 39% chance that a new car joins the lane
		// 15% chance that a car changes lanes

		int percentage = rand() % 100 + 1; // generate random percentage

		cout << "Time: " << i << endl; // output time header

		for (int j = 0; j < queues.size(); j++) { // iterate through each lane

			deque<Car>& lane = queues[j]; // get the reference to current lane (so we can modify it)

			if (!lane.empty()) { // make sure the lane isn't empty, as different operations can't be performed on an empty lane

				if (percentage <= PAY_TOLL) { // 46% chance (in this case) that front car pays toll and is removed from the queue

					Car car = lane.front(); // get the front car
					lane.pop_front(); // remove the front car
					cout << "Lane " << j + 1 << " | Car paid toll: "; // output operation prefix
					car.print(); // output the car that paid the toll

				} else if (percentage <= JOIN_LANE) { // 39% chance (in this case) of a new car being added to the back of the queue

					Car newCar = Car(); // create a new car
					lane.push_back(newCar); // add a new car to the back of the queue
					cout << "Lane " << j + 1 << " | Car joined lane : "; // output operation prefix
					newCar.print(); // output the new car

				} else { // 15% chance (in this case) of the rear car changing lanes to a different lane they aren't in

					int newLane = (j + (rand() % 3 + 1)) % queues.size(); // generate a random lane excluding the current lane to move to
					Car car = lane.back(); // get the rear car
					lane.pop_back(); // remove the rear car
					queues[newLane].push_back(car); // add the rear car to the rear of the new lane
					cout << "Lane " << j + 1 << " | Car changed lanes: "; // output operation prefix
					car.print(); // output the car that changed lanes

				}
			} else { // lane is empty

				if (percentage <= EMPTY_LANE_ENTER) { // 50% chance (in this case) of a new car being added to the back of the queue

					Car newCar = Car(); // create a new car
					lane.push_back(newCar); // add a new car to the back of the queue
					cout << "Lane " << j + 1 << " | Car joined lane: "; // output operation prefix
					newCar.print(); // output the new car

				} else { // 50% chance (in this case) of no operation

					cout << "Lane " << j + 1 << " | No operation" << endl; // output no operation message

				}
			}
		}

		outputQueues(queues); // output the queues

	}

	return 0;

}

// outputQueues() outputs the queues of cars
// arguments: array<deque<Car>, 4>& - the array of queues of cars
// returns: void
void outputQueues(array<deque<Car>, 4>& queues) {

	for (int i = 0; i < queues.size(); i++) { // iterate through each lane

		cout << "Lane " << i << " Queue:" << endl; // output lane header
		deque<Car> lane = queues[i]; // get the lane

		if (lane.empty()) { // if the lane is empty, output "  Empty" and return

			cout << "    Empty" << endl;
			continue;

		}

		for (Car car : lane) {

			cout << "    "; // output indentation for formatting purposes
			car.print(); // print each car in the lane

		}
	}

	cout << endl; // output blank line for formatting purposes

}