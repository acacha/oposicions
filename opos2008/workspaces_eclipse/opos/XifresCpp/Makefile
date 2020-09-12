# Author: Ricardo Garcia Gonzalez
# License: Public domain code
CXX = c++
CXXFLAGS = -O2
CXXFLAGS += -Wall -std=c++98
LDFLAGS = 

program = cifras
objects = cifras.o operation.o node.o memory_manager.o

$(program): $(objects)
	$(CXX) -o $(program) $(objects) $(LDFLAGS)

cifras.o: cifras.cc operation.h node.h
	$(CXX) $(CXXFLAGS) -c cifras.cc

operation.o: operation.cc operation.h
	$(CXX) $(CXXFLAGS) -c operation.cc

node.o: node.cc node.h operation.h
	$(CXX) $(CXXFLAGS) -c node.cc

memory_manager.o: memory_manager.cc operation.h node.h
	$(CXX) $(CXXFLAGS) -c memory_manager.cc

clean:
	rm -f $(program) $(objects) *~
