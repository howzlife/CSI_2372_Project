//
//  Board.cpp
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "GameBoard.h"

template<> void GameBoard<Tile, Player>::add(const Tile& tile, int row, int col) {
    tiles[row][col] = tile;
}

template<> const Tile& GameBoard<Tile, Player>::getTile(int row, int col) const {
    return tiles[row][col];
}

template<> void GameBoard<Tile, Player>::getCoordinate(const Tile &tile, int *row, int *col) const {
    int rowNum = 0;
    for (std::vector<vector<Tile>>::const_iterator it = tiles.begin(); it != tiles.end(); ++it) {
        int colNum = 0;
        for (std::vector<Tile>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            if (*it2 == tile) {
                *row = rowNum;
                *col = colNum;
                break;
            }
            colNum++;
        }
        rowNum++;
    }
}

template<> void GameBoard<Tile, Player>::setPlayer(Player player) {
    //dafuq do I do here?
}

template<> Player GameBoard<Tile, Player>::getPlayer(const std::string& playerName) {
    for (std::vector<vector<vector<Player>>>::iterator it = players.begin(); it != players.end(); ++it) {
        for (std::vector<vector<Player>>::iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            for (std::vector<Player>::iterator it3 = it2->begin(); it3 != it2->end(); ++it3) {
                if (it3->name == playerName) return *it3;
            }
        }
    }
    throw std::out_of_range("Player not found");
}

template<> const Tile& GameBoard<Tile, Player>::getTile(const std::string& playerName) const{
    int rowNum = 0;
    for (std::vector<vector<vector<Player>>>::const_iterator it = players.begin(); it != players.end(); ++it) {
        int colNum = 0;
        for (std::vector<vector<Player>>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            for (std::vector<Player>::const_iterator it3 = it2->begin(); it3 != it2->end(); ++it3) {
                if (it3->name == playerName) return tiles[rowNum][colNum];
            }
            colNum++;
        }
        rowNum++;
    }
    throw std::out_of_range("Tile not found");
}

template<> std::vector<Player> GameBoard<Tile, Player>::getPlayers(const Tile& tile) const {
    int numCol = 0;
    for (std::vector<vector<Tile>>::const_iterator it = tiles.begin(); it != tiles.end(); ++it) {
        int numRow = 0;
        for (std::vector<Tile>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            if (*it2 == tile) {
                return players[numCol][numRow];
                break;
            }
                numRow++;
        }
        numCol++;
    }
    throw std::out_of_range("Tile not found");
}

template<> const Tile& GameBoard<Tile, Player>::move(enum Move move, const std::string& playerName ){
    int rowNum = 0;
    int playerRow = 0;
    int playerCol = 0;
    const Player * daPlayer;
    for (std::vector<vector<vector<Player>>>::const_iterator it = players.begin(); it != players.end(); ++it) {
        int colNum = 0;
        for (std::vector<vector<Player>>::const_iterator it2 = it->begin(); it2 != it->end(); ++it) {
            for (std::vector<Player>::const_iterator it3 = it2->begin(); it3 != it2->end(); ++it3) {
                if (it3->name == playerName) {
                    daPlayer = &*it3;
                    int playerRow = rowNum;
                    int playerCol = colNum;
                    
                    int x = move;
                    switch (x) {
                        case 0:
                            if (playerRow != 0) {
                                players[playerRow - 1][playerCol].push_back(*new Player(*daPlayer));
                                players[playerRow][playerCol].erase(it3);
                                return tiles[playerRow - 1][playerCol];
                            } else throw std::out_of_range("Can't move there");
                            break;
                        case 1:
                            if (players.begin() + playerCol != players.end() - 1) {
                                players[playerRow + 1][playerCol].push_back(*new Player(*daPlayer));
                                players[playerRow][playerCol].erase(it3);
                                return tiles[playerRow + 1][playerCol];
                            } else throw std::out_of_range("Can't move there");
                            break;
                        case 2:
                            if (playerCol != 0) {
                                players[playerRow][playerCol - 1].push_back(*new Player(*daPlayer));
                                players[playerRow][playerCol].erase(it3);
                                return tiles[playerRow][playerCol - 1];
                            } else throw std::out_of_range("Can't move there");
                            break;
                        case 3:
                            if (players[0].begin() + playerCol != players[0].end() - 1) {
                                players[playerRow][playerCol + 1].push_back(*new Player(*daPlayer));
                                players[playerRow][playerCol].erase(it3);
                                return tiles[playerRow][playerCol + 1];
                            }
                            break;
                        case 4:
                            return tiles[playerRow][playerCol];
                            break;
                    }

                    }
                }
                colNum++;
            }
        rowNum++;
        }
    throw std::out_of_range("Can't move there");
    }







