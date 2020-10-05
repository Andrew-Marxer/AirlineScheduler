#include "member.h"
#include <iostream>
#include <string>
#include <vector>

class members{
private:
  vector <member> memberList;
public:
  void addMember();
  void deleteMember();
  void editMember();
  int searchMemberFromId(string id);
  void printMembers();
  string getTypeFromId(string id);
  void loadMembers();
  void storeMembers();
};
