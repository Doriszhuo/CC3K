#include <iostream>
#include <string>
#include "Grid.h"
#include <ctime>
#include <cstdlib>

using namespace std;


int main(int argc, char * argv[]) {
  srand(time(NULL));
  Grid g;
  bool gExist = false;
  string dir;
  bool restartRequest = false;
  bool validC = false;

  if(argc > 1) {
   for(int i = 1; i < argc; ++i) {
	if(atoi(argv[i]) != 0) {
	srand(atoi(argv[i]));
   }
}  
}

  cout << "Welcome to the game of ChamberCrawler3000" << endl;
                      
  while(true) {
    if (gExist) { 
      cout << "Welcome to the game of ChamberCrawler3000" << endl;
    }
    cout << "Please choose the race you wish to use:" << endl;
    cout << "(H)uman, who starts with 140 HP, 20 Atk, 20Def" << endl;
    cout << "(O)rc, who starts with 180 HP, 30 Atk, 25Def, gold is worth half value" << endl;
    cout << "(D)warf, who starts with 100 HP, 20 Atk, 30 Def, gold is doubled in value" << endl;
    cout << "(E)lf, who starts with 140 HP, 30 Atk, 10 Def, negative potions have positive effect" << endl;
    cout << "Please enter the one you like: " << endl;

    char c;
    cin >> c;
    // choose the race of hero
    if (c != 'h' && c != 'e' && c != 'd' && c != 'o' && 
        c != 'H' && c != 'E' && c != 'D' && c != 'O') {
      cout << "Oops, it seems that we don't have the characters you want" << endl;
      cout << "Would you mind to do it again?" << endl;
      continue;
    }

    gExist = true;
    string s;
    // initialize the game
    if (argc == 2) {
      	g.readMap(argv[1],c);
    } else {  
        g.init(c);
    }
    cout << g;
    cout << "Action: Player character has spawned." << endl;
                                                                                                                
    while (cin >> s) {
      validC = false;
      // restart the game
      if (s == "r") break;
      // quite the game
      if (s == "q") {
        validC = true;
        cout << "Good bye and have a good day~!" << endl;
        return 0;
      }
      // move
      if (s == "no" || s == "so" || s == "ea" || s == "we" ||
          s == "ne" || s == "nw" || s == "se" || s == "sw") {
        validC = true;

        g.move(s);
 
       if (g.isDie()) {
	     cout << "Sorry, you died" <<endl;
             cout << "Would you like to restart? (y/n)";
          char choose;
          cin >> choose;
	  // restart the game if died
          if (choose == 'y' || choose == 'Y')  {
	    restartRequest = true;
          } else {
          cout << "Good bye and have a good day~!" << endl;
	  return 0;
          }
        }
	// win the game
        if (g.isWon()){
	  cout << "Congratulations, you won the game!!!" << endl;
	  cout << "Would you like to restart? (y/n)";
	  char choose;
	  cin >> choose;
	  if (choose == 'y' || choose == 'Y')  {
            restartRequest = true;
	  } else {
	    return 0;
	  }
	}
      }

      // use potion
     if (s == "u") {
	validC = true;
        cin >> dir;
        g.use(dir);
	if (g.isDie()){
	  cout << "Sorry, you died" <<endl;
          cout << "Would you like to restart? (y/n)";
	  char choose;
	  cin >> choose;
	  if (choose == 'y' || choose == 'Y')  {
            restartRequest = true;
	  } else {
	    return 0;
	  }
	}
     }
     // attack enemy
     if (s == "a") {
        validC = true;
        cin >> dir;
        g.attack(dir);
        if (g.isDie()){
          cout << "Sorry, you died" <<endl;
          cout << "Would you like to restart? (y/n)";
	  char choose;
	  cin >> choose;
	  if (choose == 'y' || choose == 'Y')  {
            restartRequest = true;
	  } else {
	    return 0;
	  }
       }
     }
     // buy potion in shop
     if (s == "b") {
        validC = true;
        cin >> dir;
        g.buy(dir);
     }
   
     if (restartRequest) {
        validC = false;
        restartRequest = false;
        break; 
     }
     // input is invalid
     if (!validC) {
        cout << "Oops, you are not giving the right command." << endl;
        cout << "Please do it again." << endl;
     }
   }
 }
}



