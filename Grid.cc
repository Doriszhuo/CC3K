#include <iostream>
#include <cstdlib>
#include <string>
#include "Grid.h"
using namespace std;

Grid::Grid():
  theGrid{0}, theEnemy{0}, thePotion{0}, d{0}, originalMap{0}, h{0},Chamber1{0},Chamber2{0},Chamber3{0},Chamber4{0},Chamber5{0}, won{false}, lose{false}, x{79}, y{25}, floor{1},heroChamber{0} {}

Grid::~Grid() {
    clear();
}


void Grid::clear() {
  theGrid.clear();
  theEnemy.clear();
  thePotion.clear();
  theTreasure.clear();
  Chamber1.clear();
  Chamber2.clear();
  Chamber3.clear();
  Chamber4.clear();
  Chamber5.clear();

  delete originalMap;
  delete d;
  delete h;
}


void Grid::initDisplay() {
  d = new Display{"map.txt"};
  originalMap = new Display{"map.txt"};        
}


void Grid::readMap(string filename, char hero) {
  
  clear();
  d = new Display{filename};
  originalMap = new Display{"map.txt"};

  for (int i=4; i <= 29; ++i) {
        for (int k=4; k<=7; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber1.push_back(aCell);
        }
    }
    
    for (int i=5; i <= 25; ++i){
        for (int k=16; k<=22; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber2.push_back(aCell);
        }
    }

    for (int i=39; i <= 50; ++i) {
        for (int k=11; k<= 13; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber3.push_back(aCell);
        }
    }
    
    for (int i=40; i <= 62; ++i) {
        for (int k=4; k<= 7; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber4.push_back(aCell);
        }
    }
    
    for (int i=62; i <= 76; ++i) {
        for (int k=8; k<= 13; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber4.push_back(aCell);
        }
    }
    
    for (int i=63; i <= 70; ++i) {
        Cell aCell;
        aCell.setCoords(i, 6);
        Chamber4.push_back(aCell);
    }
    
    for (int i=63; i <= 73; ++i) {
        Cell aCell;
        aCell.setCoords(i, 7);
        Chamber4.push_back(aCell);
    }
    
    for (int i=38; i <= 76; ++i) {
        for (int k=20; k<= 22; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber5.push_back(aCell);
        }
    }
    
    for (int i=66; i <= 76; ++i) {
        for (int k=17; k<= 19; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber5.push_back(aCell);
        }
    }
     
    x = 79;
    y = 25;

    // create cells
    for(int row = 0; row < y; ++row) {
        // create the inside vector
        std::vector<Cell> rowCell;
        for(int col = 0; col < x; ++col) {
            Cell aCell;
            aCell.setCoords(col, row);
            char t = d->getType(col+1, row+1);
            aCell.setType(t);
            rowCell.push_back(aCell);
        }
        theGrid.push_back(rowCell);
    }
    
    // attach cells;
    for (int row = 0; row < y; ++row) {
        for(int col = 0; col < x; ++col) {
            // the left cell
            if (col - 1 >= 0) {
                theGrid[row][col].attach(&theGrid[row][col-1]);
            }
            // the right cell
            if (col + 1 < x) {
                theGrid[row][col].attach(&theGrid[row][col+1]);
            }
            // the up cell
            if (row - 1 >= 0) {
                theGrid[row][col].attach(&theGrid[row-1][col]);
            }
            // the down cell
            if (row + 1 < y) {
                theGrid[row][col].attach(&theGrid[row+1][col]);
            }
            // the up left cell
            if (row - 1 >= 0 && col - 1 >= 0) {
                theGrid[row][col].attach(&theGrid[row-1][col-1]);
            }
            // the up right cell
            if (row - 1 >= 0 && col + 1 < x) {
                theGrid[row][col].attach(&theGrid[row-1][col+1]);
            }
            // the down left cell
            if (row + 1 < y && col - 1 >= 0) {
                theGrid[row][col].attach(&theGrid[row+1][col-1]);
            }
            // the down right cell
            if (row + 1 < y && col +1 < x) {
                theGrid[row][col].attach(&theGrid[row+1][col+1]);
            }
            
            //attach the all display
            theGrid[row][col].attach(d);
        }
    }

    char curr;
    int heroX,heroY;
    int row = 0;
    int col = 0;
        

    for(;row < 25; ++row) {
     for(; col < 79; ++col) {
      	curr = d->getType(col+1, row+1);	

    	if (curr == '0') {
	  Potion * p = new RH(col+1, row+1);
	  thePotion.emplace_back(p);
	  d->setType(col+1, row+1, 'P');
	  theGrid[row][col].setType('P');
	} else if (curr == '1') {
	  Potion * p = new BA(col+1, row+1);
	  thePotion.emplace_back(p);
	  d->setType(col+1, row+1, 'P');
	  theGrid[row][col].setType('P');
	} else if (curr == '2') {
	  Potion * p = new BD(col+1, row+1);
	  thePotion.emplace_back(p);
	  d->setType(col+1, row+1, 'P');
	  theGrid[row][col].setType('P');
	} else if (curr == '3') {
	  Potion * p = new PH(col+1, row+1);
	  thePotion.emplace_back(p);
	  d->setType(col+1, row+1, 'P');
	  theGrid[row][col].setType('P');
	} else if (curr == '4') {
	  Potion * p = new WA(col+1, row+1);
	  thePotion.emplace_back(p);
	  d->setType(col+1, row+1, 'P');
	  theGrid[row][col].setType('P');
	} else if (curr == '5') {
	  Potion * p = new WD(col+1, row+1);
	  thePotion.emplace_back(p);
	  d->setType(col+1, row+1, 'P');
	  theGrid[row][col].setType('P');
	} else if (curr == '6') {
	  Treasure *t = new Normal(col+1, row+1);
	  theTreasure.emplace_back(t);
	  d->setType(col+1, row+1, 'G');
	  theGrid[row][col].setType('G');
	} else if (curr == '7') {
	  Treasure *t = new SmallHoard(col+1, row+1);
	  theTreasure.emplace_back(t);
	  d->setType(col+1, row+1, 'G');
	  theGrid[row][col].setType('G');
	} else if (curr == '8') {
	  Treasure *t = new MerchantHoard(col+1, row+1);
	  theTreasure.emplace_back(t);
	  d->setType(col+1, row+1, 'G');
	  theGrid[row][col].setType('G');
	} else if (curr == '9') {
	  int dX, dY;
	  Treasure *t = new DragonHoard(col+1, row+1);
	  theTreasure.emplace_back(t);
	  d->setType(col+1, row+1, 'G');
	  theGrid[row][col].setType('G');

	  if (d->getType(col+2, row+1) == 'D') {
	    dX = col+2; dY = row+1;
	  } else if (d->getType(col, row+1) == 'D') {
	    dX = col; dY = row+1;
	  } else if (d->getType(col+1, row+2) == 'D') {
	    dX = col+1; dY = row+2;
	  } else if (d->getType(col+1, row) == 'D') {
	    dX = col+1; dY = row;
	  } else if (d->getType(col, row) == 'D') {
	    dX = col; dY = row;
	  } else if (d->getType(col, row+2) == 'D') {
	    dX = col; dY = row+2;
	  } else if (d->getType(col+2, row) == 'D') {
	    dX = col+2; dY = row;
	  } else if (d->getType(col+2, row+2) == 'D') {
	    dX = col+2; dY = row+2;
	  }
	  Dragon *d = new Dragon(dX,dY,t);
	  theGrid[dY-1][dX-1].setType('D');
	  theEnemy.emplace_back(d);
	} else if (curr == '@') {
	  heroX = col+1;
	  heroY = row+1;
	} else if (curr == 'V') {
	  Vampire *v = new Vampire(col+1, row+1);
	  theEnemy.emplace_back(v);
	  theGrid[row][col].setType('V');
	} else if (curr == 'N') {
	  Goblin *n = new Goblin(col+1, row+1);
	  theEnemy.emplace_back(n);
	  theGrid[row][col].setType('N');
	} else if (curr == 'W') {
	  Werewolf *w = new Werewolf(col+1, row+1);
	  theEnemy.emplace_back(w);
	  theGrid[row][col].setType('W');
	} else if (curr == 'T') {
	  Troll *t = new Troll(col+1, row+1);
	  theEnemy.emplace_back(t);
	  theGrid[row][col].setType('T');
	} else if (curr == 'M') {
	  Merchant *m = new Merchant(col+1, row+1);
	  theEnemy.emplace_back(m);
	  theGrid[row][col].setType('M');
	} else if (curr == 'X') {
	  Phoenix *x = new Phoenix(col+1, row+1);
	  theEnemy.emplace_back(x);
	  theGrid[row][col].setType('X');
	} 

      }
      col = 0;
    }
    //int hp, atk, def;
    if (hero == 'h' || hero == 'H') {
        //hp = 140; atk = 20; def = 20;
        heroType = "Human";
        h = new Human(heroX,heroY);
    } else if (hero == 'd'|| hero == 'D') {
        //hp = 10; atk = 20; def = 30;
        heroType = "Dwarf";
        h = new Dwarf(heroX,heroY);
    } else if (hero == 'e' || hero == 'E') {
        //hp = 140; atk = 10; def = 30;
        heroType = "Elf";
        h = new Elf(heroX,heroY);
    } else {
        //hp = 180; atk = 30; def = 25;
        heroType = "Orc";
        h = new Orc(heroX,heroY);
    } 
    theGrid[heroY-1][heroX-1].setType('@');

}

    

	


