#ifndef _POTION_H_
#define _POTION_H_

#include<string>

class Potion {
protected:
    int x; 
    int y;
    std::string type; // Type of the potion :RH, BA, BD, PH, WA, WD
public:
    Potion(int x, int y); // Constructor
    void setCood(int x, int y); // Set the coordinate of the potion
    int getX() const; // return the X coordinate
    int getY() const; // return the Y coordinate
    std::string getType() const; // return the type of the potion
    virtual void usedBy() = 0; // The effect of the potion
    virtual bool getIden() = 0; // return if the potion is known or not
};

class RH : public Potion { // Restore health (RH) : restore up to 10 HP (cannot exceed maximum prescribed by race)
    static bool identifyRH;  
public:
    RH(int x, int y);
    void usedBy(); 
    bool getIden();
};

class PH : public Potion { // Poison health (PH) : lose up to 10 HP (cannot fall below 0 HP)
    static bool identifyPH;
public:
    PH(int x, int y);
    void usedBy();
    bool getIden();
};

class BA : public Potion { //Boost Atk (BA) : increase ATK by 5
    static bool identifyBA;
public:
    BA(int x, int y);
    void usedBy();
    bool getIden();
};

class WA : public Potion { //Wound Atk (WA) : decrease Atk by 5
    static bool identifyWA;
public:
    WA(int x, int y);
    void usedBy();
    bool getIden();
};

class BD : public Potion { //Boost Def (BD) : increase Def by 5
    static bool identifyBD;
public:
    BD(int x, int y);
    void usedBy();
    bool getIden();
};

class WD : public Potion {  //Wound Def (WD) : decrease Def by 5
    static bool identifyWD;
public:
    WD(int x, int y);
    void usedBy();
    bool getIden();
};


#endif


