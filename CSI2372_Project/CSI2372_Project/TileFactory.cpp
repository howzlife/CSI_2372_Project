//
//  TileFactory.cpp -> DONE
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-20.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "TileFactory.h"
#include <iostream>
#include <vector>
using namespace std;

TileFactory::TileFactory(int numTiles) {
    if (! instanceFlag) {
    int numInstances = numTiles / 14;
    
    for (int i = 0; i < numTiles - numInstances; ++i) {
        tileContainer.push_back(new Tile);
    }
    int counter = numInstances - 1;
    do {
        int whichTile = rand() % 13;
        switch (whichTile) {
            case 0:
                tileContainer.push_back(new Restaurant);
                break;
            case 1:
                tileContainer.push_back(new Spice_Merchant);
                break;
            case 2:
                tileContainer.push_back(new Fabric_Manufactures);
                break;
            case 3:
                tileContainer.push_back(new Jeweler);
                break;
            case 4:
                tileContainer.push_back(new Cart_Manufacturer);
                break;
            case 5:
                tileContainer.push_back(new Small_Market);
                break;
            case 6:
                tileContainer.push_back(new Spice_Market);
                break;
            case 7:
                tileContainer.push_back(new Jewelry_Market);
                break;
            case 8:
                tileContainer.push_back(new Fabric_Market);
                break;
            case 9:
                tileContainer.push_back(new Black_Market);
                break;
            case 10:
                tileContainer.push_back(new Casino);
                break;
            case 11:
                tileContainer.push_back(new Gem_Merchant);
            case 12:
                tileContainer.push_back(new Palace);
                break;
        }
        --counter;
    } while (counter > 0);
    //Add a restaurant as starting tile
    tileContainer.push_back(new Restaurant);
    //shuffle tiles, set iterator
    std::random_shuffle(tileContainer.begin(), tileContainer.end(), [] (int i) { return rand() % i; });
    it = tileContainer.begin();
        instanceFlag = true;
    }
}

//Get next tile in the board.

Tile* TileFactory::next() {
    Tile* t = *it;
    it++;
    return t;
}

 TileFactory* TileFactory::get(int _nTiles)
{
        static TileFactory tf(_nTiles);
        return &tf;
}