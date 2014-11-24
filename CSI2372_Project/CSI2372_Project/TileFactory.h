//
//  TileFactory.h
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-20.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __C___Project__TileFactory__
#define __C___Project__TileFactory__

#include <stdio.h>
#include "Tile.h"
#include "Tile.cpp"

class TileFactory {
    int _nTiles;
    static bool instanceFlag;
    TileFactory(int);
public:
    static TileFactory *get(int);

    Tile* next(); //return new tile
};


#endif /* defined(__C___Project__TileFactory__) */
