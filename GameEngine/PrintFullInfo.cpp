//
// Created by kamil on 28.12.2021.
//

#include "GameEngine.h"

void GameEngine::printFullInfo() {
    std::cout << "Stored resources: ";
    if (GoldStorage != nullptr) {
        std::cout << TownHall->getStoredGold() + GoldStorage->getStoredGold() << " gold, ";
    } else {
        std::cout << TownHall->getStoredGold() << " gold, ";
    }
    if (StoneStorage != nullptr) {
        std::cout << TownHall->getStoredStone() + StoneStorage->getStoredStone() << " stone, ";
    } else {
        std::cout << TownHall->getStoredStone() << " stone, ";
    }
    if (WoodStorage != nullptr) {
        std::cout << TownHall->getStoredWood() + WoodStorage->getStoredWood() << " wood.";
    } else {
        std::cout << TownHall->getStoredWood() << " wood.";
    }
    std::cout << std::endl;
}