void Grid::initStair() {
    int chamber;
    while (true){
        chamber = rand()%5;
        if (chamber != heroChamber) break;
    }
    Cell Stair;
    if (chamber == 0) {
        Stair = Chamber1[rand()%Chamber1.size()];
    }
    if (chamber == 1){
        Stair = Chamber2[rand()%Chamber2.size()];
    }
    if (chamber == 2) {
        Stair = Chamber3[rand()%Chamber3.size()];
    }
    if (chamber == 3){
        Stair = Chamber4[rand()%Chamber4.size()];
    }
    if (chamber == 4 ){
        Stair = Chamber5[rand()%Chamber5.size()];
    }
    int rx = Stair.getCol();
    int ry = Stair.getRow();
    d->setType(rx, ry, '\\');
    theGrid[ry-1][rx-1].setType('\\'); 
}


void Grid::initHero(char hero) {
    // get the avalable position
    int chamber = rand()%5;
    Cell Hero;
    if (chamber == 0) {
        Hero = Chamber1[rand()%Chamber1.size()];
    }
    if (chamber == 1){
        Hero = Chamber2[rand()%Chamber2.size()];
    }
    if (chamber == 2) {
        Hero = Chamber3[rand()%Chamber3.size()];
    }
    if (chamber == 3){
        Hero = Chamber4[rand()%Chamber4.size()];
    }
    if (chamber == 4 ){
        Hero = Chamber5[rand()%Chamber5.size()];
    }
    int rx;
    int ry;
    rx = Hero.getCol();
    ry = Hero.getRow();
    heroChamber = chamber;
    //int hp, atk, def;
    if (hero == 'h' || hero == 'H') {
        //hp = 140; atk = 20; def = 20;
        heroType = "Human";
        h = new Human(rx, ry);
    } else if (hero == 'd'|| hero == 'D') {
        //hp = 10; atk = 20; def = 30;
        heroType = "Dwarf";
        h = new Dwarf(rx, ry);
    } else if (hero == 'e' || hero == 'E') {
        //hp = 140; atk = 10; def = 30;
        heroType = "Elf";
        h = new Elf(rx, ry);
    } else {
        //hp = 180; atk = 30; def = 25;
        heroType = "Orc";
        h = new Orc(rx, ry);
    }
    
    d->setType(rx, ry, '@');
    theGrid[ry-1][rx-1].setType('@');
    
}


