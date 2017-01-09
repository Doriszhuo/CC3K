#include "Display.h"
#include <fstream>
#include <sstream>
using namespace std;

Display::Display(string filename):
x{79}, y{25} {
    ifstream file{filename};
    string s;
    while (getline(file,s)) {
        vector<char> oneRow;
        for(int i = 0; i < x; ++i) {
            oneRow.emplace_back(s[i]);
        }
        theDisplay.emplace_back(oneRow);
    }
}


Display::~Display() {
   // for(int i = 0; i < y; ++i){
  //      theDisplay[i].clear();
// cout << "Delete: " << i << endl;
 //   }
    theDisplay.clear();
}


void Display::notify(Cell &c, char newType) {
    
}

char Display::getType(int x, int y) {
    return theDisplay[y-1][x-1];
}


void Display::setType(int x, int y, char type) {
    theDisplay[y-1][x-1] = type;
}

SubscriptionType Display::subType() {
    return SubscriptionType::All;
}


ostream &operator<<(ostream &out, const Display &d) {
    for (int row = 0; row < d.y; ++row) {
        for(int col = 0; col < d.x; ++col) {
            out << (d.theDisplay)[row][col];
        }
        out << endl;
    }
    return out;
}


