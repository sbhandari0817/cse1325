
CXXFLAGS += --std=c++17

all: main 

debug: CXXFLAGS += -g
debug: all
main: main.o customer.o options.o order.o store.o desktop.o *.h
	$(CXX) $(CXXFLAGS) -o main  main.o customer.o options.o order.o store.o desktop.o
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp
opitons.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) -c options.cpp
order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c order.cpp
store.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp
desktop.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c desktop.cpp
clean:
	-rm -f *.o main *.gch 
