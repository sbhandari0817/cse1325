CXXXFLAGS = --std = c++17

all: coin

coin:test.o coin.o
	$(CXX) $(CXXFLAGS) test.o coin.o -o coin
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o
coin.o:coin.cpp *.h
	$(CXX) $(CXXFLAGS) -c coin.cpp -o coin.o
coin.gch: coin.h
	$(CXX) $(CXXFLAGS) -c coin.h -o coin.gch
clean:
	rm -f *.o *.gch 
logger: 
	$(CXX) $(CXXFLAGS) -DLOGGER -c test.cpp  -o test.o
	$(CXX) $(CXXFLAGS) -DLOGGER -c coin.cpp  -o coin.o
	$(CXX) $(CXXFLAGS) -DLOGGER test.o coin.o -o coin

