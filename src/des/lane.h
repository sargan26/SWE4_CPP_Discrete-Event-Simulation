#pragma once
#include <queue>
#include "car.h"
#include "trafficLight.h"
#include "events.h"
#include <memory>

class Lane {
private:
	std::queue<std::shared_ptr<event>> events;
	TrafficLight light;
	std::string direction;
	int carCount = 0;

public:
	Lane(const std::string& dir) : direction(dir) {}
	void init();
	void print() const;

};