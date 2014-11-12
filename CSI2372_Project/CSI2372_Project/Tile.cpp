//
//  Tile.cpp
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "Tile.h"
#include <stdlib.h>
using namespace std;

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
                                 + player.fabric + player.jewel) < player.cart) {
            player.gold -= 2;
            player.spice += 3;
            if ((player.spice + player.ruby
                 + player.fabric + player.jewel) > player.cart) {
                player.spice -= ((player.spice + player.ruby
                                  + player.fabric + player.jewel) - player.cart );
            }
            return true;
        }
        return false;
    }
};

class Fabric_Manufactures:Tile {
    bool action( Player& player) {
        if (player.gold >= 2 && (player.spice + player.ruby
                                 + player.fabric + player.jewel) < player.cart) {
            player.gold -= 2;
            player.fabric += 3;
            if ((player.spice + player.ruby
                 + player.fabric + player.jewel) > player.cart) {
                player.fabric -= ((player.spice + player.ruby
                                  + player.fabric + player.jewel) - player.cart );
            }
            return true;
        }
        return false;
    }
};

class Jeweler:Tile {
    bool action( Player& player) {
        if (player.gold >= 2 && (player.spice + player.ruby
                                 + player.fabric + player.jewel) < player.cart) {
            player.gold -= 2;
            player.jewel += 3;
            if ((player.spice + player.ruby
                 + player.fabric + player.jewel) > player.cart) {
                player.jewel -= ((player.spice + player.ruby
                                  + player.fabric + player.jewel) - player.cart );
            }
            return true;
        }
        return false;
    }
};

class Cart_Manufacturer:Tile {
    bool action( Player& player) {
        if (player.gold >= 7) {
            player.gold -= 7;
            player.cart += 3;
            return true;
        }
        return false;
    }
};

class Small_Market:Tile {
    bool action( Player& player) {
        if (player.fabric > 0 && player.jewel > 0
            && player.spice > 0) {
            player.fabric --;
            player.jewel --;
            player.spice --;
            player.gold += 8;
            return true;
        }
        return false;
    }
};

class Spice_Market:Tile {
    bool action( Player& player) {
        if ( player.spice >= 3) {
            player.spice -= 3;
            player.gold += 6;
            return true;
        }
        return false;
    }
};

class Jewelry_Market:Tile {
    bool action( Player& player) {
        if ( player.jewel >= 3) {
            player.jewel -= 3;
            player.gold += 6;
            return true;
        }
        return false;
    }
};

class Fabric_Market:Tile {
    bool action( Player& player) {
        if ( player.fabric >= 3) {
            player.fabric -= 3;
            player.gold += 6;
            return true;
        }
        return false;
    }
};

class Black_Market:Tile {
    bool action( Player& player) {
        int v1 = rand() % 6;
        int v2 = rand() % 5;
        return false;
    }
};