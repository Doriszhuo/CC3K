#include "Treasure.h"
#include "Enemy.h"

class Dragon;

Treasure::Treasure(int gold, int x, int y, bool openable): gold{gold}, x{x}, y{y}, openable(openable){}

int Treasure::getGold() const{
      return gold;
}

void Treasure::setX(int x){
      this->x=x;
}

void Treasure::setOpenable(){
    this->openable=true;
}

bool Treasure::getOpenable(){
    return openable;
}


int Treasure::getX() const{
      return x;
}

void Treasure::setY(int y){
      this->y=y;
}

int Treasure::getY() const{
      return y;
}

Normal::Normal(int x, int y):Treasure{1, x, y, true}{}

SmallHoard::SmallHoard(int x, int y):Treasure{2, x, y,true}{}

MerchantHoard::MerchantHoard( int x, int y):Treasure{4, x, y, true}{}

DragonHoard::DragonHoard(int x, int y):Treasure{6, x, y, false}{}


