cmake_minimum_required(VERSION 3.12)
project(eulerCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(eulerCpp main.cpp romanNumeral.h pokerHand.h)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})