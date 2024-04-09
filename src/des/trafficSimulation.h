#pragma once
#include "lane.h"

class TrafficSimulation {
private:
	static constexpr int laneCount = 4;
	std::unique_ptr<Lane> lanes[laneCount]; // 4 lanes in all directions

public: 
	TrafficSimulation();
	void init();
	void run();
	void print() const;
};