//
//  Tile.cpp
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "Tile.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//methods


Tile* clone(const Tile& other) {
    Tile* x = new Tile(other);
    return x;
}

//derived classes

class Desert:public Tile {
    string name = "Desert";
};
class Restaurant:public Tile {
    string name = "Restaurant";
    bool action( Player& player) {
        player.food = 10;
        return true;
    }
};

class Spice_Merchant:public Tile {
    string name = "Spice Merchant";
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

class Fabric_Manufactures:public Tile {
    string name = "Fabric Manufactures";
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

class Jeweler:public Tile {
    string name = "Jeweler";
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

class Cart_Manufacturer:public Tile {
    string name = "Cart Manufacturer";
    bool action( Player& player) {
        if (player.gold >= 7) {
            player.gold -= 7;
            player.cart += 3;
            return true;
        }
        return false;
    }
};

class Small_Market:public Tile {
    string name = "Small Market";
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

class Spice_Market:public Tile {
    string name = "Spice Market";
    bool action( Player& player) {
        if ( player.spice >= 3) {
            player.spice -= 3;
            player.gold += 6;
            return true;
        }
        return false;
    }
};

class Jewelry_Market:public Tile {
    string name = "Jewelry Market";
    bool action( Player& player) {
        if ( player.jewel >= 3) {
            player.jewel -= 3;
            player.gold += 6;
            return true;
        }
        return false;
    }
};

class Fabric_Market:public Tile {
    string name = "Fabric Market";
    bool action( Player& player) {
        if ( player.fabric >= 3) {
            player.fabric -= 3;
            player.gold += 6;
            return true;
        }
        return false;
    }
};

class Black_Market:public Tile {
    string name = "Black Market";
    bool action( Player& player) {
        int numGoods = rand() % 5;
        
        for (int i = 0; i < numGoods; i++) {
            if ((player.fabric + player.jewel + player.spice) == player.cart) break;
            int whichGood = rand() % 3;
            switch (whichGood) {
                case 0:
                    player.fabric++;
                    break;
                case 1:
                    player.jewel++;
                    break;
                case 2:
                    player.spice++;
                    break;
            }
        }
        return false;
    }
};

class Casino:public Tile {
    string name = "Casino";
    bool action( Player& player) {
        if (player.gold > 0) {
            player.gold--;
            int result = rand() % 10;
            if (result < 3) player.gold += 2;
            else if (result > 2 && result < 5) player.gold += 3;
            else if (result == 5) player.gold += 10;
        }
        return true;
    }
};

class GemMerchant:public Tile {
    string name = "Gem Merchant";
    bool action (Player& player) {
        int cost = 0;
        switch (player.ruby) {
            case 1:
                cost = 12;
                break;
            case 2:
                cost = 13;
                break;
            case 3:
                cost = 14;
                break;
            case 4:
                cost = 15;
                break;
        }
        if (player.gold >= cost) {
            player.gold -= cost;
            player.ruby++;
        }
        return true;
    }
};

class Palace:public Tile {
    string name = "Palace";
    bool action (Player& player) {
        if (player.spice >= 5 && player.fabric >= 5 && player.jewel >= 5) {
            player.spice -= 5;
            player.fabric -= 5;
            player.jewel -= 5;
            player.ruby++;
        }
        return true;
    }
};
