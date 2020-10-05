#include <vector>
#include <iostream>
#include <string>
#include "plane.h"

using namespace std;
class planes{
private:
  vector<plane> planeList;
public:
  void addPlane();
  void deletePlane();
  void editPlane();
  int searchPlaneFromID(string id);
  int getSeatsFromId(string id);
  void printPlanes();
  void findAndPrintPlane();
  int getSizeOfList(){return planeList.size();}
  void storePlanes();
  void loadPlanes();
};
