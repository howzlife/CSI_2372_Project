//
//  Tile.h
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __C___Project__Tile__
#define __C___Project__Tile__
#include <iostream>
#include "Player.h"
#include <stdio.h>
using namespace std;

class Tile {
public:
    string name;
    friend bool operator==(const Tile &lhs, const Tile &rhs) {
        if (lhs.name == rhs.name) return true;
        return false;
    };
    virtual bool action(Player& player );
    virtual Tile* clone();
    
    friend ostream& operator<<(ostream &os, Tile& tile1) {
        os << tile1.name;
        return os;
    }
};



#endif /* defined(__C___Project__Tile__) */
