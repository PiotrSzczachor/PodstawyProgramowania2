//
// Created by Piotr on 04.05.2021.
//

#include "ConsoleLogger.h"
#include "functions.h"
#include <ctime>

using namespace std;

void ConsoleLogger::log(const string &text) {
    cout << getCurrentTimeInTextForm() << " " << text << endl;
}
