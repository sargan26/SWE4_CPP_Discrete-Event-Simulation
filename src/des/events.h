#pragma once
#include <memory>
#include <string>
#include "random_utils.h"
#include "Car.h"

class event {
public:
    event(unsigned int t);
    virtual ~event() = default;
    virtual void processEvent() = 0;
    virtual std::string toString() const = 0;

    const unsigned int time; // in milliseconds
};

struct eventComparator
{
    bool operator() (const std::unique_ptr<event>& left, const std::unique_ptr<event>& right) const {
        return left->time > right->time;
    }
};

// --- Event subclasses ---

// --- Car Events
class ArriveCarEvent : public event {
private:
    Car car;

public:
    ArriveCarEvent(unsigned int t, const Car& c) : event(t), car(c) {}
    void processEvent() override;
    std::string toString() const;
};

class LeaveCarEvent : public event {
public:
    LeaveCarEvent(unsigned int t) : event(t) {}
	void processEvent() override;
    std::string toString() const;
};


// --- IceStore Events
class arriveEvent : public event {
public:
    arriveEvent(unsigned int t, unsigned int groupSize);
    virtual void processEvent();
    std::string toString() const;

private:
    unsigned int size;
};

class orderEvent : public event {
public:
    orderEvent(unsigned int t, unsigned int groupSize);
    virtual void processEvent();
    std::string toString() const;
private:
    unsigned int size;
};

class leaveEvent : public event {
public:
    leaveEvent(unsigned int t, unsigned int groupSize);
    virtual void processEvent();
    std::string toString() const;
private:
    unsigned int size;
};