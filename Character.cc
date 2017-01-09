#include "Character.h"


Character::Character(int HP, int ATK, int DEF,int x, int y): HP{HP},ATK{ATK}, DEF{DEF}, x{x}, y{y}{
    isDie = false;
}

int Character::getX(){
    return x;
}
int Character::getY(){
    return y;
}
void Character::move(int x, int y){
    this->x=x;
    this->y=y;
}
int Character::getHP(){
    return HP;
}

int Character::getATK(){
    return ATK;
}
int Character::getDEF(){
    return DEF;
}

bool Character::getDie(){
    return isDie;
}
void Character::setHP(int currHP) {
    this->HP = currHP;
}
void Character::goDie() {
    if (HP <= 0) {
        isDie = true;
    }
}

Character::~Character() {}

