//
//  GameBoard.h ->DONE
//  C++ Project
//
//  Created by Nicolas Dubus and Hugh Nguyen on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __C___Project__Board__
#define __C___Project__Board__


#include "Tile.h"
#include "TileFactory.h"
#include "Player.h"
#include <stdio.h>
#include <deque>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

enum class Move {UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3};

template<class T, class J, int N>
class GameBoard {
public:
    //player location on board
    int** pLoc;
    //array of tiles should be 2D : 1st D = rows, 2nd D = columns
    Tile* tiles[N][N];
    //players on each tile, will be a 3D array, i.e. rows, columns, players.
    vector<J> players;
    //default constructor
    GameBoard() = default;
    //destructor
    ~GameBoard(){};
    //constructor where players are passed
    GameBoard(vector<string> _players);
    //add tile to game
    void add(T* tile, int row, int col);
    //get tile where player lands
    T* getTile(int row, int col);
    //get coordinates of a certain tile
    void getCoordinate(const T& tile, int *row, int *col) const;
    //set player on a tile
    void setPlayer(J player);
    //get player from a certain tile, using his name
    J getPlayer(const string& playerName);
    //get Tile based on player name
    const T& getTile(const string& playerName) const;
    //get tile type if you know where it is
    const T& getTile(const string& playerName, int *row,int *col) const;
    //get all players
    vector<J> getPlayers(const T& tile) const;
    //move up, down, left, right
    T* move(Move move, const string& playerName );
    //set players on tile
    void setPlayers(int row, int col);
    //print out game board
    void print();
    //add player to game board
    void addPlayer(J player, int* i, int* j);
    //Pause game
    friend ostream& operator<<(ostream& outstream, const GameBoard &board);
    //Unpause game
    friend istream& operator>>(istream& instream, GameBoard& board);
};

//This function adds all players when the game is started.

template<class T, class J, int N>
void GameBoard<T, J, N>::setPlayers(int r, int c) {
    for (int i = 0; i < players.size(); ++i) {
        pLoc[i][0] = r;
        pLoc[i][1] = c;
    }
}

//constructor to initialize players

template<class T, class J, int N>
GameBoard<T, J, N>::GameBoard(vector<string> _players) {
    pLoc = new int*[_players.size()];
    for (int i = 0; i < _players.size(); ++i) {
        pLoc[i] = new int[2];
        Player player(_players[i]);
        players.push_back(player);
    }
}




template<class T, class J, int N>
T* GameBoard<T, J, N>::move(Move move, const std::string& playerName ){
    int location = 0;
    for (int i = 0; i < players.size(); ++i) {
        if (players[i].name == playerName){
            location = i;
        }
    }
    int playerRow = pLoc[location][0];;
    int playerCol = pLoc[location][1];
    
    switch (move) {
        case Move::UP:
            if (playerRow > 0) {
                pLoc[location][0]--;
            } else throw std::out_of_range("Can't move there");
            break;
        case Move::DOWN:
            if (playerRow < (N - 1)) {
                pLoc[location][0]++;
            } else throw std::out_of_range("Can't move there");
            break;
        case Move::LEFT:
            if (playerCol > 0) {
                pLoc[location][1]--;
            } else throw std::out_of_range("Can't move there");
            break;
        case Move::RIGHT:
            if (playerCol < (N - 1)) {
                pLoc[location][1]++;
            } else throw std::out_of_range("Can't move there");
            break;
        default:
            throw istream::failure("This is not a valid move, please try again, idiot.");
            break;
    }
    return tiles[pLoc[location][0]][pLoc[location][1]];
}


//Pause game, write to file
ostream& operator<<(ostream& outstream, const GameBoard<Tile, Player, 10> &board) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            outstream << (* board.tiles[i][j]).type() << endl; //save all tile types and their locations
    
    outstream << board.players.size() << endl;
    int i = 0;
    //iterate over all players
    for (auto player : board.players){
        //save player name
        outstream << player.name << endl;
         //save players row
        outstream << board.pLoc[i][0] << endl;
        //save players column
        outstream << board.pLoc[i][1] << endl;
        //save player attributes
        outstream << player.gold << endl;
        outstream << player.ruby << endl;
        outstream << player.spice << endl;
        outstream << player.fabric << endl;
        outstream << player.jewel << endl;
        outstream << player.cart << endl;
        outstream << player.food << endl;
        ++i;
    }
    return outstream;
}

