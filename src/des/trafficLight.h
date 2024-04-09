#pragma once

class TrafficLight {
private:
	bool green;

public:
	TrafficLight() : green(false) {}
	void change();
	bool isGreen() const { return green;}
};
