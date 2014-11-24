//
//  TileFactory.cpp
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-20.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "TileFactory.h"
#include <vector>
using namespace std;

TileFactory::TileFactory(int numTiles) {
    int numInstances = numTiles / 14;
    int numDesert = numTiles % 14;
    
    std::vector<std::unique_ptr<Tile>> tiles;
    for (int i = 0; i < numInstances; i++) {
        tiles.emplace_back(new Desert());
        tiles.emplace_back(new Restaurant);
        tiles.emplace_back(new Spice_Merchant);
        tiles.emplace_back(new Fabric_Manufactures);
        tiles.emplace_back(new Jeweler);
        tiles.emplace_back(new Cart_Manufacturer);
        tiles.emplace_back(new Small_Market);
        tiles.emplace_back(new Spice_Market);
        tiles.emplace_back(new Jewelry_Market);
        tiles.emplace_back(new Fabric_Market);
        tiles.emplace_back(new Black_Market);
        tiles.emplace_back(new Casino);
        tiles.emplace_back(new GemMerchant);
        tiles.emplace_back(new Palace);
    }
    
    for (int j = 0; j < numDesert; j++) {
        tiles.emplace_back(new Desert());
    }
    
    std::random_shuffle(tiles.begin(), tiles.end());
    
}

 TileFactory* TileFactory::get(int _nTiles)
{
    if (!instanceFlag) {
        static TileFactory tf(_nTiles);
        instanceFlag = true;
        return &tf;
    }
    return NULL;
}