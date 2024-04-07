#pragma once

#include <queue>
#include <vector>
#include <memory>
#include "events.h"

class simulation {
public:
	simulation();
	void run();
	void step();

	void scheduleEvent(std::unique_ptr<event> newEvent);
	unsigned int time;

protected:
	std::priority_queue<std::unique_ptr<event>, 
						std::vector<std::unique_ptr<event> >, 
						eventComparator> 
	eventQueue;
};