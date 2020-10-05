#include "member.h"
#include <string>
#include <iostream>

using namespace std;
member::member()
{
  name = "";
  id = "";
  type = "";
  status = "";
}
member::member(string n, string i, string t)
{
  name = n;
  id = i;
  type = t;
}
