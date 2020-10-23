#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>

using namespace std;

class room {
  //public functions
 public:
  room(int Id, const char* Description, const char* a, const char* e);
  void printTurn();
  void Take(char **a);
  void Drop(char* a);
 private:
  //Item struct
  struct item {
    char name[99];
  };
  //Variables
  char exits[99];
  int id;
  item fallenItems[8];
  char name[99];
  char description[99];
};

#endif
