CXXFLAGS += --std=c++17

all: cart

cart: main.o cart.o item.o *.h
	$(CXX) $(CXXFLAGS) main.o cart.o item.o -o cart

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

cart.o: cart.cpp *.h
	$(CXX) $(CXXFLAGS) cart.cpp -c -o cart.o

item.o: item.cpp *.h
	$(CXX) $(CXXFLAGS) item.cpp -c -o item.o

clean:
	rm -f *.o *.gch cart

