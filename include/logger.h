#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

class Logger {
public:
    static void log(const std::string& message);
}

#endif // LOGGER_H
