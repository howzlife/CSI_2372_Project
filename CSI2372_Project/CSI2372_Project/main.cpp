//
//  main.cpp
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//
#include "GameBoard.h"
#include "TileFactory.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
using namespace std;


template <class T,class J, int N>
bool turn(GameBoard<T, J, N> &board, const string &playerName) {
    try {
        
        Tile t;
        int m = 0;
        cin.exceptions(istream::failbit);
        cin >> m;
        if (cin.fail())
            throw invalid_argument("Error: This value must be an Integer!");
        //Find the player matching the required name
        Player p = board.getPlayer(playerName);
        //Get the new tile
        Tile* tile = board.move(static_cast<Move>(m), playerName);
        //Pokemon-style discovery of new tile
        cout << "Congratulations! you've found a "<< (*tile) << "!" << endl;
        //Print out possible actions based on tile
        cout << (*tile).toString() << endl;
        
        //If landed on "Desert" or Restaurant", end the turn
        if ((*tile).type() == "Desert" || (*tile).type() == "Restaurant") {
            (*tile).action(p);
            return true;
        }
  
        //If player can act, act!
        if (p.canAct()) {
            cout << "To Act, enter 1. To not act, enter 0." << endl;
            bool decision;
            cin >> decision;
            if (decision) {
                
                //Get other players on the same tile
                vector<Player> otherPlayers = board.getPlayers(*tile);
                if (p.gold >= otherPlayers.size()) {
                    
                    //Ingest and Digest.
                    p.eat();
                    //Pay the Piper! By Piper I mean other players.
                    for (auto otherPlayer : otherPlayers) {
                        p.pay(otherPlayer);
                        board.setPlayer(otherPlayer);
                    }
                    
                    //Either do action or throw exception.
                    if ( !(*tile).action(p) )
                        throw invalid_argument("Unfortunately, you don't have enough to trade. You're an IstanBum from IstanBul!!");
                    board.setPlayer(p);
                } else {
                    cout << "You don't have enough gold to pay the other players on the tile! You're an IstanBum from IstanBul!!";
                }
            }
        }
        return true;
        //Turn is now over
    } catch (invalid_argument e) {
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } catch (out_of_range e) {
        cerr << e.what() << "You can't move this way, please try another direction" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } catch (istream::failure e) {
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
}


//Main Method! #LETSGO
int main(int argc, char const *argv[]) {
    cout << "Welcome to the Istanbul Game!!!" << endl;

    srand(unsigned(time(0)));
    int numPlayers = 0;
    const int n = 10; //board dimension
    bool paused = true;
    bool load = false;
    bool is_saved = false;
    ifstream test("Istanbul.txt");
    if (test.good()) is_saved = !is_saved;
    
    // get player names
    vector<string> playerNames;
    GameBoard<Tile, Player, n> board;
    if (is_saved) {
        while (paused) {
            try {
                cout << "Type 0 for New Game, or type 1 for Load Game" << endl;
                cin.exceptions(istream::failbit);
                cin >> load;
                if (cin.fail()) throw invalid_argument("Error please input 0 or 1.");
                break;
            } catch (invalid_argument e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    } else
    {
        cout << "There are no games to load! Idiot...." << endl;
    }
    if (load) {
        ifstream load("Istanbul.txt");
        load >> board;
        load.close();
        for (auto p : board.players)
            playerNames.push_back(p.name);
        cout << "Resuming game!" << endl;
    }
    
    
    
    if (!load) {
        while (paused) {
            try {
                cout << "How many friends do you have? How many of them are playing today (plus yourself)?:" << endl;
                cin.exceptions(istream::failbit);
                cin >> numPlayers;
                if (cin.fail()) {
                    throw invalid_argument("Nope. Try Again.");
                } else if (numPlayers < 2) {
                    throw invalid_argument("You wanna play alone? Wow, you're cool..... try again");
                } else break;
            } catch (invalid_argument e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        do {
            cout << "Please enter the player's name:" << endl;
            try {
                string name;
                cin >> name;
                if (name.empty() || cin.fail()) {
                    throw invalid_argument("You need to enter a name!");
                } else if (name.length() > 0) {
                    playerNames.push_back(name);
                }
            } catch (invalid_argument e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            } catch (...) {
                cerr << "Error! Error!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (playerNames.size() < numPlayers);
        
        board = *new GameBoard<Tile, Player, 10>(playerNames);
        
        
        TileFactory* tileFactory = TileFactory::get(n*n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                board.add(tileFactory->next(), i, j);
        
        // Exit if no starting tile is found
        int row, col;
        board.getCoordinate(Restaurant(), &row, &col);
        if ((board.getTile(row, col))->type() != "Restaurant") {
            cerr << "Error! No starting tiles are available!" << endl;
            exit(1);
        }
        
        // Set players on starting tile #LETSGO
        board.setPlayers(row, col);
    }
    
    // ACTUALLY START THE GAME
    if (paused) paused = !paused;
    while (!paused) {
        cout << "Wanna keep playing? 0 = yes, 10 = Save and Exit" << endl;
        while(true) {
            try {
                cin >> paused;
                if (cin.fail()) throw invalid_argument("Yeah, the options are 1 or 0, idiot.");
                if (paused) {
                    ofstream save("Istanbul.txt");
                    save << board;
                    save.close();
                    cout << "Game Successfully Saved! #MURICA" << endl;
                    exit(0);
                } else {
                    break;
                }
            } catch (invalid_argument e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            } catch (...) {
                cerr << "Uh Oh, we made a boo-boo!!!" << endl;
                exit(1);
            }
        }
        for ( auto playerName : playerNames ) {
            Player player = board.getPlayer(playerName);
            cout << player;
            do {
                
                cout << "Enter your move (0 = UP, 1 = DOWN, 2 = LEFT, 3 = RIGHT): ";
                
            } while (!turn<Tile, Player, n>(board,playerName));
            
            //END CONDITION
            if (player.ruby >= 5) {
                cout << playerName << " has won! ALL HAIL " << playerName << "!!! I, for one, accept him as our new overlord." << endl;
                paused = !paused;
            }
        }
        
    }
    
    
    cout << "Ciao!";
    return 0;
}