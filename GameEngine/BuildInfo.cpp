//
// Created by kamil on 28.12.2021.
//

#include "GameEngine.h"

void GameEngine::buildInfo() {
    std::cout << "About which building do you want build info?" << std::endl;
    std::cout << "[1] GoldMine, [2] GoldStorage, [3] StoneMine, [4] StoneStorage, [5] LumberMill, [6] WoodStorage, [0] Go back." << std::endl;
    int info;
    std::cin >> info;
    switch (info) {
        case 1:
            std::cout << "To build this building you want 50 gold, 30 stone, 20 wood." << std::endl;
            break;
        case 2:
            std::cout << "To build this building you want 40 gold, 50 stone, 40 wood." << std::endl;
            break;
        case 3:
            std::cout << "To build this building you want 30 gold, 50 stone, 40 wood." << std::endl;
            break;
        case 4:
            std::cout << "To build this building you want 40 gold, 20 stone, 40 wood." << std::endl;
            break;
        case 5:
            std::cout << "To build this building you want 40 gold, 40 stone, 30 wood." << std::endl;
            break;
        case 6:
            std::cout << "To build this building you want 30 gold, 30 stone, 30 wood." << std::endl;
            break;
        case 0:
            return;
        default:
            std::cerr << "Unknown building" << std::endl;
    }
}