//
//  Tile.cpp
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "Tile.h"

void Tile::desert() {
    
}

class Restaurant:Tile {
    bool action( Player& player) {
        player.food = 10;
        return true;
    }
};

class Spice_Merchant:Tile {
    bool action( Player& player) {
        if (player.gold >= 2 && (player.spice + player.ruby
                                 + player.spice + player.jewel) < 9) {
            player.gold -= 2;
            switch (player.spice + player.ruby + player.fabric + player.jewel) {
                case 8:
                    player.spice ++;
                    break;
                case 7:
                    player.spice += 2;
                    break;
                default:
                    player.spice += 3;
            }
            return true;
        }
        return false;
    }
};

class Fabric_Manufactures:Tile {
    bool action( Player& player) {
        if (player.gold >= 2 && (player.spice + player.ruby
                                 + player.spice + player.jewel) < 9) {
            player.gold -= 2;
            switch (player.spice + player.ruby + player.fabric + player.jewel) {
                case 8:
                    player.fabric++;
                    break;
                case 7:
                    player.fabric += 2;
                    break;
                default:
                    player.fabric += 3;
            }
            return true;
        }
        return false;
    }
};