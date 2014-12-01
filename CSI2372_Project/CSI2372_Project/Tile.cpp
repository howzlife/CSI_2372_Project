//
//  Tile.cpp -> DONE
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

Tile* Tile::clone() {
    return new Tile(*this);
}

//default toString() call
string Tile::toString() const {
    return "You're in the Desert.";
}

//derived classes

class Desert:public Tile {
    string name = "Desert";
};

bool Restaurant::action( Player& player) {
    player.food = 10;
    cout << "Food is now at 10! Let's Fighting Love!" << endl;
    return true;
}

string Restaurant::toString() const {
    return "Food is now at 10";
}

Tile* Restaurant::clone() {
    return new Restaurant(*this);
}


bool Spice_Merchant::action( Player& player) {
        if (player.gold >= 2 && (player.getCartCapacity() > 0)) {
            player.gold -= 2;
            if (player.getCartCapacity() >= 3){
                player.spice += 3;
                cout << "Spice += 3! Let's Fighting Love!" << endl;
            }
            else if ((player.getCartCapacity()) > 0) {
                cout << "Spice += " << player.getCartCapacity() << "! Let's Fighting Love!" << endl;
                player.spice += player.getCartCapacity();
            }
            return true;
        }
        return false;
};

Tile* Spice_Merchant::clone() {
    return new Spice_Merchant(*this);
}

string Spice_Merchant::toString() const {
    return "2 Gold gets you 3 or less spice, depending on available capacity. ";
}

bool Fabric_Manufactures::action( Player& player) {
    if (player.gold >= 2 && (player.getCartCapacity() > 0)) {
        player.gold -= 2;
        if (player.getCartCapacity() >= 3) {
            player.fabric += 3;
            cout << "Fabric += 3! Let's Fighting Love!" << endl;
        }
        else if ((player.getCartCapacity()) > 0) {
            cout << "Fabric += " << player.getCartCapacity() << "! Let's Fighting Love!" << endl;
            player.fabric += player.getCartCapacity();
        }
        return true;
    }
    return false;
};


string Fabric_Manufactures::toString() const {
    return "2 Gold gets you 3 or less Fabric, depending on available capacity.";
}

Tile* Fabric_Manufactures::clone() {
    return new Fabric_Manufactures(*this);
}


bool Jeweler::action( Player& player) {
    if (player.gold >= 2 && (player.getCartCapacity() > 0)) {
        player.gold -= 2;
        if (player.getCartCapacity() >= 3) {
            player.jewel += 3;
            cout << "Jewels += 3! Let's Fighting Love!" << endl;
        }
        else if ((player.getCartCapacity()) > 0) {
            cout << "Jewels += " << player.getCartCapacity() << "! Let's Fighting Love!" << endl;
            player.jewel += player.getCartCapacity();
        }
        return true;
    }
    return false;
};

string Jeweler::toString() const {
    return "2 Gold gets you 3 or less Jewels, depending on available capacity.";
}

Tile* Jeweler::clone() {
    return new Jeweler(*this);
}


bool Cart_Manufacturer::action( Player& player) {
        if (player.gold >= 7) {
            player.gold -= 7;
            player.cart += 3;
            cout << "Cart Capacity Increased To " << player.cart << "! Let's Fighting Love!" << endl;
            return true;
        }
        return false;
};

string Cart_Manufacturer::toString() const {
    return "7 Gold get you +3 capacity in your cart. DOOOOO IT!";
}

Tile* Cart_Manufacturer::clone() {
    return new Cart_Manufacturer(*this);
}

bool Small_Market::action( Player& player) {
        if (player.fabric > 0 && player.jewel > 0
            && player.spice > 0) {
            player.fabric --;
            player.jewel --;
            player.spice --;
            player.gold += 8;
            cout << "Gold! Gold! Gold! Gold! Gold! Gold! Gold! Gold! (+8 Gold. Sweeeeet)" << endl;
            return true;
        }
        return false;
};


string Small_Market::toString() const {
    return "You can sell 1 Fabric, 1 Jewel and 1 Spice for 8 Gold. Deal?!";
}

Tile* Small_Market::clone() {
    return new Small_Market(*this);
}

