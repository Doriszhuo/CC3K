#include "Cell.h"

Cell::Cell():
type{'.'} {}



char Cell::getType()const {
    return type;
}



int Cell::getRow()const {
    return y;
}



int Cell::getCol()const {
    return x;
}



void Cell::setType(char c) {
    this->type = c;
}



void Cell::setCoords(int x, int y) {
    this->x = x;
    this->y = y;
}



void Cell::attach(Observer *o) {
    observers.push_back(o);
}



SubscriptionType Cell::subType() {
    return SubscriptionType::Around;
}


void Cell::notify(Cell&c, char newType) {
    type = newType;
}


void Cell::notifyAllObservers() {
    int size = (int)observers.size();
    for(int i = 0; i < size; ++i) {
        if (observers[i]->subType() == SubscriptionType::All) {
            observers[i]->notify(*this, type);
        }
    }
}


void Cell::notifyAroundObservers() {
    int size = (int)observers.size();
    for(int i = 0; i < size; ++i) {
        if (observers[i]->subType() == SubscriptionType::Around) {
            observers[i]->notify(*this, type);
        }
    }
}







