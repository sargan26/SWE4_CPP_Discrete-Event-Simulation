#include <queue>
#include <memory>
#include "events.h"
#include "simulation.h"

simulation::simulation() : time(0), eventQueue() { }

void simulation::scheduleEvent(std::unique_ptr<event> newEvent) {
	eventQueue.push(std::move(newEvent));
}

void simulation::step() {
	std::unique_ptr<event> nextEvent = std::move(const_cast<std::unique_ptr<event>&>(eventQueue.top()));
	eventQueue.pop();
	time = nextEvent->time;
	nextEvent->processEvent();
}

void simulation::run() {
	while (!eventQueue.empty()) {
		step();
	}
}