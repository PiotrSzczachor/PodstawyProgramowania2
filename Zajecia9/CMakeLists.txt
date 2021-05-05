cmake_minimum_required(VERSION 3.17)
project(Logger)

set(CMAKE_CXX_STANDARD 14)

add_executable(Logger main.cpp Logger.h ConsoleLogger.cpp ConsoleLogger.h FileLogger.cpp FileLogger.h functions.h Logger.cpp)