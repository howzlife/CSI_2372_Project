//
//  Tile.h -> DONE
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __C___Project__Tile__
#define __C___Project__Tile__
#include <iostream>
#include <string>
#include "Player.h"
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>

class Tile {
public:
    string name;
    bool operator==(const Tile& t){ return type() == t.type();};
    virtual bool action(Player& player ) {return true;}; //i.e. nothing happens. wop wop. 
    virtual Tile* clone();
    virtual string type() const{return "Desert";};
    virtual string toString() const;
    friend ostream& operator<<(ostream& outstream, Tile& t) {outstream << t.type(); return outstream;};
};

class Restaurant:public Tile {
    string name = "Restaurant";
    bool action(Player& player);
    Tile* clone();
    string type() const { return name;};
    string toString() const;
};


class Spice_Merchant : public Tile
{
public:
    bool action(Player& player);
    string name = "Spice Merchant";
    Tile* clone();
    string type() const{return name;};
    string toString() const;
};

class Fabric_Manufactures : public Tile
{
public:
    string name = "Fabric Manufactures";
    bool action(Player& player);
    Tile* clone();
    string type() const{ return name;};
    string toString() const;
};

class Jeweler : public Tile
{
public:
    string name = "Jeweler";
    bool action(Player& player);
    Tile* clone();
    string type() const{return name;};
    string toString() const;
};

class Cart_Manufacturer : public Tile
{
public:
    string name = "Cart Manufacturer";
    bool action(Player& player);
    Tile* clone();
    string type() const {return name;};
    string toString() const;
};

class Small_Market : public Tile
{
public:
    string name = "Small Market";
    bool action(Player& player);
    Tile* clone();
    string type() const{return name;};
    string toString() const;
};

class Spice_Market : public Tile
{
public:
    string name = "Spice Market";
    bool action(Player& player);
    Tile* clone();
    string type() const{return name;};
    string toString() const;
};

class Jewelry_Market : public Tile
{
public:
    string name = "Jewelry Market";
    bool action(Player& player);
    Tile* clone();
    string type() const{return name;};
    string toString() const;
};

class Fabric_Market : public Tile
{
public:
    string name = "Fabric Market";
    bool action(Player& player);
    Tile* clone();
    string type() const{return name;};
    string toString() const;
};

class Black_Market : public Tile
{
public:
    string name = "Black Market";
    bool action(Player& player);
    Tile* clone();
    string type() const{return name;};
    string toString() const;
};

class Casino : public Tile
{
public:
    string name = "CASINO!!!!!";
    bool action(Player& player);
    Tile* clone();
    string type() const{return name;};
    string toString() const;
};

class Gem_Merchant : public Tile
{
    int price = 12;
public:
    string name = "Gem Merchant";
    bool action(Player& player);
    Tile* clone();
    string type() const{return name;};
    string toString() const;
};

class Palace : public Tile
{
public:
    string name = "Palace";
    bool action(Player& player);
    Tile* clone();
    string type() const{return name;};
    string toString() const;
};


#endif /* defined(__C___Project__Tile__) */