void Grid::initEnemy() {
    for(int total = 0; total < 20; ++total) {
        
        int rx;
        int ry;
        while(true) {
            int chamber = rand()%5;
            Cell potion;
            if (chamber == 0) {
                potion = Chamber1[rand()%Chamber1.size()];
            }
            if (chamber == 1){
                potion = Chamber2[rand()%Chamber2.size()];
            }
            if (chamber == 2) {
                potion = Chamber3[rand()%Chamber3.size()];
            }
            if (chamber == 3){
                potion = Chamber4[rand()%Chamber4.size()];
            }
            if (chamber == 4 ){
                potion = Chamber5[rand()%Chamber5.size()];
            }
            rx = potion.getCol();
            ry = potion.getRow();
            if (d->getType(rx, ry) == '.') break;
        }   
        
        int type = rand() %18;
        if (type >= 0 && type <= 3) {
            
            Enemy *e = new Werewolf(rx, ry);
            theEnemy.emplace_back(e);
            d->setType(rx, ry, 'W');
            theGrid[ry-1][rx-1].setType('W');
        } else if (type >= 4 && type <= 6) {
            
            Enemy *e = new Vampire(rx, ry);
            theEnemy.emplace_back(e);
            d->setType(rx, ry, 'V');
            theGrid[ry-1][rx-1].setType('V');
        } else if (type >= 7 && type <= 11) {
            
            Enemy *e = new Goblin(rx, ry);
            theEnemy.emplace_back(e);
            d->setType(rx, ry, 'N');
            theGrid[ry-1][rx-1].setType('N');
        } else if (type == 12 || type == 13) {
            
            Enemy *e = new Troll(rx, ry);
            theEnemy.emplace_back(e);
            d->setType(rx, ry, 'T');
            theGrid[ry-1][rx-1].setType('T');
        } else if (type == 14 || type == 15) {
            
            Enemy *e = new Phoenix(rx, ry);
            theEnemy.emplace_back(e);
            d->setType(rx, ry, 'X');
            theGrid[ry-1][rx-1].setType('X');
        } else if (type == 16 || type == 17) {
            
            Enemy *e = new Merchant(rx, ry);
            theEnemy.emplace_back(e);
            d->setType(rx, ry, 'M');
            theGrid[ry-1][rx-1].setType('M');
        }
    }
}


void Grid::initPotion() {
    for(int total = 0; total < 10; ++total) {        
        int rx;
        int ry;
        while(true) {
            int chamber = rand()%5;
            Cell potion;
            if (chamber == 0) {
                potion = Chamber1[rand()%Chamber1.size()];
            }
            if (chamber == 1){
                potion = Chamber2[rand()%Chamber2.size()];
            }
            if (chamber == 2) {
                potion = Chamber3[rand()%Chamber3.size()];
            }
            if (chamber == 3){
                potion = Chamber4[rand()%Chamber4.size()];
            }
            if (chamber == 4 ){
                potion = Chamber5[rand()%Chamber5.size()];
            }
            rx = potion.getCol();
            ry = potion.getRow();
            if (d->getType(rx, ry) == '.') break;
        }
        
        int type = rand() % 6;
        if (type == 0) {
            Potion *p = new RH(rx, ry);
            thePotion.emplace_back(p);
        } else if (type == 1) {
            Potion *p = new BA(rx, ry);
            thePotion.emplace_back(p);
        } else if (type == 2) {
            Potion *p = new BD(rx, ry);
            thePotion.emplace_back(p);
        } else if (type == 3) {
            Potion *p = new PH(rx, ry);
            thePotion.emplace_back(p);
        } else if (type == 4) {
            Potion *p = new WA(rx, ry);
            thePotion.emplace_back(p);
        } else {
            Potion *p = new WD(rx, ry);
            thePotion.emplace_back(p);
        }
        d->setType(rx, ry, 'P');
        theGrid[ry-1][rx-1].setType('P');
        
    }
}


