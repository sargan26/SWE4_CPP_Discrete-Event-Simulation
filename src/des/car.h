#pragma once
#include <string>

class Car {
private:
	static int nextId;
	int id;
	std::string model;

public:
	Car();

	int getId() const { return id; };
	std::string getModel() const { return model; };

	void print() const;
	std::string toString() const;
};
