#pragma once
#include "simulation.h"

class storeSimulation : public simulation {
public:
	storeSimulation() : simulation(), freeChairs(35), profit(0.0) {}
	bool canSeat(unsigned int numberOfPeople);
	void order(unsigned int numberOfScoops);
	void leave(unsigned int numberOfPeople);
	double getProfit() { return profit; }

private:
	unsigned int freeChairs;
	double profit;

};

extern storeSimulation theSimulation;