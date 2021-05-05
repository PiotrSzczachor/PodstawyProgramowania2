//
// Created by Piotr on 05.05.2021.
//

#ifndef LOGGER_FUNCTIONS_H
#define LOGGER_FUNCTIONS_H

#endif //LOGGER_FUNCTIONS_H

#include <fstream>
#include <iostream>
#include "ctime"

using namespace std;

std::string getCurrentTimeInTextForm()
{
    time_t now = time(nullptr);
    char buffer[100] = {};
    strftime(buffer, sizeof(buffer),"%d-%m-%Y %H:%M:%S", gmtime(&now));
    return string(buffer);
}

void log2File(const char* fileName, const std::string& text2Log)
{
    ofstream file(fileName, ios::app);
    if (!file)
    {
        throw std::invalid_argument("Can't open file "s + fileName + " for writing!");
    }
    file << getCurrentTimeInTextForm() << ": " << text2Log << endl;
}


