#include <iostream>
#include <memory>
#include "events.h"
#include "storeSimulation.h"
#include "random_utils.h"
#include "car.h"
#include "trafficSimulation.h"

int main() {
    // --- Example: Ice Cream Store simulation ---
    std::cout << "--- Example: Ice Cream Store simulation ---\n";

    // Load queue with some number of initial events.
    for (unsigned t = 0; t < 20; t += get_random_integer(0, 6)) {

        std::cout << "pumping queue with event " << t << '\n';
        theSimulation.scheduleEvent(std::make_unique<arriveEvent>(t, 1 + get_random_integer(0, 4)));
    }

    // Run the simulation.
    theSimulation.run();

    std::cout << "Total profits " << theSimulation.getProfit()
        << "\n--- End of ice cream store simulation ---\n\n";

    // --- Test: Car class
    std::cout << "--- Test: Car class ---\n";
    Car car1, car2, car3;

    car1.print();
    car2.print();
    car3.print();

    std::cout << "\n";

    // --- Test: Traffic simulation ---
    std::cout << "--- Test: Traffic simulation ---\n";
    TrafficSimulation trafficSimulation;

    trafficSimulation.init();
    trafficSimulation.print();

    std::cout << "--- Test: Traffic simulation run ---\n";
    trafficSimulation.run();


    return 0;
}
