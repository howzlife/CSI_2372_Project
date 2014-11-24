//
//  main.cpp
//  C++ Project
//
//  Created by Nicolas Dubus on 2014-11-11.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {

    bool paused = false;
    while (!paused) {
        int numPlayers;
        std::cout << "How many players today, bitch?" << std::endl;
        std::cin >> numPlayers;
        std::vector<string> names;
        for (int i = 0; i < numPlayers; ++i) {
            string name;
            std::cout << "What is player #" << i + 1 << "'s name, bitch?" << std::endl;
            std::cin >> name;
            names.push_back(name);
        }
        
        
        
        
    }
    
    return 0;
}