void Grid::initTreasure() {
    
    int rx;
    int ry;
    for(int total = 0; total < 10; ++total) {
        int type = rand() %8;
        if (type >= 0 && type <= 4) {
            
            int rx;
            int ry;
        while(true) {
            int chamber = rand()%5;
            Cell potion;
            if (chamber == 0) {
                potion = Chamber1[rand()%Chamber1.size()];
            }
            if (chamber == 1){
                potion = Chamber2[rand()%Chamber2.size()];
            }
            if (chamber == 2) {
                potion = Chamber3[rand()%Chamber3.size()];
            }
            if (chamber == 3){
                potion = Chamber4[rand()%Chamber4.size()];
            }
            if (chamber == 4 ){
                potion = Chamber5[rand()%Chamber5.size()];
            }
            rx = potion.getCol();
            ry = potion.getRow();
            if (d->getType(rx, ry) == '.') break;
	}
            
            Treasure *t = new Normal(rx, ry);
            theTreasure.emplace_back(t);
            d->setType(rx, ry, 'G');
            theGrid[ry-1][rx-1].setType('G');
        } else if (type == 5 || type == 6) {
            
            int rx;
            int ry;
        while(true) {
            int chamber = rand()%5;
            Cell potion;
            if (chamber == 0) {
                potion = Chamber1[rand()%Chamber1.size()];
            }
            if (chamber == 1){
                potion = Chamber2[rand()%Chamber2.size()];
            }
            if (chamber == 2) {
                potion = Chamber3[rand()%Chamber3.size()];
            }
            if (chamber == 3){
                potion = Chamber4[rand()%Chamber4.size()];
            }
            if (chamber == 4 ){
                potion = Chamber5[rand()%Chamber5.size()];
            }
            rx = potion.getCol();
            ry = potion.getRow();
            if (d->getType(rx, ry) == '.') break;
	}
            
            Treasure *t = new SmallHoard(rx, ry);
            theTreasure.emplace_back(t);
            d->setType(rx, ry, 'G');
            theGrid[ry-1][rx-1].setType('G');
        } else {
	    int rx;
            int ry;
            
            while(true) {
            int chamber = rand()%5;
            Cell potion;
            if (chamber == 0) {
                potion = Chamber1[rand()%Chamber1.size()];
            }
            if (chamber == 1){
                potion = Chamber2[rand()%Chamber2.size()];
            }
            if (chamber == 2) {
                potion = Chamber3[rand()%Chamber3.size()];
            }
            if (chamber == 3){
                potion = Chamber4[rand()%Chamber4.size()];
            }
            if (chamber == 4 ){
                potion = Chamber5[rand()%Chamber5.size()];
            }
            rx = potion.getCol()-1;
            ry = potion.getRow()-1;
                
	    if ((d->getType(rx+1, ry+1) == '.') &&
	       ((d->getType(rx, ry+1) == '.') ||
                (d->getType(rx+2, ry+1) == '.') ||
                (d->getType(rx+1, ry) == '.') ||
                (d->getType(rx+1, ry+2) == '.') ||
                (d->getType(rx, ry) == '.') ||
                (d->getType(rx+2, ry) == '.') ||
                (d->getType(rx, ry+2) == '.') ||
                (d->getType(rx+2, ry+2) == '.')))
                break;
            }
            
            if(d->getType(rx, ry+1) == '.') {
                Treasure *t = new DragonHoard(rx+1, ry+1);
                theTreasure.emplace_back(t);
                d->setType(rx+1, ry+1, 'G');
                theGrid[ry][rx].setType('G');
                
                Dragon *dr = new Dragon(rx, ry+1,t);
                theEnemy.emplace_back(dr);
                d->setType(rx, ry+1, 'D');
                theGrid[ry][rx-1].setType('D');

            } else if (d->getType(rx+2, ry+1) == '.') {
                Treasure *t = new DragonHoard(rx+1, ry+1);
                theTreasure.emplace_back(t);
                d->setType(rx+1, ry+1, 'G');
                theGrid[ry][rx].setType('G');
                
                Dragon *dr = new Dragon(rx+2, ry+1,t);
                theEnemy.emplace_back(dr);
                d->setType(rx+2, ry+1, 'D');
                theGrid[ry][rx+1].setType('D');

            } else if (d->getType(rx+1, ry) == '.') {
                
                Treasure *t = new DragonHoard(rx+1, ry+1);
                theTreasure.emplace_back(t);
                d->setType(rx+1, ry+1, 'G');
                theGrid[ry][rx].setType('G');
                
                Dragon *dr = new Dragon(rx+1, ry, t);
                theEnemy.emplace_back(dr);
                d->setType(rx+1, ry, 'D');
                theGrid[ry-1][rx].setType('D');

            } else if (d->getType(rx+1, ry+2) == '.') {
                Treasure *t = new DragonHoard(rx+1, ry+1);
                theTreasure.emplace_back(t);
                d->setType(rx+1, ry+1, 'G');
                theGrid[ry][rx].setType('G');

                Dragon *dr = new Dragon(rx+1, ry+2,t);
                theEnemy.emplace_back(dr);
                d->setType(rx+1, ry+2, 'D');
                theGrid[ry+1][rx].setType('D');

            } else if (d->getType(rx, ry) == '.') {
                Treasure *t = new DragonHoard(rx+1, ry+1);
                theTreasure.emplace_back(t);
                d->setType(rx+1, ry+1, 'G');
                theGrid[ry][rx].setType('G');
                
                Dragon *dr = new Dragon(rx, ry,t);
                theEnemy.emplace_back(dr);
                d->setType(rx, ry, 'D');
                theGrid[ry-1][rx-1].setType('D');

            } else if (d->getType(rx+2, ry) == '.') {
                Treasure *t = new DragonHoard(rx+1, ry+1);
                theTreasure.emplace_back(t);
                d->setType(rx+1, ry+1, 'G');
                theGrid[ry][rx].setType('G');
                
                Dragon *dr = new Dragon(rx+2, ry, t);
                theEnemy.emplace_back(dr);
                d->setType(rx+2, ry, 'D');
                theGrid[ry-1][rx+1].setType('D');

            } else if (d->getType(rx, ry+2) == '.') {
                Treasure *t = new DragonHoard(rx+1, ry+1);
                theTreasure.emplace_back(t);
                d->setType(rx+1, ry+1, 'G');
                theGrid[ry][rx].setType('G');
                
                Dragon *dr = new Dragon(rx, ry+2,t);
                theEnemy.emplace_back(dr);
                d->setType(rx, ry+2, 'D');
                theGrid[ry+1][rx-1].setType('D');

            } else {
                Treasure *t = new DragonHoard(rx+1, ry+1);
                theTreasure.emplace_back(t);
                d->setType(rx+1, ry+1, 'G');
                theGrid[ry][rx].setType('G');
                
                Dragon *dr = new Dragon(rx+2, ry+2,t);
                theEnemy.emplace_back(dr);
                d->setType(rx+2, ry+2, 'D');
                theGrid[ry+1][rx+1].setType('D');

            }
        }
    }
}


int Grid::getFloor() const {
    return floor;
}


bool Grid::isWon() const {
    return won;
}

bool Grid::isLose() const {
    return lose;
}

bool Grid::isDie() const {
    return (h->getHP() == 0);
}

