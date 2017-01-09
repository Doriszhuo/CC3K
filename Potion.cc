#include "Potion.h"
using namespace std;

//**************************************************
//static boolean
bool RH::identifyRH = false;

bool PH::identifyPH = false;

bool BA::identifyBA = false;

bool WA::identifyWA = false;

bool BD::identifyBD = false;

bool WD::identifyWD = false;

//**************************************************
//Super class Potion
Potion::Potion(int x, int y): x{x}, y{y} {}

void Potion::setCood(int x, int y) {
    this->x = x;
    this->y = y;
}

int Potion::getX() const {
    return this->x;
}

int Potion::getY() const {
    return this->y;
}

string Potion::getType() const {
    return this->type;
}

//**************************************************
//Sub class RH
RH::RH(int x, int y): Potion{x, y} {
    type = "RH";
}

void RH::usedBy() {
    RH::identifyRH = true;
}

bool RH::getIden() {
    return RH::identifyRH;
}

//**************************************************
//Sub class PH
PH::PH(int x, int y): Potion{x, y} {
    type = "PH";
}

void PH::usedBy() {
    PH::identifyPH = true;
}

bool PH::getIden() {
    return PH::identifyPH;
}

//**************************************************
//Sub class BA
BA::BA(int x, int y): Potion{x, y} {
    type = "BA";
}

void BA::usedBy() {
    BA::identifyBA = true;
}

bool BA::getIden() {
    return BA::identifyBA;
}

//**************************************************
//Sub class WA
WA::WA(int x, int y): Potion{x, y} {
    type = "WA";
}

void WA::usedBy() {
    WA::identifyWA = true;
}

bool WA::getIden() {
    return WA::identifyWA;
}

//**************************************************
//Sub class BD
BD::BD(int x, int y): Potion{x, y} {
    type = "BD";
}

void BD::usedBy() {
    BD::identifyBD = true;
}

bool BD::getIden() {
    return BD::identifyBD;
}

//**************************************************
//Sub class WD
WD::WD(int x, int y): Potion{x, y} {
    type = "WD";
}

void WD::usedBy() {
    WD::identifyWD = true;
}

bool WD::getIden() {
    return WD::identifyWD;
}

