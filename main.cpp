/*
Andrew Marxer
andrewmarxer@my.unt.edu
This program simulates a flight scheduler. It allows the user to add crew members, pilots, planes.
Then combines all fileds into one flight. The user may also edit or delete any data they wish.ß
*/

#include <iostream>
#include <string>
#include <fstream>
#include "flights.h"
using namespace std;


void printMenu();
int main()
{
  cout << "Andrew Marxer" << endl <<  "andrewmarxer@my.unt.edu" <<  endl << "Homework 4" << endl;
  cout << "CSCE1040" << endl;
  flights Flights;
  members Members;
  planes Planes;
  int option;
  Planes.loadPlanes();
  Members.loadMembers();
  Flights.loadFlights();

  while(option != 0)
  {
    printMenu();
    cin >> option;
    switch (option){
      case 0:
            Planes.storePlanes();
            Members.storeMembers();
            Flights.storeFlights();
            cout << "Info has been saved" << endl;
            break;
      case 1:
            Planes.addPlane();
            Planes.storePlanes();
            break;
      case 2:
            Planes.editPlane();
            Planes.storePlanes();
            break;
      case 3:
            Planes.deletePlane();
            Planes.storePlanes();
            break;
      case 4:
            Planes.printPlanes();
            break;
      case 5:
            Members.addMember();
              Members.storeMembers();
            break;
      case 6:
            Members.editMember();
              Members.storeMembers();
            break;
      case 7:
            Members.deleteMember();
              Members.storeMembers();
            break;
      case 8:
            Members.printMembers();
            break;
      case 9:
            Planes.storePlanes();
            break;
      case 10:
            Planes.loadPlanes();
            break;
      case 11:
            Members.storeMembers();
            break;
      case 12:
            Members.loadMembers();
            break;
      case 13:
            Flights.addFlight(Members, Planes);
            Flights.storeFlights();
            break;
      case 14:
            Flights.printFlights();
            break;
      case 15:
            Flights.deleteFlight();
            Flights.storeFlights();
            break;
      case 16:
            Flights.editFlight(Members, Planes);
            Flights.storeFlights();
            break;

    }
  }
  return 0;
}
void printMenu()
{
  cout << "MENU" << endl;
  cout << "Enter 0 to quit"<< endl;
  cout << "Enter 1 to add a plane" << endl;
  cout << "Enter 2 to edit plane info" << endl;
  cout << "Enter 3 to delete a plane" << endl;
  cout << "Enter 4 to print a list of all planes" << endl;
  cout << "Enter 5 to add a crew member" << endl;
  cout << "Enter 6 to edit crew member info" << endl;
  cout << "Enter 7 to delete a crew member" << endl;
  cout << "Enter 8 to print a list of all crew members" << endl;
  cout << "Enter 9 to store plane info" << endl;
  cout << "Enter 10 to load plane info" << endl;
  cout << "Enter 11 to store crew member info" << endl;
  cout << "Enter 12 to load crew member info" << endl;
  cout << "Enter 13 to add a flight" << endl;
  cout << "Enter 14 to print flights" << endl;
  cout << "Enter 15 to delete a flight" << endl;
  cout << "Enter 16 to edit a flight" << endl;
}