bool Grid::atStair() const {
    int x = h->getX();
    int y = h->getY();
    return (d->getType(x, y) == '\\');
}


void Grid::print() {
    cout << (*d);
    cout << "Race: " << heroType << " Gold: " << h->getGold();
    cout << "                                                   ";
    cout << "Floor " << floor << endl;
    cout << "HP: " << h->getHP() << endl;
    cout << "Atk: " << h->getATK() << endl;
    cout << "Def: " << h->getDEF() << endl;
    cout << "Action: ";
    
}


void Grid::init(char hero) {
    clear();  
    for (int i=4; i <= 29; ++i) {
        for (int k=4; k<=7; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber1.push_back(aCell);
        }
    }
    
    for (int i=5; i <= 25; ++i){
        for (int k=16; k<=22; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber2.push_back(aCell);
        }
    }

    for (int i=39; i <= 50; ++i) {
        for (int k=11; k<= 13; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber3.push_back(aCell);
        }
    }
    
    for (int i=40; i <= 62; ++i) {
        for (int k=4; k<= 7; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber4.push_back(aCell);
        }
    }
    
    for (int i=62; i <= 76; ++i) {
        for (int k=8; k<= 13; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber4.push_back(aCell);
        }
    }
    
    for (int i=63; i <= 70; ++i) {
        Cell aCell;
        aCell.setCoords(i, 6);
        Chamber4.push_back(aCell);
    }
    
    for (int i=63; i <= 73; ++i) {
        Cell aCell;
        aCell.setCoords(i, 7);
        Chamber4.push_back(aCell);
    }
    
    for (int i=38; i <= 76; ++i) {
        for (int k=20; k<= 22; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber5.push_back(aCell);
        }
    }
    
    for (int i=66; i <= 76; ++i) {
        for (int k=17; k<= 19; ++k){
            Cell aCell;
            aCell.setCoords(i, k);
            Chamber5.push_back(aCell);
        }
    }

       
    x = 79;
    y = 25;
    initDisplay();
    
    // create cells
    for(int row = 0; row < y; ++row) {
        // create the inside vector
        std::vector<Cell> rowCell;
        for(int col = 0; col < x; ++col) {
            Cell aCell;
            aCell.setCoords(col, row);
            char t = d->getType(col+1, row+1);
            aCell.setType(t);
            rowCell.push_back(aCell);
        }
        theGrid.push_back(rowCell);
    }
    
    // attach cells;
    for (int row = 0; row < y; ++row) {
        for(int col = 0; col < x; ++col) {
            // the left cell
            if (col - 1 >= 0) {
                theGrid[row][col].attach(&theGrid[row][col-1]);
            }
            // the right cell
            if (col + 1 < x) {
                theGrid[row][col].attach(&theGrid[row][col+1]);
            }
            // the up cell
            if (row - 1 >= 0) {
                theGrid[row][col].attach(&theGrid[row-1][col]);
            }
            // the down cell
            if (row + 1 < y) {
                theGrid[row][col].attach(&theGrid[row+1][col]);
            }
            // the up left cell
            if (row - 1 >= 0 && col - 1 >= 0) {
                theGrid[row][col].attach(&theGrid[row-1][col-1]);
            }
            // the up right cell
            if (row - 1 >= 0 && col + 1 < x) {
                theGrid[row][col].attach(&theGrid[row-1][col+1]);
            }
            // the down left cell
            if (row + 1 < y && col - 1 >= 0) {
                theGrid[row][col].attach(&theGrid[row+1][col-1]);
            }
            // the down right cell
            if (row + 1 < y && col +1 < x) {
                theGrid[row][col].attach(&theGrid[row+1][col+1]);
            }
            
            //attach the all display
            theGrid[row][col].attach(d);
        }
    }
    initHero(hero);
    initStair();
    initPotion();
    initTreasure();
    initEnemy();
}


void Grid::randomMove(){
    for (vector<Enemy *>::iterator it = theEnemy.begin(); it !=theEnemy.end(); ++it){

        if ((*it)->getType() == "Dragon") continue;
        int currX = (*it)->getX();
        int currY = (*it)->getY();
        if ((d->getType(currX-1, currY) != '.') &&
            (d->getType(currX+1, currY) != '.') &&
            (d->getType(currX, currY-1) != '.') &&
            (d->getType(currX, currY+1) != '.') &&
            (d->getType(currX-1, currY-1) != '.') &&
            (d->getType(currX-1, currY+1) != '.') &&
            (d->getType(currX+1, currY-1) != '.') &&
            (d->getType(currX+1, currY+1) != '.')) continue;
        int randomX;
        int randomY;
        while (true){
            randomX = currX+rand()%3-1;
            randomY = currY+rand()%3-1;
            if (d->getType(randomX, randomY) == '.') break;
        }

        char original = originalMap->getType(currX, currY);
        d->setType(currX, currY, original);
        string s = (*it)->getType();
        int typeC;
        if (s == "Vampire") {typeC = 'V';}
        if (s == "Werewolf") {typeC = 'W';}
        if (s == "Goblin") {typeC = 'N';}
        if (s == "Troll") {typeC = 'T';}
        if (s == "Phoenix") {typeC = 'X';}
        if (s == "Merchant") {typeC = 'M';}
        d->setType(randomX, randomY, typeC);
        theGrid[randomY-1][randomX-1].setType(typeC);
        theGrid[currY-1][currX-1].setType(original);

        (*it)->move(randomX, randomY);

    }


}


