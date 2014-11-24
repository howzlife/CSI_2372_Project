//
//  Board.h
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __C___Project__Board__
#define __C___Project__Board__

#include <stdio.h>
#include "Tile.h"
#include "Player.h"
#include <vector>
using namespace std;

enum Move {up = 0, down = 1, left = 2, right = 3, stay = 4};

template<typename T, typename J>
class GameBoard {
    int rows;
    int columns;
    vector<vector<T>> tiles; //vector of tiles should be 2D : 1st D = rows, 2nd D = columns
    vector<vector<vector<J>>> players; //players on each tile, will be a 3D array, i.e. rows, columns, players.
    int N; //number of players
    
public:
    GameBoard();
    void add(const T& tile, int row, int col);
    const T& getTile(int row, int col) const;
    void getCoordinate(const T &tile, int *row, int *col) const;
    void setPlayer(J player);
    J getPlayer(const std::string& playerName);
    const T& getTile(const std::string& playerName) const;
     std::vector<J> getPlayers(const T& tile) const;
     const T& move(enum Move move, const std::string& playerName );
    
};


#endif /* defined(__C___Project__Board__) */
