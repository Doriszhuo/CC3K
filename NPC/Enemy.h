#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <iostream>
#include <string>
#include "Hero.h"
#include "Character.h"

class Hero;

class Enemy: public Character {
  protected:
    std::string type; // The type of enemy : Vampire, Werewolf, Goblin, Troll, Phoenix, Merchant, Dragon
  public:
    Enemy(int HP, int ATK, int DEF,int x, int y,std::string type); // Constructor
    virtual void attackBy(Hero *h); // Get damage by hero h
    virtual bool getHostile(); // See if the enemy is hostile or not
    std::string getType(); // Return the type of the enemy
   //  virtual ~Enemy(); 
};

class Werewolf:public Enemy { // 120 HP, 30 Atk, 5 Def
  public:
    Werewolf(int x, int y);
};

class Vampire: public Enemy { // 50 HP, 25 Atk, 25 Def
  public:
    Vampire (int x, int y);
};

class Goblin: public Enemy { // 70 HP, 5 Atk, 10 Def
  public:
    Goblin (int x, int y);
};

class Troll: public Enemy { // 120 HP,25 Atk, 15 Def
  public:
    Troll (int x, int y);
};

class Phoenix: public Enemy { // 50 HP, 35 Atk, 20 Def
  public:
    Phoenix (int x, int y);
};

class Merchant: public Enemy { // 30 HP, 70 Atk, 5 Def
    static bool Hostile;  // Hostile is for all the Merchant in the floor
  public:
    Merchant (int x, int y);
    bool getHostile() override; // Return the Hostile of the Merchant
    void attackBy(Hero *h) override; // Set the hostile for all Merchant is attacked by PC
};

class Dragon: public Enemy { // 150 HP, 20 Atk, 20 Def, always guards a treasure horde
    Treasure *DH;
  public:
    void attackBy(Hero *h) override; // If dragon died, the DragonHoard will bacome openable
    Dragon (int x, int y, Treasure *DH); 
};


#endif
