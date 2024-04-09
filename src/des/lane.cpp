#include "lane.h"
#include <iostream>
#include "random_utils.h"
#include <algorithm>
#include <numeric>

void Lane::init() {
	//unsigned int dayDuration = 24 * 60 * 60 * 1000 + 1; // 24 hours in milliseconds
	unsigned int dayDuration = 4 * 60 * 1000 + 1; // 4 Minutes in milliseconds
	unsigned int currentTime = phaseDuration;

	while (currentTime < dayDuration) {
		auto switchEvent = std::make_unique<TrafficLightSwitchEvent>(currentTime, *this);
		scheduleEvent(std::move(switchEvent));
		currentTime += phaseDuration;
	}

	currentTime = printStatsInterval;
	while (currentTime < dayDuration) {
		auto printEvent = std::make_unique<PrintStatisticsEvent>(currentTime, *this);
		auto exportEvent = std::make_unique<ExportStatisticsEvent>(currentTime, *this);
		scheduleEvent(std::move(printEvent));
		scheduleEvent(std::move(exportEvent));
		currentTime += printStatsInterval;
	}

	currentTime = 0;
	while (currentTime < dayDuration) {
		unsigned int interval = get_random_integer_exponential(0.0001); // 10 seconds average
		currentTime += interval;

		if (currentTime >= dayDuration) {
			break;
		}

		Car car;
		auto event = std::make_unique<ArriveCarEvent>(currentTime, car, *this);
		scheduleEvent(std::move(event));
	}
}

void Lane::print() const {
    std::cout << "Lane direction: " << direction << std::endl;
    std::cout << "Car count: " << carCount << std::endl;
	std::cout << "Avg car count: " << avgCarCount << std::endl;
	std::cout << "Min wait time: " << waitTimeMin << std::endl;
	std::cout << "Max wait time: " << waitTimeMax << std::endl;
	std::cout << "Avg wait time: " << waitTimeAvg << std::endl;
    std::cout << "First event: " << std::endl;
	printFirstEvent();
}

void Lane::printFirstEvent() const {
	if (!eventQueue.empty()) {
		const auto& event = eventQueue.top();

		std::cout << event->toString() << std::endl;
	}
	else {
		std::cout << "Event queue is empty." << std::endl;
	}
}

void Lane::toggleTrafficLight() {
	isGreen = !isGreen;
}

void Lane::updateStatistics() {
	double sumCarCount = std::accumulate(carCountHistory.begin(), carCountHistory.end(), 0.0);
	avgCarCount = sumCarCount / carCountHistory.size();

	waitTimeMin = *std::min_element(waitTimes.begin(), waitTimes.end());
	waitTimeMax = *std::max_element(waitTimes.begin(), waitTimes.end());

	double sumWaitTime = std::accumulate(waitTimes.begin(), waitTimes.end(), 0.0);
	waitTimeAvg = sumWaitTime / waitTimes.size();
}

void Lane::printStatistics() {
	updateStatistics();

	std::cout << "Lane direction: " << direction << std::endl;
	std::cout << "Car count: " << carCount << std::endl;
	std::cout << "Avg car count: " << avgCarCount << std::endl;
	std::cout << "Min wait time: " << waitTimeMin << std::endl;
	std::cout << "Max wait time: " << waitTimeMax << std::endl;
	std::cout << "Avg wait time: " << waitTimeAvg << std::endl << std::endl;
}