string Grid::checkPotionOneDir(string direction, bool have) {
    //get potion's position
    int currX;
    int currY;
    currX = h->getX();
    currY = h->getY();
    int potionX;
    int potionY;
    if (direction == "no") {
        potionX = currX;
        potionY = currY - 1;
    } else if (direction == "so") {
        potionX = currX;
        potionY = currY + 1;
    } else if (direction == "ea") {
        potionX = currX + 1;
        potionY = currY;
    } else if (direction == "we") {
        potionX = currX - 1;
        potionY = currY;
    } else if (direction == "ne") {
        potionX = currX + 1;
        potionY = currY - 1;
    } else if (direction == "nw") {
        potionX = currX - 1;
        potionY = currY - 1;
    } else if (direction == "se") {
        potionX = currX + 1;
        potionY = currY + 1;
    } else {
        potionX = currX - 1;
        potionY = currY + 1;
    }

    // if see potion check if if it is known, if there is potion before, print action
    if(d->getType(potionX, potionY) == 'P') {
	string m;
	if (have) {
	  m =  ", ";
	} else {
	  m = " and sees ";
	}

	unsigned long s = thePotion.size();
	int i = 0;
	while (i < s) {
          if (thePotion[i]->getX() == potionX && thePotion[i]->getY() == potionY) break;
          else ++i;
	}

	if(thePotion[i]->getIden()) {
          string potionType = thePotion[i]->getType();
	  m += "a " + potionType;
	} else {
	  m += "an unknown potion";
	} 
	return m;
    } else {
	return "";
    }
}


string Grid::checkPotion() {
    bool have = false;
    string m1,m2,m3,m4,m5,m6,m7,m8;
    m1 = checkPotionOneDir("no", have);
    if (m1 != "") have = true;
    m2 = checkPotionOneDir("so", have);
    if (m2 != "") have = true;
    m3 = checkPotionOneDir("we", have);
    if (m3 != "") have = true;
    m4 = checkPotionOneDir("ea", have);
    if (m4 != "") have = true;
    m5 = checkPotionOneDir("nw", have);
    if (m5 != "") have = true;
    m6 = checkPotionOneDir("ne", have);
    if (m6 != "") have = true;
    m7 = checkPotionOneDir("sw", have);
    if (m7 != "") have = true;
    m8 = checkPotionOneDir("se", have);
    return m1+m2+m3+m4+m5+m6+m7+m8+".\n";
}


string Grid::checkEnemyOneDir(string direction, bool needSpace) {

  // get enemy position
  int currX, currY, enemyX, enemyY;
  currX = h->getX();
  currY = h->getY();

  if (direction == "no") {
    enemyX = currX;
    enemyY = currY - 1;
  } else if (direction == "so") {
    enemyX = currX;
    enemyY = currY + 1;
  } else if (direction == "ea") {
    enemyX = currX + 1;
    enemyY = currY;
  } else if (direction == "we") {
    enemyX = currX - 1;
    enemyY = currY;
  } else if (direction == "ne") {
    enemyX = currX + 1;
    enemyY = currY - 1;
  } else if (direction == "nw") {
    enemyX = currX - 1;
    enemyY = currY - 1;
  } else if (direction == "se") {
    enemyX = currX + 1;
    enemyY = currY + 1;
  } else {
    enemyX = currX - 1;
    enemyY = currY + 1;
  }

  char c = d->getType(enemyX, enemyY);
  if (c != 'V' && c != 'W' && c != 'N' && c != 'M' && 
      c != 'D' && c != 'X' && c != 'T' && c != 'M' ) return "";

  // find the corresponding enemy
  unsigned long s = theEnemy.size();
  int i = 0;
  for(; i < s; ++i) { if(theEnemy[i]->getX() == enemyX && theEnemy[i]->getY() == enemyY) break; }
  
  if(!theEnemy[i]->getHostile()) return ""; // the Enemy is not Hostile

  string m = "";
  // the enemy is Hostile, do the attack
  int PCOriginalHP = h->getHP();
  string enemyType = theEnemy[i]->getType();
  h->attackBy(enemyType);

  int PCCurrHP = h->getHP();
  // print the action 
  if(needSpace) { m += "        "; } 
  m += string(1,c) + " deals " + to_string(PCOriginalHP - PCCurrHP) + " damage to PC.\n";

  // check if enemy and hero are dead
  if (h->getHP() == 0) {
    lose = true;
    char original = originalMap->getType(currX, currY);
    d->setType(currX, currY, original);
    theGrid[currY-1][currX-1].setType(original);
    m += "Player was killed by " + enemyType;
    m += "\nYou lose the game!\n";
  }
  return m;
}


string Grid::checkAttack() {
    bool needSpace = true;
    string m1,m2,m3,m4,m5,m6,m7,m8;
    m1 = checkEnemyOneDir("no", needSpace);
    m2 = checkEnemyOneDir("so", needSpace);
    m3 = checkEnemyOneDir("we", needSpace);
    m4 = checkEnemyOneDir("ea", needSpace);
    m5 = checkEnemyOneDir("nw", needSpace);
    m6 = checkEnemyOneDir("ne", needSpace);
    m7 = checkEnemyOneDir("sw", needSpace);
    m8 = checkEnemyOneDir("se", needSpace);
    return m1+m2+m3+m4+m5+m6+m7+m8;
}


