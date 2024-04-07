#include "trafficSimulation.h"
#include "events.h"
#include <iostream>

TrafficSimulation::TrafficSimulation() : simulationInstance() {
	lanes[0] = std::make_unique<Lane>("North");
	lanes[1] = std::make_unique<Lane>("East");
	lanes[2] = std::make_unique<Lane>("South");
	lanes[3] = std::make_unique<Lane>("West");
}

void TrafficSimulation::initSimulation() {
	// Init lanes
	for (size_t i = 0; i < laneCount - 1; i++)
	{
		lanes[i]->init();
	}

	// Init simulation
	
}


void TrafficSimulation::printLanes() const {
	// Print lanes
	for (size_t i = 0; i < laneCount - 1; i++)
	{
		lanes[i]->print();
		std::cout << "\n";
	}
}