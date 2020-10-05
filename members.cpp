#include "members.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
string id;
string type;
string name;
void members::addMember()
{ cin.ignore();
  cout << "Enter member name: ";
  getline(cin,name);
  cout << "Enter classification (pilot/cabin): ";
  cin >> type;
  cout << "Enter member ID: ";
  cin >> id;
  member m(name, id, type);
  memberList.push_back(m);
  cout << "Member " << id << " added." << endl;
}
void members::deleteMember()
{
  cout << "Enter member ID to delete: " << endl;
  cin >> id;
  int i = searchMemberFromId(id);
  memberList.erase(memberList.begin() + i);
  cout << "Member " << id << " deleted." << endl;
}
void members::editMember()
{
  cout << "Enter member ID to edit: " << endl;
  cin >> id;
  int i = searchMemberFromId(id);
  string option;
  cout << "EDITING MEMBER " << id << endl;
  cout << "Enter new classification for crew member (pilot/co-pilot/cabin)" << endl;
  cin >> option;
  memberList[i].setType(option);
  cout << "Changed member " << id << " classification to " << option << endl;

}
void members::printMembers()
{
  cout << "PRINTING ALL MEMBERS" << endl;
  for(int i = 0; i < memberList.size(); i++)
  {
    cout << "Name: " << memberList[i].getName() << endl;
    cout << "ID: " << memberList[i].getId() << endl;
    cout << "Classification: " << memberList[i].getType() << endl << endl;

  }
}
int members::searchMemberFromId(string id)
{
  cout << "MemberList Size: " << memberList.size() << endl;
  for(int i = 0; i < memberList.size(); i++)
  {
    if(memberList[i].getId() == id)
    {
      return i;
    }
  }
      cout << "MEMBER NOT FOUND" << endl;
      return -1;

}
string members::getTypeFromId(string id)
{
  return memberList[searchMemberFromId(id)].getType();
}
void members::storeMembers()
{
  ofstream memberFile;
  memberFile.open("members.dat");
  for(int i = 0; i < memberList.size(); i++)
  {
    memberFile << memberList[i].getName();
    memberFile << ',';
    memberFile << memberList[i].getId();
    memberFile << ',';
    memberFile << memberList[i].getType();
    memberFile << '\n';
  }
  memberFile.close();
}
void members::loadMembers()
{
  ifstream memberFile;
  memberFile.open("members.dat");
  {
    while(getline(memberFile,name,',')) //correctly loads data **change planes to THIS**
    {
      getline(memberFile,id,',');
      getline(memberFile,type);
      member m(name,id,type);
      memberList.push_back(m);
    }
    memberFile.close();
    cout << "Loaded " << memberList.size() << " members" << endl;

  }
}
