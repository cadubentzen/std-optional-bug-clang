CXX=clang++-18
CXXFLAGS=-std=c++23 -O1

default: util.o main.o
	$(CXX) util.o main.o -o main

%.o: %.cpp
	$(CXX) -c $*.cpp $(CXXFLAGS)

clean:
	rm -f util.o main.o main
