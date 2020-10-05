#include "plane.h"

using namespace std;
plane::plane()
{
  make = "";
  model = 0;
  tailNum = "";
  numSeats = 0;
  range = 0;
  minCrew = 0;
}
plane::plane(string mke, int modl, string tail, int seats, int r, int crew)
{
  make = mke;
  model = modl;
  tailNum = tail;
  numSeats = seats;
  range = r;
  minCrew = crew;
}
void plane::setMinCrew(int min){
  minCrew = min;
}
