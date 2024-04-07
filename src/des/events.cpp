#include "events.h"
#include "storeSimulation.h"
#include "random_utils.h"
#include "helper_functions.h"
#include <random>
#include <sstream>
#include <cstdlib>

// Event
event::event(unsigned int t) : time(t)
{ }

// --- Event subclasses ---

// --- Car Events
void ArriveCarEvent::processEvent()  {
    ;
}

std::string ArriveCarEvent::toString() const {
    std::ostringstream stream;
    stream << "ArriveCarEvent: Time=" << formatTime(time) << " " << car.toString();
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