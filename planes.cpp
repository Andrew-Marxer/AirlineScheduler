#include "planes.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
string make;
int model;
string tail;
int seats;
int range;
int crew;
void planes::addPlane()
{

  cout << "Enter make of the plane: ";
  cin >> make;
  cout << "Enter model of plane: ";
  cin >> model;
  cout << "Enter tail number: ";
  cin >> tail;
  cout << "Enter number of seats: ";
  cin >> seats;
  cout << "Enter range of plane: ";
  cin >> range;
  cout << "Enter minimum # of crew: ";
  cin >> crew;
  plane p(make,model,tail,seats,range,crew);
  planeList.push_back(p);
}
void planes::deletePlane()
{
        cout << "Enter plane ID to delete" << endl;
        cin >> tail;
        int i = searchPlaneFromID(tail);

        planeList.erase(planeList.begin() + i);
}
void planes::editPlane()
{
    cout << "Enter plane ID to edit" << endl;
    cin >> tail;
   int i = searchPlaneFromID(tail);
     int choice;
      cout << "EDITING PLANE " << tail << endl;
      cout << "Which field would you like to edit?" << endl;
      cout << "Enter: " << endl;
      cout << "1 - Number of seats" << endl << "2 - Range" << endl << "3 - Minimum crew" << endl;
      cin >> choice;
      switch (choice){
        case 1: cout << "Enter new number of seats: ";
                cin >> seats;
                planeList[i].setSeats(seats);
                break;
        case 2: cout << "Enter new range: ";
                cin >> range;
                planeList[i].setRange(range);
                break;
        case 3: cout << "Enter new minimum crew: ";
                cin >> crew;
                planeList[i].setMinCrew(crew);
                break;
        default: cout << "Invalid entry" << endl;


    }
  }

void planes::printPlanes()
{
  cout << "PRINTING ALL PLANES" << endl;
  for(int i = 0; i < planeList.size(); i++)
  {
    cout << "Make: " << planeList[i].getMake() << endl;
    cout << "Model: " << planeList[i].getModel() << endl;
    cout << "Tail Number: " << planeList[i].getTail() << endl;
    cout << "Range: " << planeList[i].getRange() << endl;
    cout << "Number of seats: " << planeList[i].getSeats() << endl;
    cout << "Minimum crew: " << planeList[i].getMinCrew() << endl << endl;

  }
}
int planes::searchPlaneFromID(string id)
{
  for(unsigned int i = 0; i < planeList.size(); i++)
  {
    if(planeList[i].getTail() == id)
    {
      return i;
    }
  }
    cout << "PLANE NOT FOUND" << endl;
    return -1;

}
int planes::getSeatsFromId(string id)
{
  return planeList[searchPlaneFromID(id)].getSeats();
}
void planes::storePlanes() // FIXME
{
  ofstream planeFile;
  planeFile.open("plane.dat");
  for(int i = 0; i < planeList.size(); i++)
  {
    planeFile << planeList[i].getMake();
    planeFile << " ";
    planeFile << planeList[i].getModel();
    planeFile << " ";
    planeFile << planeList[i].getTail();
    planeFile << " ";
    planeFile << planeList[i].getSeats();
    planeFile << " ";
    planeFile << planeList[i].getRange();
    planeFile << " ";
    planeFile << planeList[i].getMinCrew();
    planeFile << " ";
    planeFile << '\n';
  }
  planeFile.close();
}
void planes::loadPlanes()
{ int i =0;
  char nline;
  ifstream planeFile;
  planeFile.open("plane.dat");
  while(planeFile >> make >> model >> tail >> seats >> range >> crew)
  {
    plane p(make,model,tail,seats,range,crew);
    planeList.push_back(p);
    i++;
  }
  cout << i;
  planeFile.close();
}
