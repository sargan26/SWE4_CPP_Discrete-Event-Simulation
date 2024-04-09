#include "trafficSimulation.h"
#include "events.h"
#include <iostream>

TrafficSimulation::TrafficSimulation() {
	lanes[0] = std::make_unique<Lane>("North");
	lanes[1] = std::make_unique<Lane>("East");
	lanes[2] = std::make_unique<Lane>("South");
	lanes[3] = std::make_unique<Lane>("West");
}

void TrafficSimulation::init() {
	// Init lanes
	for (size_t i = 0; i < laneCount; i++)
	{
		lanes[i]->init();
	}
}

void TrafficSimulation::run() {
	// Init lanes
	for (size_t i = 0; i < laneCount; i++)
	//for (size_t i = 0; i < 1; i++)
	{
		lanes[i]->run();
	}
}


void TrafficSimulation::print() const {
	// Print lanes
	for (size_t i = 0; i < laneCount ; i++)
	{
		lanes[i]->print();
		std::cout << "\n";
	}
}