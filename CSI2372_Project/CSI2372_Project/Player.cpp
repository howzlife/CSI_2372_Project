//
//  Player.cpp
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "Player.h"

Player::Player(){
    gold = 5;
    ruby = 0;
    spice = 1;
    fabric = 1;
    jewel = 1;
    food = 10;
    cart = 9;
}

bool Player::canAct() const {
    return (food > 0);
}

void Player::eat() {
    if (food > 0) food -= 1;
}

bool Player::pay( Player& player) {
    if (gold > 0) {
        gold -= 1;
        player.gold += 1;
        return true;
    }
    else return false;
}

