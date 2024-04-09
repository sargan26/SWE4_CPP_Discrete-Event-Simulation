#include "random_utils.h"
#include <random>
//#include <chrono>

// Statische Instanz des Zufallszahlengenerators
static auto engine = std::mt19937_64(std::random_device{}());

int get_random_integer(int min, int max) {
    return std::uniform_int_distribution<int>{min, max}(engine);
}

int get_random_integer_exponential(double lambda) {
    std::exponential_distribution<double> distribution(lambda);
    double number = distribution(engine);
    return static_cast<int>(std::floor(number));
}

int get_random_integer_normal(double mean, double stddev) {
    std::normal_distribution<double> distribution(mean, stddev);
    double number = distribution(engine);
    return static_cast<int>(std::round(number));
}