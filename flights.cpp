#include "flights.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

string planeID;
int flightID;
string sCode;
string eCode;
time_t start;
time_t end;
int numPass;
void flights::addFlight(members m, planes p)
{ cout << "Enter flight ID: ";
  cin >> flightID;
  cout << "Enter the plane's ID: ";
  cin >> planeID;
  while(p.searchPlaneFromID(planeID) == -1)
  {
    cout << "Plane does not exist, try again: ";
    cin >> planeID;
  }
  cout << "Enter starting airport code: ";
  cin >> sCode;
  cout << "Enter ending airport code: ";
  cin >> eCode;
  int year;
  int month;

  time_t start = time(0);
  tm *inputStart = localtime(&start);
  cout << "Enter start time: " << endl;
  cout << "Year: ";
  cin >> year;
  year -= 1900;
  inputStart->tm_year = year;
  cout << "Month: ";
  cin >> month;
  month -= 1;
  inputStart->tm_mon = month;
  cout << "Day: ";
  cin >> inputStart->tm_mday;
  cout << "Hour: ";
  cin >> inputStart->tm_hour;
  cout << "Min: ";
  cin >> inputStart-> tm_min;
  inputStart->tm_sec = 0;
  start = mktime(inputStart);
  cout << start;



  time_t end = time(0);
  tm *inputEnd = localtime(&end);
  cout << "Enter end time: " << endl;
  cout << "Year: ";
  cin >> year;
  year -= 1900;
  inputEnd->tm_year = year;
  cout << "Month: ";
  cin >> month;
  month -= 1;
  inputEnd->tm_mon = month;
  cout << "Day: ";
  cin >> inputEnd->tm_mday;
  cout << "Hour: ";
  cin >> inputEnd->tm_hour;
  cout << "Min: ";
  cin >> inputEnd->tm_min;
  inputEnd->tm_sec = 0;
  end = mktime(inputEnd);
  cout << end;

  flightList.push_back(flight(flightID,planeID, start, end, sCode, eCode));
  int duration = end - start;
  if(duration > 28800)
  {
    for(int i = 0; i < 2; i ++)
    {
      flightList[flightList.size()-1].addPilot(m);
      flightList[flightList.size()-1].addPilot(m);
      flightList[flightList.size()-1].addCabin(m);
      flightList[flightList.size()-1].addCabin(m);
    }
  }
  else{
    flightList[flightList.size()-1].addPilot(m);
    flightList[flightList.size()-1].addPilot(m);
    flightList[flightList.size()-1].addCabin(m);
    flightList[flightList.size()-1].addCabin(m);
  }
  flightList[flightList.size()-1].addPassengers(p);
}

void flights::deleteFlight()
{ int id;
  cout << "Enter flight ID to delete.";
  cin >> id;
  for(int i = 0; i < flightList.size();i++)
  {
    if(flightList[i].getFlightId() == id)
    {
      flightList.erase(flightList.begin()+i);
    }
  }
}
void flights::editFlight(members m, planes p)
{ int id;
  cout << "Enter flight ID to edit";
  cin >> id;
  for(int i = 0; i < flightList.size();i++)
  {
    if(flightList[i].getFlightId() == id)
    {   cout << "Enter 1 to change plane" << endl;
        cout << "Enter 2 to add another pilot" << endl;
        cout << "enter 3 to add another cabin member" << endl;
        int option;
        string iD;
        cin >> option;
        switch(option){
          case 1:
                cout << "Enter new plane ID";
                cin >> iD;
                flightList[i].setPlaneId(iD);
                break;
          case 2:
                flightList[i].addPilot(m);
                break;
          case 3:
                flightList[i].addCabin(m);
                break;
        };
    }
  }

}
void flights::storeFlights()
{
  ofstream flightFile;
  flightFile.open("flights.dat");
  for(int i = 0; i < flightList.size(); i++)
  {
    flightFile << flightList[i].getFlightId();
    flightFile << ' ';
    flightFile << flightList[i].getPlaneId();
    flightFile << ' ';
    flightFile << flightList[i].getStartCode();
    flightFile << ' ';
    flightFile << flightList[i].getEndCode();
    flightFile << ' ';
    flightFile << flightList[i].getStartTime();
    flightFile << ' ';
    flightFile << flightList[i].getEndTime();
    flightFile << ' ';
    flightFile << flightList[i].getNumPassengers();
    flightFile << '\n';

    }
    flightFile.close();
}
void flights::loadFlights()
{
  ifstream flightFile;
  flightFile.open("flights.dat");
  while(flightFile >> flightID >> planeID >> sCode >> eCode >> start >> end >> numPass)
  {
    flightList.push_back(flight(flightID,planeID, start, end, sCode, eCode));
    flightList[flightList.size()-1].setNumPassengers(numPass);
  }

}

void flights::printFlights()
{
  for(int i = 0; i < flightList.size(); i++)
  { time_t s = flightList[i].getStartTime();
    time_t e = flightList[i].getEndTime();
    struct tm* startGMT;
    startGMT = gmtime(&s);
    char* st = asctime(startGMT);
    cout << "Flight ID: " << flightList[i].getFlightId() << endl;
    cout << "Plane ID: " << flightList[i].getPlaneId() << endl;
    cout << "Going from " << flightList[i].getStartCode() << " to " << flightList[i].getEndCode() << endl;
    cout << "Begins at: " << st << endl;
    struct tm* endGMT;
    endGMT = gmtime(&e);
    char* et = asctime(endGMT);
    cout << "Ends at: " << et << endl;
    cout << "Contains " << flightList[i].getNumPassengers() << " passengers." << endl;
}
}
