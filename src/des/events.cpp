#include "events.h"
#include "storeSimulation.h"
#include "random_utils.h"
#include "helper_functions.h"
#include <random>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "lane.h"

// Event
event::event(unsigned int t) : time(t)
{ }

// --- Event subclasses ---

// --- Intersection Events
void ArriveCarEvent::processEvent()  {
    lane.incrementCarCount();
    if (lane.getIsGreen()) {
        if (lane.getCarCount() == 1) {
            //car can leave immediately
			lane.scheduleEvent(std::make_unique<LeaveCarEvent>(time, lane, 0));
        }
        else {
            if (!lane.getCarLeaving()) {
                // car has to wait
                lane.setCarLeaving(true);
                unsigned int leaveDuration = get_random_integer_normal(3000, 500);
                lane.scheduleEvent(std::make_unique<LeaveCarEvent>(time + leaveDuration, lane, leaveDuration));
            }
        }
    }

    std::cout << this->toString() << "\n";
}

std::string ArriveCarEvent::toString() const {
    std::ostringstream stream;
    stream << "ArriveCarEvent: Time=" << formatTime(time) << " " << car.toString() << ", CarCount=" << lane.getCarCount();
    return stream.str();
}

void LeaveCarEvent::processEvent() {
    if (lane.getIsGreen()) {
	    lane.decrementCarCount();
		lane.addWaitTime(leaveDuration);
    }
    lane.setCarLeaving(false);    
	std::cout << this->toString() << "\n";
}

std::string LeaveCarEvent::toString() const {
    std::ostringstream stream;
    if (lane.getIsGreen()) {
        stream << "LeaveCarEvent:  Time=" << formatTime(time) << " car left, CarCount=" << lane.getCarCount();
    }
    else {
        stream << "LeaveCarEvent:  Time=" << formatTime(time) << " cancelled because traffic light is red, CarCount=" <<lane.getCarCount();
    }
    return stream.str();
}

void TrafficLightSwitchEvent::processEvent() {
    lane.toggleTrafficLight();
    lane.addCarCountHistory();
    std::cout << this->toString() << "\n"; // print after toggling, else false information!
}

std::string TrafficLightSwitchEvent::toString() const {
    std::ostringstream stream;
    stream << "TrafficLightSwitchEvent: Time=" << formatTime(time) << ", switched to "
        << (lane.getIsGreen() ? "green" : "red");
    return stream.str();
}

void PrintStatisticsEvent::processEvent() {
    std::cout << this->toString() << "\n";
    lane.printStatistics();
}

std::string PrintStatisticsEvent::toString() const {
    std::ostringstream stream;
    stream << "\nPrintStatisticsEvent: Time=" << formatTime(time);
    return stream.str();
}

void ExportStatisticsEvent::processEvent() {
    lane.updateStatistics();
    std::string filePath = "lane_" + lane.getDirection() + "_statistics.csv";
    std::ofstream fileCSV(filePath, std::ios::app);

    if (fileCSV.is_open()) {
        fileCSV << formatTime(time) << ","
            << lane.getWaitTimeMin() << ","
            << lane.getWaitTimeMax() << ","
            << lane.getWaitTimeAvg() << ","
            << lane.getAvgCarCount() << "\n";

        fileCSV.close();
        std::cout << this->toString() << "\n";
    }
    else {
		std::cerr << "Error: Could not open file " << filePath << " for writing." << std::endl;
	}
}

std::string ExportStatisticsEvent::toString() const {
    std::ostringstream stream;
    stream << "ExportStatisticsEvent: Time=" << formatTime(time) << ", statistics exportet in CSV.";
    return stream.str();
}


// --- IceStore Events
// Arrive Event
arriveEvent::arriveEvent(unsigned int t, unsigned int groupSize) : event(t), size(groupSize)
{ }

void arriveEvent::processEvent() {

    if (theSimulation.canSeat(size))
        theSimulation.scheduleEvent(std::make_unique<orderEvent>(time + 1 + get_random_integer(0, 4), size));
}

std::string arriveEvent::toString() const {
    return "arriveEvent: ";
}

// Order Event
orderEvent::orderEvent(unsigned int t, unsigned int groupSize) : event(t), size(groupSize)
{ }

void orderEvent::processEvent() {

    // Each person orders some number of scoops.
    for (unsigned int i = 0; i < size; i++)
        theSimulation.order(1 + get_random_integer(0, 4));

    // Then we schedule the leave event.
    theSimulation.scheduleEvent
    (std::make_unique<leaveEvent>(time + 1 + get_random_integer(0, 10), size));
}

std::string orderEvent::toString() const {
    	return "orderEvent: ";
}


// Leave Event
leaveEvent::leaveEvent(unsigned int t, unsigned int groupSize)
    : event(t), size(groupSize)
{ }

void leaveEvent::processEvent() {
    theSimulation.leave(size);
}

std::string leaveEvent::toString() const {
	return "leaveEvent: ";
}