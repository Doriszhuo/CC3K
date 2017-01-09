#ifndef _CELL_H_
#define _CELL_H_

#include <iostream>
#include <vector>
#include "Observer.h"
#include "Display.h"

class Cell : public Observer {
  char type; // The type of the cell : wall, floor, path, enemy, hero, potion, treasure, blank
  std::vector<Observer*> observers; // observer pattern
  int x, y; // coordinate of the cell
                  
  public:
  Cell(); // default constructor

  char getType() const; // return the type of the cell
  int getRow() const; // return the y coordiante
  int getCol() const; // return the x coordinate
  void setType(char c); // set the type of the cell 
  void setCoords(int x, int y); // set the coordinate of the cell

  // Observer pattern 
  void attach(Observer *o); 
  SubscriptionType subType() override; 
                                                 
  void notify(Cell &c, char newType) override;

  void notifyAllObservers();
  void notifyAroundObservers();
                                                              
};


#endif


