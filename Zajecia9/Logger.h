//
// Created by Piotr on 04.05.2021.
//
#include <iostream>
#include <vector>


using namespace std;
#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H


class Logger {
protected:
    Logger(){};
    ~Logger(){};

public:
    static Logger* currentLogger;
    static vector<pair<string, Logger*>> loggers;

    static Logger* instance() {
        currentLogger = loggers.front().second;
        return currentLogger;
    }
    virtual void log(const string& text) = 0;

};


#endif //LOGGER_LOGGER_H