//*********************************************************************************  move
void Grid::move(string direction) {
    string fullDirection;
    // get current position
    int currX, currY, nextX, nextY;
    currX = h->getX();
    currY = h->getY();
        
    if (direction == "no") {
        nextX = currX;
        nextY = currY - 1;
        fullDirection = "North";
    } else if (direction == "so") {
        nextX = currX;
        nextY = currY + 1;
        fullDirection = "South";
    } else if (direction == "ea") {
        nextX = currX + 1;
        nextY = currY;
        fullDirection = "East";
    } else if (direction == "we") {
        nextX = currX - 1;
        nextY = currY;
        fullDirection = "West";
    } else if (direction == "ne") {
        nextX = currX + 1;
        nextY = currY - 1;
        fullDirection = "Northeast";
    } else if (direction == "nw") {
        nextX = currX - 1;
        nextY = currY - 1;
        fullDirection = "Northwest";
    } else if (direction == "se") {
        nextX = currX + 1;
        nextY = currY + 1;
        fullDirection = "Southeast";
    } else {
        nextX = currX - 1;
        nextY = currY + 1;
        fullDirection = "Southwest";
    }
    
    // check whether the next point of moving is valid or not
    if ((!(nextX >= 1 && nextX <= 79)) || (!(nextY >= 1 && nextY <=25))) {
        print();
        cout << "PC unable move into places out of the map. Invalid input." << endl;
        return;
    }
    char c = d->getType(nextX, nextY);

    // invalid position
    if (c != '.' && c != '+' && c != '#' && c != 'G' && c!= '\\') {
        print();
        cout << "PC unable to move onto Enemy or Potion or Wall. Invalid input." << endl;
        return;
    }
    
    // go upstairs
    if (c == '\\') {
	if (floor == 5) {
	  won = true;
	  return;
	}
        int currHP = h->getHP();
	int currGold = h->getGold();
        char t = heroType[0];
        init(t);
        h->setHP(currHP);
        h->setGold(currGold);
	++floor;
	print();
	cout << "PC moves " << fullDirection << " and go upstairs." << endl;
	return;
    } 
    
    // get gold
    if (c == 'G') {
        unsigned long s = theTreasure.size();
        int i = 0;
        for(; i < s; ++i) {
            if(theTreasure[i]->getX() == nextX &&
               theTreasure[i]->getY() == nextY) break;
        }
        if (theTreasure[i]->getGold() == 6){
            if (theTreasure[i]->getOpenable() == false){
                cout << "You must kill the Dragon to get DragonHoard"<<endl;
                return;
            }
        }
        h->getTreasure(theTreasure[i]);
        char original = originalMap->getType(currX, currY);
        d->setType(currX, currY, original);
        d->setType(nextX, nextY, '@');
        theGrid[nextY-1][nextX-1].setType('@');
        theTreasure.erase(theTreasure.begin() + i);
        theGrid[currY-1][currX-1].setType(original);
        h->move(nextX,nextY);
    }

    // ordinary move
    if (c == '.' || c == '+' || c == '#') {

        char original = originalMap->getType(currX, currY);

        d->setType(currX, currY, original);
        d->setType(nextX, nextY, '@');
        theGrid[nextY-1][nextX-1].setType('@');
        theGrid[currY-1][currX-1].setType(original);
        h->move(nextX, nextY);
    }    
    randomMove();	

    string message;
    message = "Action: PC moves " + fullDirection;

    // After moving, checking if there is some thing around and make Action change.
    message += checkPotion();
    message += checkAttack();
    cout << (*d);
    cout << "Race: " << heroType << " Gold: " << h->getGold();
    cout << "                                                   ";
    cout << "Floor " << floor << endl;
    cout << "HP: " << h->getHP() << endl;
    cout << "Atk: " << h->getATK() << endl;
    cout << "Def: " << h->getDEF() << endl;
    cout << message;

}


void Grid::attack(string direction) {

  // get enemy position
  int currX, currY, enemyX, enemyY;
  currX = h->getX();
  currY = h->getY(); 

  if (direction == "no") {
    enemyX = currX;
    enemyY = currY - 1;
  } else if (direction == "so") {
    enemyX = currX;
    enemyY = currY + 1;
  } else if (direction == "ea") {
    enemyX = currX + 1;
    enemyY = currY;
  } else if (direction == "we") {
    enemyX = currX - 1;
    enemyY = currY;
  } else if (direction == "ne") {
    enemyX = currX + 1;
    enemyY = currY - 1;
  } else if (direction == "nw") {
    enemyX = currX - 1;
    enemyY = currY - 1;
  } else if (direction == "se") {
    enemyX = currX + 1;
    enemyY = currY + 1;
  } else {
    enemyX = currX - 1;
    enemyY = currY + 1;
  }

  // check whether enemy position is valid
  if ((!(enemyX >= 1 && enemyX <= 79)) || (!(enemyY >= 1 && enemyY <=25))) {
    cout << "Cannot attack. Direction beyond the map." << endl;
    return;
  }
  char c = d->getType(enemyX, enemyY);
  if (c != 'V' && c != 'W' && c != 'N' && c != 'M' && c != 'D' &&
      c != 'X' && c != 'T' && c != 'M' ) {
    cout << "Cannot attack. There is no enemy on that direction." << endl;
    return;
  }


  // find the corresponding enemy
  unsigned long s = theEnemy.size();
  int i = 0;
  for(; i < s; ++i) {
    if(theEnemy[i]->getX() == enemyX && theEnemy[i]->getY() == enemyY) break;
  }

  // do the attack
  int PCOriginalHP = h->getHP();
  int EnemyOriginalHP = theEnemy[i]->getHP();
  string enemyType = theEnemy[i]->getType();
  h->attackBy(enemyType);
  theEnemy[i]->attackBy(h);
  int PCCurrHP = h->getHP();
  int EnemyCurrHP = theEnemy[i]->getHP();

  // check if enemy and hero are dead

  if (h->getHP() == 0) {
    lose = true;
    char original = originalMap->getType(currX, currY);
    d->setType(currX, currY, original);
    theGrid[currY-1][currX-1].setType(original);
    print();
    cout << "PC deals " << EnemyOriginalHP - EnemyCurrHP;
    cout << " damage to " << c << " (" << EnemyCurrHP << " HP). ";
    cout << c << " deals " << PCOriginalHP - PCCurrHP;
    cout << " damage to PC.";

    cout << " Player was killed." << endl;
    cout << "You lose the game!" << endl;
    return;
  }
  if (theEnemy[i]->getHP() == 0) {
      if (theEnemy[i]->getType() == "Merchant"){
          d->setType(enemyX, enemyY, 'G');
          theGrid[enemyY-1][enemyX-1].setType('G');
          theEnemy.erase(theEnemy.begin() + i);
          Treasure *t = new MerchantHoard(enemyX, enemyY);
          theTreasure.emplace_back(t);
      } else {
          if (theEnemy[i]->getType() != "Dragon") h->pickGold();
          char original = originalMap->getType(enemyX,enemyY);
          d->setType(enemyX, enemyY, original);
          theGrid[enemyY-1][enemyX-1].setType(original);
          theEnemy.erase(theEnemy.begin() + i);
      }
    print();
    cout << "PC deals " << EnemyOriginalHP - EnemyCurrHP;
    cout << " damage to " << c << " (" << EnemyCurrHP << " HP). ";
    cout << c << " deals " << PCOriginalHP - PCCurrHP;
    cout << " damage to PC.";
    cout << " Killed the " << enemyType << "." << endl;
    //return;
  } else {
  print();
  cout << "PC deals " << EnemyOriginalHP - EnemyCurrHP;
  cout << " damage to " << c << " (" << EnemyCurrHP << " HP). ";
  cout << c << " deals " << PCOriginalHP - PCCurrHP;
  cout << " damage to PC." << endl;
  }
}

