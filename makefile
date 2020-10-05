make:
	g++ main.cpp flights.cpp planes.cpp members.cpp flight.cpp plane.cpp member.cpp -o airlineScheduler.exe

main.o: main.cpp
	g++ -c main.cpp

planes.o: planes.cpp
	g++ -c planes.cpp

members.o: members.cpp
	g++ -c members.cpp

flights.o: flights.cpp
	g++ -c flights.cpp
