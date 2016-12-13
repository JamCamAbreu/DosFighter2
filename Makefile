# Author: James Cameron Abreu
# Date: 10/27/2016


CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
LDFLAGS = -lboost_date_time

objects := $(wildcard *.o)
sources := $(wildcard *.cpp)
headers := $(wildcard *.hpp)

dosFighter2 : ${sources}
	g++ ${sources} -o dosFighter2

${objects} : ${sources}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean :
	rm *.o

