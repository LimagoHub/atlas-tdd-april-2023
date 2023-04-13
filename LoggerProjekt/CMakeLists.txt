cmake_minimum_required(VERSION 3.24)
project(LoggerProjekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(LoggerProjekt main.cpp Logger.h Appender.h ConsolenAppender.h)
