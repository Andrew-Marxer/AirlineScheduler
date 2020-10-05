#include <string>

using namespace std;
class plane
{
private:
  string make;
  int model;
  string tailNum;
  int numSeats;
  int range;
  int minCrew;
public:
  plane();
  plane(string make, int model, string tail, int seats, int range, int crew);
  void setMake(string m){make = m;}
  string getMake(){return make;}
  void setModel(int m){model = m;}
  int getModel(){return model;}
  void setTail(int t){tailNum = t;}
  string getTail(){return tailNum;}
  void setSeats(int s){numSeats = s;}
  int getSeats(){return numSeats;}
  void setRange(int r){range = r;}
  int getRange(){return range;}
  void setMinCrew(int min);
  int getMinCrew(){return minCrew;}
  friend class flight;
};
