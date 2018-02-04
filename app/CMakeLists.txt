##
##    Copyright: O-Marius Chincisan & Zirexix Inc 2016-2017
##
##    This program is distributed
##    WITHOUT ANY WARRANTY; without even the implied warranty of
##    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
##
cmake_minimum_required (VERSION 3.7.2)

add_definitions(-DDEBUG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fexceptions -Wall -fpermissive -ggdb")

link_directories(../link)

add_executable (bunget main.cpp crypto.cpp ../lib)
target_link_libraries (bunget bungetLib crypto++)

include_directories(../lib ../lib/include)

set(EXECUTABLE_OUTPUT_PATH ../bin)

