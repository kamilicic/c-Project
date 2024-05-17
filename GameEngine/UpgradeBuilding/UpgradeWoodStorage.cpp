//
// Created by kamil on 28.12.2021.
//
#include "../GameEngine.h"


void GameEngine::upgradeWoodStorage() {
    if (GoldStorage != nullptr && StoneStorage != nullptr && WoodStorage != nullptr && WoodStorage->getBuildLevel() < TownHall->getBuildLevel()) {
        if ((GoldStorage->getStoredGold() + TownHall->getStoredGold()) - (80 * WoodStorage->getBuildLevel()) >= 0 &&
            (StoneStorage->getStoredStone() + TownHall->getStoredStone()) - (80 * WoodStorage->getBuildLevel()) >= 0 &&
            (WoodStorage->getStoredWood() + TownHall->getStoredWood()) - (80 * WoodStorage->getBuildLevel()) >= 0) {
            if (GoldStorage->getStoredGold() - (80 * WoodStorage->getBuildLevel()) >= 0) {
                GoldStorage->m_storedGold = GoldStorage->getStoredGold() - (80 * WoodStorage->getBuildLevel());
            } else {
                TownHall->m_storedGold = (GoldStorage->getStoredGold() + TownHall->getStoredGold()) - (80 * WoodStorage->getBuildLevel());
                GoldStorage->m_storedGold = 0;
            }
            if (StoneStorage->getStoredStone() - (80 * WoodStorage->getBuildLevel()) >= 0) {
                StoneStorage->m_storedStone = StoneStorage->getStoredStone() - (80 * WoodStorage->getBuildLevel());
            } else {
                TownHall->m_storedStone = (StoneStorage->getStoredStone() + TownHall->getStoredStone()) - (80 * WoodStorage->getBuildLevel());
                StoneStorage->m_storedStone = 0;
            } if (WoodStorage->getStoredWood()- (80 * WoodStorage->getBuildLevel()) >= 0){
                WoodStorage->m_storedWood = WoodStorage->getStoredWood()- (80 * WoodStorage->getBuildLevel());
            } else {
                TownHall->m_storedWood = (WoodStorage->getStoredWood() + TownHall->getStoredWood()) - (80 * WoodStorage->getBuildLevel());
                WoodStorage->m_storedWood = 0;
            }
            WoodStorage->upgradeLevel();
            std::cout << "Building upgraded." << std::endl;
        } else {
            std::cout << "You have not enough resources." << std::endl;
        }
    } else {
        std::cout << "You first have to build all building's to start upgrading buildings." << std::endl;
    }
}