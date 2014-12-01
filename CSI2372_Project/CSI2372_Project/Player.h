//
//  Player.h -> DONE
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __C___Project__Player__
#define __C___Project__Player__

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Player {
public:
    int gold;
    int ruby;
    int spice;
    int fabric;
    int jewel;
    int cart;
    int food;
    string name;
    
    
    Player(string);
    bool canAct() const;
    bool pay(Player& player);
    void eat();
    int getSumGoods() { return ruby + spice + fabric + jewel; };
    int getCartCapacity() { return (cart - (this->getSumGoods()));};
    friend ostream& operator<<(ostream& outstream, Player &player);
};

#endif /* defined(__C___Project__Player__) */
