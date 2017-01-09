#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>
#include <vector>
#include <string>
#include "Observer.h"

class Cell;

class Display: public Observer {
    std::vector<std::vector<char>> theDisplay;
    const int x;
    const int y;
    
public:
    Display(std::string filename); // constructor
    ~Display(); // destructor
    

    void notify(Cell &c, char newType) override; // never used
    char getType(int x, int y); // get the type of the display in given coordinate
    void setType(int x, int y, char type); // set the type of the display in given coordinate
    SubscriptionType subType() override; // never used
    
    friend std::ostream &operator<<(std::ostream &out, const Display &d); // print 
};


#endif


