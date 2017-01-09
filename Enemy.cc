#include "Enemy.h"
#include "Treasure.h"
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

bool Merchant::Hostile = false;

Enemy::Enemy(int HP, int ATK, int DEF,int x, int y, string type): Character{HP,ATK,DEF,x,y}, type{type}{}

void Enemy::attackBy(Hero *h){
    float damage1 = 100 * (h->getATK());
    float damage2 = 100 + (this->getDEF());
    float damage = ceil (damage1 / damage2);
    HP-=damage;
    if (HP <0) HP=0;
}

bool Enemy::getHostile(){
  return true;
}

std::string Enemy::getType(){
    return type;
}

/*void Enemy::setHostile(bool Hostile){
  this->Hostile = Hostile;
}*/

Werewolf::Werewolf(int x, int y): Enemy(120,30,5,x,y,"Werewolf"){}

Vampire::Vampire(int x, int y): Enemy(50,25,25,x,y,"Vampire"){}

Goblin::Goblin (int x, int y):Enemy(70,5,10,x,y,"Goblin"){}

Troll::Troll (int x, int y):Enemy(120,25,15,x,y,"Troll"){}

Merchant::Merchant (int x, int y):Enemy(30,70,5,x,y,"Merchant"){}

bool Merchant::getHostile() {
    return Merchant::Hostile;
}

void Merchant::attackBy(Hero *h){
    Enemy::attackBy(h);
    Merchant::Hostile = true;
}

Dragon::Dragon (int x, int y, Treasure *DH):Enemy(150,20,20,x,y,"Dragon"), DH{DH}{}

void Dragon::attackBy(Hero *h){
    float damage1 = 100 * (h->getATK());
    float damage2 = 100 + (this->getDEF());
    float damage = ceil (damage1 / damage2);
    HP-=damage;
    if (HP <=0) {
        HP =0;
        DH->setOpenable();
    }
}

Phoenix::Phoenix (int x, int y):Enemy(50,35,20,x,y,"Phoenix"){}
