#include <cmath>
#include <iostream>
#include "Hero.h"
#include "Treasure.h"
#include <cstdlib>

class Treasure;

float Damage(int attackerATK, int defencerDEF){
    float damage1 = 100 * attackerATK;
    float damage2 = 100 + defencerDEF;
    float damage = ceil (damage1/damage2);
    return damage;
}

Hero::Hero(int HP, int ATK, int DEF,int x, int y):gold{0}, Character{HP,ATK,DEF,x,y}{}

void Hero::pickGold(){
    gold +=1;
}

float Hero::getGold() {
    return gold;
}

void Hero::setGold(float gold){
    this->gold = gold;
}

void Hero::attackBy(std::string enemyType){
    int chance = rand()%2;
    float damage = 0;
    if (chance){
    if (enemyType == "Vampire"){
        damage = Damage(25,DEF);
    }
    if (enemyType == "Werewolf"){
        damage = Damage(30, DEF);
    }
    if (enemyType == "Troll"){
        damage = Damage(25, DEF);
    }
    if (enemyType == "Goblin"){
        damage = Damage(5, DEF);
    }
    if (enemyType == "Merchant"){
        damage = Damage(70, DEF);
    }
    if (enemyType == "Dragon"){
        damage = Damage(20, DEF);
    }
    if (enemyType == "Phoenix"){
        damage = Damage(35, DEF);
    }
    HP -=damage;
    if (HP <0) HP=0;
    }
}

void Hero::getPotion(std::string potionType){
    if (potionType == "RH"){
        HP += 10;
        if (HP >100) HP = 100;
    }
    
    if (potionType == "BA"){
        ATK += 5;
    }
    if (potionType == "BD"){
        DEF += 5;
    }
    if (potionType == "PH"){
        HP -= 10;
        if (HP <0) HP = 0;
    }
    if (potionType == "WA"){
        ATK -= 5;
        if (ATK < 0) ATK = 0;
    }
    if (potionType == "WD"){
        DEF -= 5;
        if (DEF < 0) DEF = 0;
    }
}

void Hero::getTreasure(Treasure *t){
        if (t->getOpenable()) gold += t->getGold();
}

Hero::~Hero() {}

Dwarf::Dwarf (int x, int y):Hero{100,20,30,x,y}{}

void Dwarf::getTreasure(Treasure *t) {
        if (t->getOpenable()) gold += 2*t->getGold();
}

void Hero::buy(std::string Potion){
    if (Potion == "RH"){
        HP += 10;
        if (HP >100) HP = 100;
    }
    if (Potion == "BA"){
        ATK += 5;
    }
    if (Potion == "BD"){
        DEF += 5;
    }
    gold-=5;
}


Elf::Elf (int x, int y):Hero{140,30,10,x,y}{}

void Elf::getPotion(std::string potionType){
    if (potionType == "RH" || potionType == "PH"){
        HP += 10;
        if (HP >140) HP = 140;
    }
    if (potionType == "BA" || potionType == "WA"){
        ATK += 5;
    }
    if (potionType == "BD" || potionType == "WD"){
        DEF += 5;
    }
}


Orc::Orc (int x, int y):Hero{180,30,25,x,y}{}

void Orc::getTreasure(Treasure *t) {
          if(t->getOpenable()) {
              if (t->getGold() == 1) gold = gold + 0.5;
              else gold += t->getGold()/2;
        }
}

void Orc::getPotion(std::string potionType){
    if (potionType == "RH"){
        HP += 10;
        if (HP >180) HP = 180;
    }
    
    if (potionType == "BA"){
        ATK += 5;
    }
    if (potionType == "BD"){
        DEF += 5;
    }
    if (potionType == "PH"){
        HP -= 10;
        if (HP <0) HP = 0;
    }
    if (potionType == "WA"){
        ATK -= 5;
        if (ATK < 0) ATK = 0;
    }
    if (potionType == "WD"){
        DEF -= 5;
        if (DEF < 0) DEF = 0;
    }
}

Human::Human (int x, int y) :Hero{140,20,20,x,y}{}

void Human::getPotion(std::string potionType) {
    if (potionType == "RH"){
        HP += 10;
        if (HP >140) HP = 140;
    }
    
    if (potionType == "BA"){
        ATK += 5;
    }
    if (potionType == "BD"){
        DEF += 5;
    }
    if (potionType == "PH"){
        HP -= 10;
        if (HP <0) HP = 0;
    }
    if (potionType == "WA"){
        ATK -= 5;
        if (ATK < 0) ATK = 0;
    }
    if (potionType == "WD"){
        DEF -= 5;
        if (DEF < 0) DEF = 0;
    }
}

