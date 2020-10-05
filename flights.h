#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "flight.h"

using namespace std;
class flights{
private:
  vector <flight> flightList;
public:
  void addFlight(members m, planes p);
  void editFlight(members m, planes p);
  void deleteFlight();
  int searchFlightFromId(string id);
  void printFlights();
  void findAndPrintFlight(string id);
  void addPilotToFlight(int index, members m);
  void addCabinToFlight(int index, members m);
  void addPassengersToFlight(int index, planes p);
  void assignPlane(int index, planes p,string pId);
  void storeFlights();
  void loadFlights();
};
