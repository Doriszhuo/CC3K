#ifndef _HERO_H_
#define _HERO_H_

#include <iostream>
#include <string>
#include "Character.h"


class Treasure;

class Hero: public Character{
protected:
    float gold; // Gold that the hero hold can purchase potion in shop(Merchant)
public:
    Hero(int HP, int ATK, int DEF,int x, int y); // Constructor
    void pickGold(); // Pick 1 gold when kill an enemy
    float getGold(); // Return the gold that the hero currently hold
    void setGold(float gold); // Set the gold that the hero hold
    virtual void getPotion(std::string potionType); // Use potion, the limited HP is 100
    void buy(std::string Potion); // Buy potion in shop (Merchant)
    void attackBy(std::string enemyType); // Get damage by given enemy type
    virtual void getTreasure(Treasure *t); // Open the treasure t
    virtual ~Hero(); // Destructor
};

class Dwarf : public Hero { //100 HP, 20 Atk, 30 Def, gold is doubled in value)
public:
    Dwarf(int x, int y);
    void getTreasure(Treasure *t) override; // Get double gold from treasure t

};

class Elf : public Hero{ //140 HP, 30 Atk, 10 Def,negative potions have positive effect
public:
    Elf (int x, int y);
    void getPotion(std::string potionType) override; // negative potions have positive effect

};

class Orc: public Hero{ //180 HP, 30 Atk, 25 Def, gold is worth half value
public:
    Orc (int x, int y);
    void getTreasure(Treasure *t) override; // Get half of the gold from treasure t
    void getPotion(std::string potionType) override; // The limited HP is 180

};

class Human: public Hero{ //140 HP, 20 Atk, 20 Def
public:
    Human (int x, int y);
    void getPotion(std::string potionType) override; // The limited HP is 140

};


#endif



