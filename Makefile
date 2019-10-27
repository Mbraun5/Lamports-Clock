CXX = g++
CXXFLAGS = -std=c++11 -Wall -pedantic -g
SOURCES = main.cpp VerifyClock.cpp CalculateClock.cpp
DEPS = VerifyClock.h CalculateClock.h
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = clock

all: $(EXECUTABLE)
	@echo Make has finished

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $*.cpp

clean:
	$(RM) *.o *~ $(EXECUTABLE)
