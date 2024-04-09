#pragma once
#include <memory>
#include <string>
#include "random_utils.h"
#include "Car.h"

class Lane;  // forward declaration

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

// --- Intersection Events
class ArriveCarEvent : public event {
private:
    Car car;
    Lane& lane; // reference to the lane is belongs

public:
    ArriveCarEvent(unsigned int t, const Car& c, Lane& lane) : event(t), car(c), lane(lane) {}
    void processEvent() override;
    std::string toString() const;
};

class LeaveCarEvent : public event {
private:
    Lane& lane; // reference to the lane is belongs
    unsigned int leaveDuration;

public:
    LeaveCarEvent(unsigned int t, Lane& lane, unsigned int leaveDuration) : event(t), lane(lane), leaveDuration(leaveDuration) {}
	void processEvent() override;
    std::string toString() const;
};

class TrafficLightSwitchEvent : public event {
private:
    Lane & lane; // reference to the lane is belongs

public:
    TrafficLightSwitchEvent(unsigned int t, Lane & lane) : event(t), lane(lane) {}
    void processEvent() override;
    std::string toString() const;
};

class PrintStatisticsEvent : public event {
private:
    Lane& lane; // reference to the lane is belongs

public:
    PrintStatisticsEvent(unsigned int t, Lane& lane) : event(t), lane(lane) {}
    void processEvent() override;
    std::string toString() const;
};

class ExportStatisticsEvent : public event {
private:
    Lane& lane; // reference to the lane is belongs

public:
    ExportStatisticsEvent(unsigned int t, Lane& lane) : event(t), lane(lane) {}
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