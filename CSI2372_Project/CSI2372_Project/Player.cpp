//
//  Player.cpp -> DONE
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "Player.h"
#include <stdio.h>
#include <iostream>

Player::Player(string _playerName) : gold(5), ruby(0), spice(1), fabric(1), jewel(1),
        cart(9), food(10), name(_playerName){}

bool Player::canAct() const {
    return (food > 0);
}

void Player::eat() {
    if (food > 0) --food;
}

bool Player::pay( Player& player) {
    if (gold > 0) {
        gold--;
        player.gold++;
        return true;
    }
    else return false;
}

//prints players stats

ostream& operator<<(ostream& outstream, Player& player) {
    outstream << "It is " << player.name
    << "'s turn to move. Player's stats are: Gold amount: " << player.gold << endl;
    outstream << "  Ruby amount: " << player.ruby << endl;
    outstream << "  Spice amount: " << player.spice << endl;
    outstream << "  Fabric amount: " << player.fabric << endl;
    outstream << "  Jewel amount: " << player.jewel << endl;
    outstream << "  Food amount: "   << player.food << endl;
    outstream << " Cart amount: "  << player.getSumGoods() << " out of " << player.cart << " is used" << endl;
    return outstream;
}


