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
#include <vector>
using namespace std;

template<typename T, typename J>
class GameBoard {
    int rows;
    int columns;
    vector<T> tiles; //vector of tiles should be 2D : 1st D = rows, 2nd D = columns
    vector<J> players; //players on each tile, will be a 3D array, i.e. rows, columns, players.
    int N; //number of players
    
public:
    void add(const T& tile, int row, int col);
    const T& getTile(int row, int col) const;
    void getCoordinate(const T &tile, int *row, int *col) const;
    void setPlayer(J player);
    J getPlayer(const std::string& playerName);
    const T& getTile(const std::string& playerName) const;
     std::vector<J> getPlayers(const T& tile) const;
     const T& move(Enum Move move, const std::string& playerName );
    
    
};


#endif /* defined(__C___Project__Board__) */
