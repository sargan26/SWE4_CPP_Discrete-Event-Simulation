#include "lane.h"
#include <iostream>
#include "random_utils.h"

void Lane::init() {
	unsigned int dayDuration = 24 * 60 * 60 * 1000; // 24 hours in milliseconds
	unsigned int currentTime = 0;

	while (currentTime < dayDuration) {
		unsigned int interval = get_random_integer_exponential(0.0001); // 10 seconds average
		currentTime += interval;

		if (currentTime >= dayDuration) {
			break;
		}

		Car car;
		auto event = std::make_shared<ArriveCarEvent>(currentTime, car);
		events.push(event);
		carCount++;
	}
}

void Lane::print() const {
    std::cout << "Lane direction: " << direction << std::endl;
    std::cout << "Car count: " << carCount << std::endl;
    std::cout << "First five events: " << std::endl;

    auto copyQueue = events;
    int count = 0;
    while (!copyQueue.empty() && count < 5) {
        auto event = copyQueue.front();
        copyQueue.pop();
        std::cout << event->toString() << std::endl;
        count++;
    }
}