void Grid::buy(std::string direction){
    int currX;
    int currY;
    currX = h->getX();
    currY = h->getY();
    int merchantX;
    int merchantY;
    if (direction == "no") {
        merchantX = currX;
        merchantY = currY - 1;
    } else if (direction == "so") {
        merchantX = currX;
        merchantY = currY + 1;
    } else if (direction == "ea") {
        merchantX = currX + 1;
        merchantY = currY;
    } else if (direction == "we") {
        merchantX = currX - 1;
        merchantY = currY;
    } else if (direction == "ne") {
        merchantX = currX + 1;
        merchantY = currY - 1;
    } else if (direction == "nw") {
        merchantX = currX - 1;
        merchantY = currY - 1;
    } else if (direction == "se") {
        merchantX = currX + 1;
        merchantY = currY + 1;
    } else {
        merchantX = currX - 1;
        merchantY = currY + 1;
    }
    
    //check whether potion's position is valid
    if ((!(merchantX >= 1 && merchantX <= 79)) || (!(merchantY >= 1 && merchantY <=25))) {
        cout << "Cannot get there. Direction beyond the map." << endl;
        return;
    }
    
    //check is the aiming position has a potion
    char c = d->getType(merchantX, merchantY);
    if (c != 'M') {
        cout << "There is no Merchant on that direction." << endl;
        return;
    }
    if (h->getGold() < 5){
        cout << "Don't you even have 5 golds?" <<endl;
        return;
    }
    cout <<"Welcome to the shop!" <<endl;
    cout <<"Please choose the Potion you want to purchase: (Cost 5 golds)"<<endl;
    cout <<"[RH] Restore health: restore up to 10 HP"<< endl;
    cout <<"[BA] Boost Atk: increase ATK by 5" <<endl;
    cout <<"[BD] Boost Def: increase Def by 5" <<endl;
    string p;
    while (true){
       cin >> p;
       if (p == "RH" || p == "BA" || p == "BD") break;
       cout << "We only sell potions right now" <<endl;
       cout << "You have to buy something to leave the shop" <<endl;
    } 
    h->buy(p);
    print();
    cout << "You purchase a " << p << " Potion." <<endl;
    cout << "See ya~!" <<endl;
}

void Grid::use(string direction) {
    //get potion's position
    int currX;
    int currY;
    currX = h->getX();
    currY = h->getY();
    int potionX;
    int potionY;
    if (direction == "no") {
        potionX = currX;
        potionY = currY - 1;
    } else if (direction == "so") {
        potionX = currX;
        potionY = currY + 1;
    } else if (direction == "ea") {
        potionX = currX + 1;
        potionY = currY;
    } else if (direction == "we") {
        potionX = currX - 1;
        potionY = currY;
    } else if (direction == "ne") {
        potionX = currX + 1;
        potionY = currY - 1;
    } else if (direction == "nw") {
        potionX = currX - 1;
        potionY = currY - 1;
    } else if (direction == "se") {
        potionX = currX + 1;
        potionY = currY + 1;
    } else {
        potionX = currX - 1;
        potionY = currY + 1;
    }
    
    //check whether potion's position is valid
    if ((!(potionX >= 1 && potionX <= 79)) || (!(potionY >= 1 && potionY <=25))) {
        cout << "Cannot get there. Direction beyond the map." << endl;
        return;
    }
    
    //check is the aiming position has a potion
    char c = d->getType(potionX, potionY);
    if (c != 'P') {
        cout << "There is no potion on that direction." << endl;
        return;
    }
    
    //use the fucking potion
    
    unsigned long s = thePotion.size();
    int i = 0;
    while (i < s) {
        if (thePotion[i]->getX() == potionX && thePotion[i]->getY() == potionY) break;
        else ++i;
    }
    string potionType = thePotion[i]->getType();

    // set back to original point
    char original = originalMap->getType(potionX,potionY);
    d->setType(potionX, potionY, original);
    theGrid[potionY-1][potionX-1].setType(original);

    h->getPotion(potionType);

    print();
    cout << "Use " << potionType << " potion." << endl;
    thePotion[i]->usedBy();
    
    //should delete the potion here
    thePotion.erase(thePotion.begin() + i);
}




ostream &operator<<(ostream &out, const Grid &g) {
  Display &dis = *(g.d);
  out << dis;
  out << "Race: " << g.heroType << " Gold: " << g.h->getGold();
  out << "                                                   ";
  out << "Floor " << g.floor << endl;
  out << "HP: " << g.h->getHP() << endl;
  out << "Atk: " << g.h->getATK() << endl;
  out << "Def: " << g.h->getDEF() << endl;
  return out;
}











