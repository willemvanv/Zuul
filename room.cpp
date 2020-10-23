#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

//Constructor
room::room(int Id, const char* Description, const char* a, const char* b) {
  id = Id;
  strcpy(description, Description);
  strcpy(fallenItems[0].name, a);
  strcpy(exits, b);
}
//Basic room description printing
void room::printTurn() {
  cout << description << endl;
  cout << "Exits: " << exits << endl;
  if (fallenItems[0].name[0] != ' ') {
    cout << "Items Nearby: " << fallenItems[0].name << endl;
  }
}
//Picking up item function
void room::Take(char **a) {
  
  if (fallenItems[0].name[0] != ' ') {
    strcpy(*a, fallenItems[0].name);
    fallenItems[0].name[0] = ' ';
  }
  else if (fallenItems[1].name[0] != ' ') {
    strcpy(*a, fallenItems[1].name);
    fallenItems[1].name[0] = ' ';
  }
  else if (fallenItems[2].name[0] != ' ') {
    strcpy(*a, fallenItems[2].name);
    fallenItems[2].name[0] = ' ';
  }
  else if (fallenItems[3].name[0] != ' ') {
    strcpy(*a, fallenItems[3].name);
    fallenItems[3].name[0] = ' ';
  }
  else if (fallenItems[4].name[0] != ' ') {
    strcpy(*a, fallenItems[4].name);
    fallenItems[4].name[0] = ' ';
  }
  else if (fallenItems[5].name[0] != ' ') {
    strcpy(*a, fallenItems[5].name);
    fallenItems[5].name[0] = ' ';
  }
  else if (fallenItems[6].name[0] != ' ') {
    strcpy(*a, fallenItems[6].name);
    fallenItems[6].name[0] = ' ';
  }
}
//Drop an item
void room::Drop(char* a) {
  if (fallenItems[0].name == 0 || fallenItems[0].name[0] == ' ') {
    strcpy(fallenItems[0].name, a);
  }
  else if (fallenItems[1].name == 0 || fallenItems[1].name[1] == ' ') {
    strcpy(fallenItems[1].name, a);
  }
  else if (fallenItems[2].name == 0 || fallenItems[2].name[2] == ' ') {
    strcpy(fallenItems[2].name, a);
  }
  else if (fallenItems[3].name == 0 || fallenItems[3].name[3] == ' ') {
    strcpy(fallenItems[3].name, a);
  }
  else if (fallenItems[4].name == 0 || fallenItems[4].name[4] == ' ') {
    strcpy(fallenItems[4].name, a);
  }
  else if (fallenItems[5].name == 0 || fallenItems[5].name[5] == ' ') {
    strcpy(fallenItems[5].name, a);
  }
  else if (fallenItems[6].name == 0 || fallenItems[6].name[6] == ' ') {
    strcpy(fallenItems[6].name, a);
  }
}
