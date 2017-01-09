#ifndef _TREASURE_H_
#define _TREASURE_H_

class Dragon;

class Treasure {
protected:
    int gold; // The value of the treasure
    int x; // The x coordinate of the treasure
    int y; // The y coorfinate of the treasure
    bool openable; // If the treasure can be opened by hero
public:
    Treasure(int gold, int x, int y, bool openable); // constructor
    void setOpenable(); // set the openable of the treasure
    bool getOpenable(); // return if the treasure is openable
    int getGold() const; // return the value of the treasure
    void setX(int x); // set the x coordinate
    int getX() const; // return the x coordinate
    void setY(int y); // set the y coordinate
    int getY() const; // return the y coordiante
};

class Normal : public Treasure { // value 1
public:
    Normal(int x, int y);
};

class SmallHoard : public Treasure { // value 2
public:
    SmallHoard(int x, int y);
};

class MerchantHoard : public Treasure { // value 4
public:
    MerchantHoard( int x, int y);
    
};


class DragonHoard : public Treasure { // value 6, can only be opened once the dragon guarding it has been slain
public:
    DragonHoard(int x, int y);
};



#endif



