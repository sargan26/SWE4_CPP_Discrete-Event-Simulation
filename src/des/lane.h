#pragma once
#include <queue>
#include "car.h"
#include "events.h"
#include "simulation.h"
#include <memory>

class Lane : public simulation {
private:
	bool isGreen = false;
	bool carLeaving = false;
	std::string direction;
	int phaseDuration = 1000 * 60; // 1 minute
	int printStatsInterval = 4000 * 60; // 4 minute
	int carCount = 0;
	unsigned int waitTimeMin = 0;
	unsigned int waitTimeMax = 0;
	unsigned int waitTimeAvg = 0;
	unsigned int avgCarCount = 0;
	std::vector<unsigned int> waitTimes;
	std::vector<unsigned int> carCountHistory;

	void printFirstEvent() const;

public:
	Lane(const std::string& dir) : direction(dir) {}
	void init();
	void print() const;


	// lane methodds
	bool getIsGreen() const { return isGreen; }
	std::string getDirection() const { return direction; }
	void toggleTrafficLight();
	
	// cars methods
	int getCarCount() const { return carCount; }
	unsigned int getAvgCarCount() const { return avgCarCount; }
	bool getCarLeaving() const { return carLeaving; }
	void addWaitTime(unsigned int waitTime) { waitTimes.push_back(waitTime); }
	void addCarCountHistory() { carCountHistory.push_back(carCount); }
	void setCarLeaving(bool carLeaving) { this->carLeaving = carLeaving; }
	void incrementCarCount() { carCount++; }
	void decrementCarCount() { carCount--; }

	// statistics
	int getWaitTimeMin() const { return waitTimeMin; }
	int getWaitTimeMax() const { return waitTimeMax; }
	int getWaitTimeAvg() const { return waitTimeAvg; }
	void updateStatistics();
	void printStatistics();
};