//
// Created by kamil on 28.12.2021.
//
#include "../GameEngine.h"


void GameEngine::upgradeGoldStorage() {
    if (GoldStorage != nullptr && StoneStorage != nullptr && WoodStorage != nullptr && GoldStorage->getBuildLevel() < TownHall->getBuildLevel()) {
        if ((GoldStorage->getStoredGold() + TownHall->getStoredGold()) - (70 * GoldStorage->getBuildLevel()) >= 0 &&
            (StoneStorage->getStoredStone() + TownHall->getStoredStone()) - (90 * GoldStorage->getBuildLevel()) >= 0 &&
            (WoodStorage->getStoredWood() + TownHall->getStoredWood()) - (100 * GoldStorage->getBuildLevel()) >= 0) {
            if (GoldStorage->getStoredGold() - (70 * GoldStorage->getBuildLevel()) >= 0) {
                GoldStorage->m_storedGold = GoldStorage->getStoredGold() - (70 * GoldStorage->getBuildLevel());
            } else {
                TownHall->m_storedGold =
                        (GoldStorage->getStoredGold() + TownHall->getStoredGold()) -
                        (70 * GoldStorage->getBuildLevel());
                GoldStorage->m_storedGold = 0;
            }

            if (StoneStorage->getStoredStone() - (90 * GoldStorage->getBuildLevel()) >= 0) {
                StoneStorage->m_storedStone = StoneStorage->getStoredStone() - (90 * GoldStorage->getBuildLevel());
            } else {
                TownHall->m_storedStone =
                        (StoneStorage->getStoredStone() + TownHall->getStoredStone()) -
                        (90 * GoldStorage->getBuildLevel());
                StoneStorage->m_storedStone = 0;
            }
            if (WoodStorage->getStoredWood() - (100 * GoldStorage->getBuildLevel()) >= 0) {
                WoodStorage->m_storedWood = WoodStorage->getStoredWood() - (100 * GoldStorage->getBuildLevel());
            } else {
                TownHall->m_storedWood = (WoodStorage->getStoredWood() + TownHall->getStoredWood()) -
                                         (100 * GoldStorage->getBuildLevel());
                WoodStorage->m_storedWood = 0;
            }
            GoldStorage->upgradeLevel();
            std::cout << "Building upgraded." << std::endl;
        } else {
            std::cout << "You have not enough resources." << std::endl;
        }
    } else {
        std::cout << "You first have to build all building's to start upgrading buildings." << std::endl;
    }
}