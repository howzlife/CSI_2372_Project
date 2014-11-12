//
//  Player.h
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __C___Project__Player__
#define __C___Project__Player__

#include <stdio.h>
#include "Tile.h"
using namespace std;

class Player {
protected:
    friend class Tile;
    friend class Desert;
    friend class Restaurant;
    friend class Spice_Merchant;
    friend class Fabric_Manufactures;
    friend class Jeweler;
    friend class Cart_Manufacturer;
    friend class Small_Market;
    friend class Spice_Market;
    friend class Jewelry_Market;
    friend class Fabric_Market;
    friend class Black_Market;
    int gold;
    int ruby;
    int spice;
    int fabric;
    int jewel;
    int cart;
    int food;
    
public:
    Player();
    bool canAct() const;
    bool pay( Player& player);
    void eat();
};

#endif /* defined(__C___Project__Player__) */
