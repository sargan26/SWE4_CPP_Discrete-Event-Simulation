#include "car.h"
#include "random_utils.h"
#include <iostream>
#include <array>
#include <sstream>

// Static unique ID counter
int Car::nextId = 0;

Car::Car() {
	static std::array<std::string, 5> models = { "Audi", "BMW", "Mercedes", "VW", "Opel" };
	id = ++nextId;
	model = models[get_random_integer(0, models.size() - 1)];
}

void Car::print() const {
	std::cout << "Car ID: " << id << ", Model: " << model << std::endl;
}

std::string Car::toString() const {
	std::ostringstream stream;
	stream << "Car ID: " << id << ", Model: " << model;
	return stream.str();
}
