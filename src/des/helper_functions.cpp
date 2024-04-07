#include <string>
#include <iomanip> 
#include <sstream>

std::string formatTime(unsigned int milliseconds) {
    unsigned int totalSeconds = milliseconds / 1000; 
    unsigned int seconds = totalSeconds % 60; 
    unsigned int totalMinutes = totalSeconds / 60; 
    unsigned int minutes = totalMinutes % 60; 
    unsigned int hours = totalMinutes / 60;

    std::ostringstream stream;
    stream << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setfill('0') << std::setw(2) << seconds;

    return stream.str();
}