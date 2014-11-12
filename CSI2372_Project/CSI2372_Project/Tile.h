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
    bool operator==(const Tile &t);
    virtual bool action( Player& player );
    virtual Tile* clone();
    ostream& operator<<(const Tile &t);
    void desert();
};

#endif /* defined(__C___Project__Tile__) */
