# Makefile for Cypher
CXXFLAGS += --std=c++17

all: main 

debug: CXXFLAGS += -g
debug: all

rebuild: clean main 

main: main.o product.o taxed.o taxfree.o *.h
	$(CXX) $(CXXFLAGS) -o store main.o product.o taxed.o taxfree.o
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
product.o: product.cpp *.h
	$(CXX) $(CXXFLAGS) -c product.cpp
taxed.o: taxed.cpp *.h
	$(CXX) $(CXXFLAGS) -c taxed.cpp
taxfree.o: taxfree.cpp *.h
	$(CXX) $(CXXFLAGS) -c taxfree.cpp
clean:
	-rm -f *.o store *.gch 
