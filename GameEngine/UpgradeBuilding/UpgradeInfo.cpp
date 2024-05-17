//
// Created by kamil on 28.12.2021.
//
#include "../GameEngine.h"


void GameEngine::upgradeInfo() {
    std::cout << "About which building do you want upgrade info?" << std::endl;
    std::cout << "[1] TownHall, [2] GoldMine, [3] GoldStorage, [4] StoneMine, [5] StoneStorage, [6] LumberMill, [7] WoodStorage, [0] Go back." << std::endl;
    int info;
    std::cin >> info;
    switch (info) {
        case 1:
                std::cout << "For upgrade this building you want: " << 250 * TownHall->getBuildLevel() << " gold, "
                          << 250 * TownHall->getBuildLevel() << " stone, " << 250 * TownHall->getBuildLevel() << " wood."
                          << std::endl;
            break;
        case 2:
            if (GoldMine != nullptr) {
                std::cout << "For upgrade this building you want: " << 80 * GoldMine->getBuildLevel() << " gold, "
                          << 90 * GoldMine->getBuildLevel() << " stone, " << 70 * GoldMine->getBuildLevel() << " wood."
                          << std::endl;
            } else {
                std::cerr << "Not existing building!" << std::endl;
            }
            break;
        case 3:
            if (GoldStorage != nullptr) {
                std::cout << "For upgrade this building you want: " << 70 * GoldStorage->getBuildLevel() << " gold, "
                          << 90 * GoldStorage->getBuildLevel() << " stone, " << 100 * GoldStorage->getBuildLevel() << " wood."
                          << std::endl;
            } else {
                std::cerr << "Not existing building!" << std::endl;
            }
            break;
        case 4:
            if (StoneMine != nullptr) {
                std::cout << "For upgrade this building you want: " << 100 * StoneMine->getBuildLevel() << " gold, "
                          << 70 * StoneMine->getBuildLevel() << " stone, " << 90 * StoneMine->getBuildLevel() << " wood."
                          << std::endl;
            } else {
                std::cerr << "Not existing building!" << std::endl;
            }
            break;
        case 5:
            if (StoneStorage != nullptr) {
                std::cout << "For upgrade this building you want: " << 80 * StoneStorage->getBuildLevel() << " gold, "
                          << 90 * StoneStorage->getBuildLevel() << " stone, " << 90 * StoneStorage->getBuildLevel() << " wood."
                          << std::endl;
            } else {
                std::cerr << "Not existing building!" << std::endl;
            }
            break;
        case 6:
            if (LumberMill != nullptr) {
                std::cout << "For upgrade this building you want: " << 110 * LumberMill->getBuildLevel() << " gold, "
                          << 70 * LumberMill->getBuildLevel() << " stone, " << 70 * LumberMill->getBuildLevel() << " wood."
                          << std::endl;
            } else {
                std::cerr << "Not existing building!" << std::endl;
            }
            break;
        case 7:
            if (WoodStorage != nullptr) {
                std::cout << "For upgrade this building you want: " << 80 * WoodStorage->getBuildLevel() << " gold, "
                          << 80 * WoodStorage->getBuildLevel() << " stone, " << 80 * WoodStorage->getBuildLevel() << " wood."
                          << std::endl;
            } else {
                std::cerr << "Not existing building!" << std::endl;
            }
            break;
    }
}