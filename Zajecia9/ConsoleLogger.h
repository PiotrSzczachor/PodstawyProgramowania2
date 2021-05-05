//
// Created by Piotr on 04.05.2021.
//

#ifndef LOGGER_CONSOLELOGGER_H
#define LOGGER_CONSOLELOGGER_H


#include "Logger.h"

class ConsoleLogger : public Logger{
    ConsoleLogger() {};
    ~ConsoleLogger() {};

public:
    static Logger* instance() {
        static ConsoleLogger logger;
        return &logger;
    }
    void log(const string &text) override;


};


#endif //LOGGER_CONSOLELOGGER_H
