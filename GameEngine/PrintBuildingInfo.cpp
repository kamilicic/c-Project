//
// Created by kamil on 28.12.2021.
//

#include "GameEngine.h"

void GameEngine::printBuildingInfo() {
    std::cout << "From which building do you want info?" << std::endl;
    std::cout << "[1] TownHall, [2] GoldMine, [3] GoldStorage, [4] StoneMine, [5] StoneStorage, [6] LumberMill, [7] WoodStorage, [0] Go back." << std::endl;
    int building;
    std::cin >> building;
    switch (building) {
        case 1:
            TownHall->printTownHallInfo();
            std::cout << std::endl;
            break;
        case 2:
            if (GoldMine != nullptr) {
                GoldMine->printInfo();
                std::cout << std::endl;
            } else {
                std::cerr << "Not existing building!" << std::endl;
            }
            break;
        case 3:
            if (GoldStorage != nullptr) {
                GoldStorage->printGoldInfo();
                std::cout << std::endl;
            } else {
                std::cerr << "Not existing building!" << std::endl;
            }
            break;
        case 4:
            if (StoneMine != nullptr) {
                StoneMine->printInfo();
                std::cout << std::endl;
            } else {
                std::cerr << "Not existing building!" << std::endl;
            }
            break;
        case 5:
            if (StoneStorage != nullptr) {
                StoneStorage->printStoneInfo();
                std::cout << std::endl;
            } else {
                std::cerr << "Not existing building!" << std::endl;
            }
            break;
        case 6:
            if (LumberMill != nullptr) {
                LumberMill->printInfo();
                std::cout << std::endl;
            } else {
                std::cerr << "Not existing building!" << std::endl;
            }
            break;
        case 7:
            if (WoodStorage != nullptr) {
                WoodStorage->printWoodInfo();
                std::cout << std::endl;
            } else {
                std::cerr << "Not existing building!" << std::endl;
            }
            break;
        case 0:
            return;
        default:
            std::cerr << "Unknown building!" << std::endl;
    }
}