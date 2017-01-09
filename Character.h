#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Character {
protected:
    int x; // x coordinate
    int y; // y coordinate
    int HP; // Health point 
    int ATK; // Attack 
    int DEF; // Defence 
    bool isDie; // if the character is die or not (HP <= 0)
public:
    Character(int HP, int ATK, int DEF,int x, int y); // constructor
    int getX(); // return the x coordinate of the character
    int getY(); // return the y coordinate of the character
    void move(int x, int y); // change the coordinates of the character
    int getHP(); // return the HP of the character
    int getATK(); // return the ATK of the character
    int getDEF(); // return the DEF of the character
    bool getDie(); // return if the character is die or not
    void goDie(); // let the character die
    void setHP(int currHP); // set the HP of the character
    virtual ~Character(); // destructor
};

#endif



