//
//  TileFactory.h -> DONE
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-20.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __C___Project__TileFactory__
#define __C___Project__TileFactory__

#include <stdio.h>
#include "Tile.h"
#include <vector>
#include <iostream>

class TileFactory {
    bool instanceFlag = false;
    vector<Tile*> tileContainer;
    TileFactory(int);
    Tile* getTile();
public:
    vector<Tile*>::iterator it;
    static TileFactory *get(int);
    Tile* next(); //return new tile
};


#endif /* defined(__C___Project__TileFactory__) */
