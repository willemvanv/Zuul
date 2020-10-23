#include <iostream>
#include <cstring>
#include "room.h"
#include <map>

using namespace std;

//Declaring functions
void move(char* a, int *b);
//Variables
room *rooms[16];
int cr;
int inv;
char inventory0[99];
char inventory1[99];
char inventory2[99];
char inventory3[99];
char inventory4[99];
char inventory5[99];
char inventory6[99];

int main() {

  //Rooms
  rooms[0] = new room(0, "A light emerges from the dark cave", " ", "EAST");
  rooms[1] = new room(1, "You find yourself on a beautiful hillside", " ",
		      "NORTH, WEST, SOUTH, EAST");
  rooms[2] = new room(2, "You come across a seaside with a vast ocean to the south", "Shell",
		      "NORTH");
  rooms[3] = new room(3, "The trail leads you to large woods, how nice", "Branch",
		      "NORTH, WEST, SOUTH");	  
  rooms[4] = new room(4, "A calm shrine emerges from the woods", "Key",
		      "NORTH");
  rooms[5] = new room(5, "Ruins of a small village surround you", " ",
		      "NORTH, SOUTH, EAST");
  rooms[6] = new room(6, "You find yourself at a small cavern, smells funny", "Odd Plant",
		      "SOUTH");
  rooms[7] = new room(7, "The path splits here", " ",
		      "NORTH, WEST, SOUTH, EAST");
  rooms[8] = new room(8, "The road broadends and gets noisier, you see a city to the east", " ",
		      "WEST, EAST");
  rooms[9] = new room(9, "You find yourself surrounded by a city full of lights", " ",
		      "NORTH, WEST, SOUTH");
  rooms[10] = new room(10, "A large casino emerges from around the corner", "Gambling Chips",
		       "NORTH");
  rooms[11] = new room(11, "This part of town feels shadier", "Ball",
		       "SOUTH");
  rooms[12] = new room(12, "Woods emerge around the path, you feel uneasy", " ",
		       "NORTH, SOUTH");
  rooms[13] = new room(13, "You find yourself at the foot of the castle", "Sword",
		       "NORTH, SOUTH");
  rooms[14] = new room(14, "You enter the castle to find a long hall with a door at the end", " ",
		       "SOUTH");
  
  
  //Variables
  bool running = true;
  cout << "Controls: north, south, west, east, drop, take, quit" << endl;
  while (running == true) {
    //Getting input
    char input[99];
    rooms[cr]->printTurn();
    //Win condition
    if (cr == 14 && (strcmp(inventory0, "Key") == 0 || strcmp(inventory1, "Key") == 0 ||
		     strcmp(inventory2, "Key") == 0 || strcmp(inventory3, "Key") == 0 ||
		     strcmp(inventory4, "Key") == 0 || strcmp(inventory5, "Key") == 0 ||
		     strcmp(inventory6, "Key") == 0)) {
      cout << "Use Key?(y/n)" << endl;
      char inp;
      cin >> inp;
      if (inp = 'y') {
	cout << "Congratulations, you beat the game!" << endl;
	running = false;  
      }
    }
    cin.getline(input, 99);
    //Move to another room
    if (input[0] == 's' && input[1] == 'o' && input[2] == 'u' && input[3] == 't' &&
	input[4] == 'h' || input[0] == 'w' && input[1] == 'e' && input[2] == 's' && input[3] == 't'
	|| input[0] == 'e' && input[1] == 'a' && input[2] == 's' && input[3] == 't'
	|| input[0] == 'n' && input[1] == 'o' && input[2] == 'r' && input[3] == 't' &&
	input[4] == 'h') {
      cout << endl;
      move(input, &cr);
    }
    //Take item
    else if (input[0] == 't' && input[1] == 'a' && input[2] == 'k' && input[3] == 'e') {
      char *c;
      c = (char *)malloc(99*sizeof(char));
      rooms[cr]->Take(&c);
      if (inv == 0) {
	strcpy(inventory0, c);
      }
      else if (inv == 1) {
	strcpy(inventory1, c);
      }
      else if (inv == 2) {
        strcpy(inventory2, c);
      }
      else if (inv == 3) {
	strcpy(inventory3, c);
      }
      else if (inv == 4) {
	strcpy(inventory4, c);
      }
      else if (inv == 5) {
	strcpy(inventory5, c);
      }
      else if (inv == 6) {
	strcpy(inventory6, c);
      }
      cout << endl;
    }
    //Drop an item
    else if (input[0] == 'd' && input[1] == 'r' && input[2] == 'o' && input[3] == 'p') {
      cout << "Enter item to be dropped" << endl;
      char in[99];
      cin.getline(in, 20);
      if (strcmp(in, inventory1) == 0) {
	inventory1[0] = ' ';
      }
      if (strcmp(in, inventory2) == 0) {
	inventory2[0] = ' ';
      }
      if (strcmp(in, inventory3) == 0) {
	inventory3[0] = ' ';
      }
      if (strcmp(in, inventory4) == 0) {
	inventory4[0] = ' ';
      }
      if (strcmp(in, inventory5) == 0) {
	inventory5[0] = ' ';
      }
      if (strcmp(in, inventory6) == 0) {
	inventory6[0] = ' ';
      }
      if (strcmp(in, inventory0) == 0) {
	inventory0[0] = ' ';
      }
      rooms[cr]->Drop(in);
      cout << endl;
    }
    //Quit game
    else if (input[0] == 'q' && input[1] == 'u' && input[2] == 'i' && input[3] == 't') {
      running = false;
    }
  }
  
  return 0;
}
//Moving rooms function
void move(char* a, int *b) {
  if (*b == 0) {
    if (a[0] == 'e' && a[1] == 'a' && a[2] == 's' && a[3] == 't') {
      *b = 1;
    }
  }
  else if (*b == 1) {
    if (a[0] == 'n' && a[1] == 'o' && a[2] == 'r' && a[3] == 't' && a[4] == 'h') {
      *b = 5;
    }
    if (a[0] == 's' && a[1] == 'o' && a[2] == 'u' && a[3] == 't' && a[4] == 'h') {
      *b = 2;
    }
    if (a[0] == 'e' && a[1] == 'a' && a[2] == 's' && a[3] == 't') {
      *b = 3;
    }
    if (a[0] == 'w' && a[1] == 'e' && a[2] == 's' && a[3] == 't') {
      *b = 0;
    }
  }
  else if (*b == 2) {
    if (a[0] == 'n' && a[1] == 'o' && a[2] == 'r' && a[3] == 't' && a[4] == 'h') {
      *b = 1;
    }
  }
  else if (*b == 3) {
    if (a[0] == 'n' && a[1] == 'o' && a[2] == 'r' && a[3] == 't' && a[4] == 'h') {
      *b = 7;
    }
    if (a[0] == 's' && a[1] == 'o' && a[2] == 'u' && a[3] == 't' && a[4] == 'h') {
      *b = 4;
    }
    if (a[0] == 'w' && a[1] == 'e' && a[2] == 's' && a[3] == 't') {
      *b = 1;
    }
  }
  else if (*b == 4) {
    if (a[0] == 'n' && a[1] == 'o' && a[2] == 'r' && a[3] == 't' && a[4] == 'h') {
      *b = 3;
    }
  }
  else if (*b == 5) {
    if (a[0] == 'n' && a[1] == 'o' && a[2] == 'r' && a[3] == 't' && a[4] == 'h') {
      *b = 6;
    }
    if (a[0] == 's' && a[1] == 'o' && a[2] == 'u' && a[3] == 't' && a[4] == 'h') {
      *b = 1;
    }
    if (a[0] == 'e' && a[1] == 'a' && a[2] == 's' && a[3] == 't') {
      *b = 7;
    }
  }
  else if (*b == 6) {
    if (a[0] == 's' && a[1] == 'o' && a[2] == 'u' && a[3] == 't' && a[4] == 'h') {
      *b = 5;
    }
  }
  else if (*b == 7) {
    if (a[0] == 'n' && a[1] == 'o' && a[2] == 'r' && a[3] == 't' && a[4] == 'h') {
      *b = 12;
    }
    if (a[0] == 's' && a[1] == 'o' && a[2] == 'u' && a[3] == 't' && a[4] == 'h') {
      *b = 3;
    }
    if (a[0] == 'e' && a[1] == 'a' && a[2] == 's' && a[3] == 't') {
      *b = 8;
    }
    if (a[0] == 'w' && a[1] == 'e' && a[2] == 's' && a[3] == 't') {
      *b = 5;
    }
  }
  else if (*b == 8) {
    if (a[0] == 'e' && a[1] == 'a' && a[2] == 's' && a[3] == 't') {
      *b = 9;
    }
    if (a[0] == 'w' && a[1] == 'e' && a[2] == 's' && a[3] == 't') {
      *b = 7;
    }
  }
  else if (*b == 9) {
    if (a[0] == 'n' && a[1] == 'o' && a[2] == 'r' && a[3] == 't' && a[4] == 'h') {
      *b = 11;
    }
    if (a[0] == 's' && a[1] == 'o' && a[2] == 'u' && a[3] == 't' && a[4] == 'h') {
      *b = 10;
    }
    if (a[0] == 'w' && a[1] == 'e' && a[2] == 's' && a[3] == 't') {
      *b = 8;
    }
  }
  else if (*b == 10) {
    if (a[0] == 'n' && a[1] == 'o' && a[2] == 'r' && a[3] == 't' && a[4] == 'h') {
      *b = 9;
    }
  }
  else if (*b == 11) {
    if (a[0] == 's' && a[1] == 'o' && a[2] == 'u' && a[3] == 't' && a[4] == 'h') {
      *b = 9;
    }
  }
  else if (*b == 12) {
    if (a[0] == 'n' && a[1] == 'o' && a[2] == 'r' && a[3] == 't' && a[4] == 'h') {
      *b = 13;
    }
    if (a[0] == 's' && a[1] == 'o' && a[2] == 'u' && a[3] == 't' && a[4] == 'h') {
      *b = 7;
    }
  }
  else if (*b == 13) {
    if (a[0] == 'n' && a[1] == 'o' && a[2] == 'r' && a[3] == 't' && a[4] == 'h') {
      *b = 14;
    }
    if (a[0] == 's' && a[1] == 'o' && a[2] == 'u' && a[3] == 't' && a[4] == 'h') {
      *b = 12;
    }
  }
  else if (*b == 14) {
    if (a[0] == 's' && a[1] == 'o' && a[2] == 'u' && a[3] == 't' && a[4] == 'h') {
      *b = 13;
    }
  }
}
