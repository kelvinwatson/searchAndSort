CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJECT = functions.o lab6.o

SOURCE = functions.cpp lab6.cpp

HEADER = functions.h

EXECUTABLE = lab6

all: ${EXECUTABLE}

${EXECUTABLE}: ${OBJECT} ${HEADER}
	${CXX} ${OBJECT} ${LDFLAGS} -o ${EXECUTABLE}

${OBJECT}: ${SOURCE}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -rf *.o ${EXECUTABLE}