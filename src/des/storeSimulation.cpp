#include "storeSimulation.h"
#include <iostream>

storeSimulation theSimulation;

bool storeSimulation::canSeat(unsigned int numberOfPeople) {

	std::cout << "Time: " << time;
	std::cout << " group of " << numberOfPeople << " customers arrives";

	if (numberOfPeople <= freeChairs) {
		std::cout << " is seated\n";
		freeChairs -= numberOfPeople;
		return true;
	}
	else {
		std::cout << " no room, they leave\n";
		return false;
	}
}

void storeSimulation::order(unsigned int numberOfScoops) {
	std::cout << "Time: " << time << " serviced order for " << numberOfScoops << "\n";
	profit += 0.35 * numberOfScoops; // 35 cents per scoop
}

void storeSimulation::leave(unsigned int numberOfPeople) {
	std::cout << "Time: " << time << " group of size " << numberOfPeople << " leaves\n";
	freeChairs += numberOfPeople;
}

