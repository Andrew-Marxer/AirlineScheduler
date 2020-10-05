#include "planes.h"
#include "members.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;
class flight{
private:
  int flightId;
  string planeId;
  int numPilot;
  int numCabin;
  vector <string> pilotList;
  vector <string> cabinList;
  time_t start;
  time_t end;
  string startCode;
  string endCode;
  int numPassengers;
  string status;
  int duration;
public:
  flight();
  flight(int fId,string pId, time_t s, time_t e, string startC, string endC);
  void setFlightId(int id){flightId = id;}
  int getFlightId(){return flightId;}
  void addPilot(members m);
  void addCabin(members m);
  void setStartTime(time_t s){start = s;}
  time_t getStartTime(){return start;}
  void setEndTime(time_t e){end = e;}
  time_t getEndTime(){return end;}
  void setDuration(){duration = end - start; cout << "set duration";}
  int getDuration(){cout << "returning duration"; return duration;}
  void setStartCode(string start){startCode = start;}
  string getStartCode(){return startCode;}
  void setEndCode(string end){endCode = end;}
  string getEndCode(){return endCode;}
  void addPassengers(planes p);
  int getNumPassengers(){return numPassengers;}
  int setNumPassengers(int n){numPassengers = n;}
  void setStatus(string stat){status = stat;}
  string getStatus(){return status;}
  void setPlaneId(string id){planeId = id;}
  string getPlaneId(){return planeId;}
};
