#pragma once

class TrafficLight {
private:
	bool isGreen;

public:
	TrafficLight() : isGreen(false) {}
	void change();
	bool getStatus() const { return isGreen;}
};