//Unpause game
istream& operator>>(istream &instream, GameBoard<Tile, Player, 10> &board) {
    board.players = {}; //declare new array, will add players in here.
    // Iterate over all saved tiles, read in each tile as its type
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            string tile;
            getline(instream, tile);
            if (tile == "Desert")
                board.tiles[i][j] = new Tile;
            else if (tile == "Restaurant")
                board.tiles[i][j] = new Restaurant;
            else if (tile == "Spice Merchant")
                board.tiles[i][j] = new Spice_Merchant;
            else if (tile == "Fabric Manufactures")
                board.tiles[i][j] = new Fabric_Manufactures;
            else if (tile == "Jeweler")
                board.tiles[i][j] = new Jeweler;
            else if (tile == "Cart Manufacturer")
                board.tiles[i][j] = new Cart_Manufacturer;
            else if (tile == "Small Market")
                board.tiles[i][j] = new Small_Market;
            else if (tile == "Spice Market")
                board.tiles[i][j] = new Spice_Market;
            else if (tile == "Jewelry Market")
                board.tiles[i][j] = new Jewelry_Market;
            else if (tile == "Black Market")
                board.tiles[i][j] = new Black_Market;
            else if (tile == "Casino")
                board.tiles[i][j] = new Casino;
            else if (tile == "Gem Merchant")
                board.tiles[i][j] = new Gem_Merchant;
            else if (tile == "Palace")
                board.tiles[i][j] = new Palace;
        }
    }
    // Read in all players, and their positions.
    string row;
    getline(instream, row);  //read each row
    int numPlayers = atoi(row.c_str()); //atoi used to read string as integer
    board.pLoc = new int*[numPlayers];
    for (int i = 0; i < numPlayers; ++i) {
        getline(instream, row);
        Player player(row);
        board.pLoc[i] = new int[2];
        getline(instream, row);
        board.pLoc[i][0] = atoi(row.c_str());
        getline(instream, row);
        board.pLoc[i][1] = atoi(row.c_str());
        getline(instream, row);
        player.gold = atoi(row.c_str());
        getline(instream, row);
        player.ruby = atoi(row.c_str());
        getline(instream, row);
        player.spice = atoi(row.c_str());
        getline(instream, row);
        player.fabric = atoi(row.c_str());
        getline(instream, row);
        player.jewel = atoi(row.c_str());
        getline(instream, row);
        player.cart = atoi(row.c_str());
        getline(instream, row);
        player.food = atoi(row.c_str());
        board.players.push_back(player);
    }
    return instream;
}

template<class T, class J, int N>
void GameBoard<T, J, N>::addPlayer(J player, int* row, int* col) {
    pLoc[players.size()] = new int[2];
    pLoc[players.size()][0] = *row;
    pLoc[players.size()][1] = *col;
    players.push_back(player);
}



//add tile pointer to tile array
template <class T, class J, int N>
void GameBoard<T, J, N>::add(T* t, int r, int c) {
    tiles[r][c] = t;
}

//get tile with coordinates
template <class T, class J, int N>
T* GameBoard<T, J, N>::getTile(int row, int col) {
    return tiles[row][col];
}


//tells us where a certain type of tile is on the gameboard

template<class T, class J, int N>
void GameBoard<T, J, N>::getCoordinate(const T& tile, int *row, int *col) const {

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if ((*tiles[i][j] == tile)) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

//will be used to set a player on certain tiles

template<class T, class J, int N>
void GameBoard<T, J, N>::setPlayer(J p) {
    for (int i = 0; i < players.size(); ++i) {
        if (players[i].name == p.name) players[i] = p; //if player is at this location, set player.
    }
}

//getter method for players
template<class T, class J, int N>
J GameBoard<T, J, N>::getPlayer(const string& playerName) {
    for (int i = 0; i < players.size(); ++i) {
            if (players[i].name == playerName) {
                return players[i];
            }
    }
    throw std::out_of_range("Player not found");
    exit(1);
}

//getter method, for the tile that the player is occupying.

template<class T, class J, int N>
const T& GameBoard<T, J, N>::getTile(const string& playerName, int *row, int *col) const{
    int count = 0;
    for (int i = 0; i < players.size(); ++i) {
        if (players[i].name == playerName) {
            *row = pLoc[i][0];
            *col = pLoc[i][1];
            count = i;
            break;
        }
    }
    return *tiles[pLoc[count][0]][pLoc[count][1]];
}

//get all players on a tile

template<class T, class J, int N>
vector<J> GameBoard<T, J, N>::getPlayers(const T& tile) const {
    int numRow, numCol;
    getCoordinate(tile, &numRow, &numCol);
    vector<J> players;
    for (int i = 0; i < players.size(); ++i) {
        if (pLoc[i][0] == numRow && pLoc[i][1] == numCol) players.push_back(players[i]);
    }
    return players;
}


//for debugging: print all gameboard tiles out
template <class T, class J, int N>
void GameBoard<T, J, N>::print() {
    for (int i = 0; i < N; i++) {
        cout << i << "\t";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << i << "\t";
        for (int j = 0; j < N; j++) {
            cout << (*tiles[i][j].name())[0] << "\t";
        }
        cout << endl;
    }
    cout<< endl;
}

#endif /* defined(__C___Project__Board__) */
