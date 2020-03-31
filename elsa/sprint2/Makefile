CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: main.o mainwin.o entrydialog.o *.h
	$(CXX) $(CXXFLAGS) mainwin.o entrydialog.o $(GTKFLAGS) -o main
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o
store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp
customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp
options.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) -c options.cpp
desktop.o: desktop.cpp *.h
	$(CXX) $(CXXFLAGS) -c desktop.cpp
order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c order.cpp
clean:
	rm -f *.o *.gch main test

