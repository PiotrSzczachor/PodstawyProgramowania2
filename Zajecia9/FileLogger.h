//
// Created by Piotr on 04.05.2021.
//

#ifndef LOGGER_FILELOGGER_H
#define LOGGER_FILELOGGER_H


#include "Logger.h"

class FileLogger : public Logger{
    FileLogger() {};
    ~FileLogger() {};

public:
    static Logger* instance()
    {
        static FileLogger logger;
        return &logger;
    }
    void log(const string &text) override;
};


#endif //LOGGER_FILELOGGER_H
