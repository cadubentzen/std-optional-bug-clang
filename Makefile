CXX=clang++-18
CXXFLAGS=-std=c++23 -O1

OBJS=util.o main.o

default: $(OBJS)
	$(CXX) $(OBJS) -o main

%.o: %.cpp
	$(CXX) -c $*.cpp $(CXXFLAGS)

clean:
	rm -f $(OBJS) main

test: clean default
	./main
