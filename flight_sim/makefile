flightSim: main.o Aisle.o Person.o Seat.o Space.o LinkedMap.o ItemBag.o Menu.o askForInt.o
	g++ -g -std=c++11 main.o Aisle.o Person.o Seat.o Space.o LinkedMap.o ItemBag.o Menu.o askForInt.o -o flightSim

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Aisle.o: Aisle.cpp Aisle.hpp
	g++ -std=c++11 -c Aisle.cpp

Person.o: Person.cpp Person.hpp
	g++ -std=c++11 -c Person.cpp

Seat.o: Seat.cpp Seat.hpp
	g++ -std=c++11 -c Seat.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++11 -c Space.cpp

LinkedMap.o: LinkedMap.cpp LinkedMap.hpp
	g++ -std=c++11 -c LinkedMap.cpp

ItemBag.o: ItemBag.cpp ItemBag.hpp
	g++ -std=c++11 -c ItemBag.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++11 -c Menu.cpp

askForInt.o: askForInt.cpp askForInt.hpp
	g++ -std=c++11 -c askForInt.cpp

clean:
	rm *.o flightSim