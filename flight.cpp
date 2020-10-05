#include "flight.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

flight::flight()
{
  flightId = 0;
  planeId = "N/A";
  numPilot = 0;
  numCabin = 0;
  start = 0;
  end = 0;
  startCode = "N/A";
  endCode = "N/A";
  numPassengers = 0;
  status = "inactive";
}
flight::flight(int fId,string pId, time_t s, time_t e, string startC, string endC)
{
  flightId = fId;
  planeId = pId;
  start = s;
  end = e;
  startCode = startC;
  endCode = endC;
  numPassengers = 0;
  status = "inactive";
  numPilot = 0;
  numCabin = 0;
}
void flight::addPilot(members m)
{ string id;
  cout << "Enter pilot ID to add: ";
  cin >> id;
  if(m.searchMemberFromId(id)!= -1)
  {
    if(m.getTypeFromId(id) == "pilot" ||m.getTypeFromId(id) == "Pilot")
    {
    pilotList.push_back(id);
    }
    else
    {
      cout << "Member is not a pilot" << endl;
    }
  }
  else
  {
    cout << "Member does not exist" << endl;
  }
}
void flight::addCabin(members m)
{   string id;
    cout << "Enter cabin crew ID to add: ";
    cin >> id;
    if(m.searchMemberFromId(id)!= -1)
    {
      if(m.getTypeFromId(id) == "cabin" ||m.getTypeFromId(id) == "Cabin")
      {
      cabinList.push_back(id);
      }
      else
      {
        cout << "Member is not a cabin attendant" << endl;
      }
    }
    else
    {
      cout << "Member does not exist" << endl;
    }
}

void flight::addPassengers(planes p)
{
  int n = 9999;
  while(n+getNumPassengers() >= p.getSeatsFromId(planeId))
  {
  cout << "Enter number of passengers to add: ";
  cin >> n;

  if(getNumPassengers() == p.getSeatsFromId(planeId))
  {
    cout << "Plane is already full" << endl;
  }
  else if(n + getNumPassengers() > p.getSeatsFromId(planeId))
  {
    cout << "Not enough room for that many passengers" << endl;
  }
  else
  {
    setNumPassengers(n+getNumPassengers());
    cout << "Added " << n << " passengers. Plane now contains " << getNumPassengers()  << " passengers."<< endl;
  }
}
}
