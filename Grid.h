#ifndef _GRID_H_
#define _GRID_H_

#include <iostream>
#include <vector>
#include "Cell.h"
#include "Display.h"
#include "Enemy.h"
#include "Hero.h"
#include "Treasure.h"
#include "Potion.h"

class Grid {
    std::vector<std::vector<Cell>> theGrid; // The actual grid
    std::vector<Enemy *> theEnemy; // The vector to store all the enemy
    
    std::vector<Potion *> thePotion; // The vector to store all the potion
    
    std::vector<Treasure *> theTreasure; // The vector to store all the treasure
    
    std::vector<Cell *> Chamber; // The vector to store 5 chambers
    Display *d;  // the text display
    
    Display *originalMap;// the plain map has no objects on it

    Hero *h; // player in the game
    
    std::string heroType; // the type of hero : Human, Orc, Dwarf, Elf
    
    
    bool won; // Grid in winning state
    bool lose; // Grid in failure state
   
    int heroChamber; // The chambers that the hero initialized in

    int x; // length of x axis
    
    int y; // length of y axis
    
    int floor; // the current floor of the game

    std::vector<Cell>Chamber1; // all the cells in chamber1 (left top chamber)
    std::vector<Cell>Chamber2; // all the cells in chamber2 (left bottom chamber)
    std::vector<Cell>Chamber3; // all the cells in chamber3 (centrual chamber)
    std::vector<Cell>Chamber4; // all the cells in chamber4 (right top chamber)
    std::vector<Cell>Chamber5; // all the cells in chamber5 (right bottom chamber)


////////////////////////////////////////    
    void initStair(); // initialize the stair
    void initHero(char hero); // initialize the hero
    void initEnemy(); // initialize all the enemy
    void initPotion(); // initialize all the potion
    
    void initTreasure(); // initialize all the trasure
    std::string checkPotion(); // check if there are potions around hero, if yes, show the information
    std::string checkPotionOneDir(std::string direction, bool have); 

    std::string checkAttack(); // check if there are enemy around hero, if yes, attack hero
    std::string checkEnemyOneDir(std::string direction, bool needSpace); 

///////////////////////////////////////
public:
    
    Grid(); // default constructor has nothing on it
    
    ~Grid(); // destructor
    
    void clear(); // clear the floor
    
    void readMap(std::string filename, char hero); // read layout of the floor and initialize it

    void initDisplay(); // initialize the display
    
    int getFloor() const; // return the current floor
    
    bool isWon() const; // return true if the player is won

    bool isLose() const; // return true if the player is lose
    
    bool isDie() const; // return true if the hero is died
    
    bool atStair() const; // return true if the hero is at the stair
    
    void init(char hero); // initialize the game with the hero type that the player choose
    
    void print(); // print the information 

    void randomMove(); // enemy move randomly if hero moved    
   
    void move(std::string direction); // move towards direction
    
    void use(std::string direction); // use the poton at given direction
   
    void attack(std::string direction); // attack enemy at given direction

    void buy(std::string direction); // buy potions at given direction
        
    friend std::ostream &operator<<(std::ostream &out, const Grid &g); // print map
    
    
};


#endif



