#pragma once
#include "simulation.h"
#include "lane.h"

class TrafficSimulation {
private:
	static constexpr int laneCount = 4;
	simulation simulationInstance;
	std::unique_ptr<Lane> lanes[laneCount]; // 4 lanes in all directions

public: 
	TrafficSimulation();
	void initSimulation();
	void printLanes() const;
};