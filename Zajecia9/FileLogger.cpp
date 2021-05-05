//
// Created by Piotr on 04.05.2021.
//

#include <fstream>
#include "functions.h"
#include "FileLogger.h"



void FileLogger::log(const string &text) {
    log2File("log" , text);
}