bool Spice_Market::action( Player& player) {
        if ( player.spice >= 3) {
            player.spice -= 3;
            player.gold += 6;
            cout << "Gold! Gold! Gold! Gold! Gold! Gold! (+6 Gold. Sweeet)" << endl;
            return true;
        }
        return false;
};

string Spice_Market::toString() const {
    return "You can sell 3 Spices for 6 Gold. Deal?";
}

Tile* Spice_Market::clone() {
    return new Spice_Market(*this);
}

bool Jewelry_Market::action( Player& player) {
        if ( player.jewel >= 3) {
            player.jewel -= 3;
            player.gold += 6;
            cout << "Gold! Gold! Gold! Gold! Gold! Gold! (+6 Gold. Sweeet)" << endl;
            return true;
        }
        return false;
};

string Jewelry_Market::toString() const {
    return "You can sell 3 Jewels for 6 Gold. Deal?";
}

Tile* Jewelry_Market::clone() {
    return new Jewelry_Market(*this);
}

bool Fabric_Market::action( Player& player) {
        if ( player.fabric >= 3) {
            player.fabric -= 3;
            cout << "Gold! Gold! Gold! Gold! Gold! Gold! (+6 Gold. Sweeet)" << endl;
            player.gold += 6;
            return true;
        }
        return false;
};

string Fabric_Market::toString() const {
    return "You can sell 3 rolls of Fabric for 6 Gold. Deal?";
}

Tile* Fabric_Market::clone() {
    return new Fabric_Market(*this);
}

bool Black_Market::action( Player& player) {
        int numGoods = rand() % 5;
        
        for (int i = 0; i < numGoods; i++) {
            if (player.getCartCapacity() == 0) break;
            int whichGood = rand() % 3;
            switch (whichGood) {
                case 0:
                    player.fabric++;
                    cout << "Fabric += 1" << endl;
                    break;
                case 1:
                    player.jewel++;
                    cout << "Jewel += 1" << endl;
                    break;
                case 2:
                    player.spice++;
                    cout << "Spice += 1" << endl;
                    break;
            }
        }
        return false;
};

string Black_Market::toString() const {
    return "For 1 Gold, you will get between 1 and 5 goods at random. Thoughts? ";
}

Tile* Black_Market::clone() {
    return new Black_Market(*this);
}


bool Casino::action( Player& player) {
        if (player.gold > 0) {
            player.gold--;
            int result = rand() % 10;
            if (result < 3) {
            player.gold += 2;
            cout << "Gold! Gold! (+2 Gold. Sweeet)" << endl;
            }
            else if (result > 2 && result < 5) {
            player.gold += 3;
            cout << "Gold! Gold! Gold!(+3 Gold. Sweeet)" << endl;
            }
            else if (result == 5){
            player.gold += 10;
            cout << "WINNER WINNER CHICKEN DINNER!!! +10 Gold!!" << endl;
            }
        }
        return true;
};


string Casino::toString() const {
    return "For 1 Gold, you can win 0, 2, 3, or 10 Gold. DOOOO IT!!!";
}

Tile* Casino::clone() {
    return new Casino(*this);
}

bool Gem_Merchant::action (Player& player) {
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
            cout << "Ruby += 1" << endl;
        }
        return true;
};

string Gem_Merchant::toString() const {
    return "For 12 Gold, You can get a Ruby! Note: Every time you buy a ruby, the price goes up. Supply and demand baby!";
}

Tile* Gem_Merchant::clone() {
    return new Gem_Merchant(*this);
}

bool Palace::action (Player& player) {
        if (player.spice >= 5 && player.fabric >= 5 && player.jewel >= 5) {
            player.spice -= 5;
            player.fabric -= 5;
            player.jewel -= 5;
            player.ruby++;
            cout << "Spice -= 5, Fabric -= 5, Jewel -= 5, and RUBY ++!!!" << endl;
        }
        return true;
};

string Palace::toString() const {
    return "I will sell you a ruby for 5 Spices, 5 Fabrics and 5 Jewels. Deal? DEEEEAAAALLL????";
}

Tile* Palace::clone() {
    return new Palace(*this);
}
