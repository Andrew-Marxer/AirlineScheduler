#include <iostream>
#include <string>

using namespace std;
class member{
private:
  string name;
  string id;
  string type;
  string status;
public:
  member();
  member(string n, string i, string t);
  void setName(string n){name = n;}
  string getName(){return name;}
  void setId(string i){id = i;}
  string getId(){return id;}
  void setType(string t){type = t;}
  string getType(){return type;}
  void setStatus(string s){status = s;}
  string getStatus(){return status;}
};
